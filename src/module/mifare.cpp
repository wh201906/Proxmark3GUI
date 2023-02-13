#include "mifare.h"
#include <QJsonArray>

const Mifare::CardType Mifare::card_mini =
{
    0,
    5,
    20,
    {4, 4, 4, 4, 4},
    {0, 4, 8, 12, 16},
    "mini"
};
const Mifare::CardType Mifare::card_1k =
{
    1,
    16,
    64,
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60},
    "1k"
};
const Mifare::CardType Mifare::card_2k =
{
    2,
    32,
    128,
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124},
    "2k"
};
const Mifare::CardType Mifare::card_4k =
{
    4,
    40,
    256,
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 16, 16, 16, 16, 16, 16, 16, 16},
    {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 144, 160, 176, 192, 208, 224, 240},
    "4k"
};

const Mifare::AccessType Mifare::dataCondition[8][4] =
{
    // {read, write, increment, decrement/transfer/restore}
    {ACC_KEY_AB, ACC_KEY_AB, ACC_KEY_AB, ACC_KEY_AB}, // {C3x, C2x, C1x} = 0
    {ACC_KEY_AB, ACC_KEY_B, ACC_NEVER, ACC_NEVER}, // {C3x, C2x, C1x} = 1
    {ACC_KEY_AB, ACC_NEVER, ACC_NEVER, ACC_NEVER}, // {C3x, C2x, C1x} = 2
    {ACC_KEY_AB, ACC_KEY_B, ACC_KEY_B, ACC_KEY_AB}, // {C3x, C2x, C1x} = 3
    {ACC_KEY_AB, ACC_NEVER, ACC_NEVER, ACC_KEY_AB}, // {C3x, C2x, C1x} = 4
    {ACC_KEY_B, ACC_NEVER, ACC_NEVER, ACC_NEVER}, // {C3x, C2x, C1x} = 5
    {ACC_KEY_B, ACC_KEY_B, ACC_NEVER, ACC_NEVER}, // {C3x, C2x, C1x} = 6
    {ACC_NEVER, ACC_NEVER, ACC_NEVER, ACC_NEVER}, // {C3x, C2x, C1x} = 7
};
const Mifare::AccessType Mifare::trailerReadCondition[8][3] =
{
    // {KEYA, Access bits, KEYB}
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A}, // {C33, C23, C13} = 0
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER}, // {C33, C23, C13} = 1
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A}, // {C33, C23, C13} = 2
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER}, // {C33, C23, C13} = 3
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A}, // {C33, C23, C13} = 4
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER}, // {C33, C23, C13} = 5
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER}, // {C33, C23, C13} = 6
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER}, // {C33, C23, C13} = 7
};
const Mifare::AccessType Mifare::trailerWriteCondition[8][3] =
{
    // {KEYA, Access bits, KEYB}
    {ACC_KEY_A, ACC_NEVER, ACC_KEY_A}, // {C33, C23, C13} = 0
    {ACC_KEY_B, ACC_NEVER, ACC_KEY_B}, // {C33, C23, C13} = 1
    {ACC_NEVER, ACC_NEVER, ACC_NEVER}, // {C33, C23, C13} = 2
    {ACC_NEVER, ACC_NEVER, ACC_NEVER}, // {C33, C23, C13} = 3
    {ACC_KEY_A, ACC_KEY_A, ACC_KEY_A}, // {C33, C23, C13} = 4
    {ACC_NEVER, ACC_KEY_B, ACC_NEVER}, // {C33, C23, C13} = 5
    {ACC_KEY_B, ACC_KEY_B, ACC_KEY_B}, // {C33, C23, C13} = 6
    {ACC_NEVER, ACC_NEVER, ACC_NEVER}, // {C33, C23, C13} = 7
};

Mifare::Mifare(Ui::MainWindow *ui, Util *addr, QWidget *parent): QObject(parent)
{
    this->parent = parent;
    util = addr;
    this->ui = ui;
    cardType = card_1k;
    keyAList = new QStringList();
    keyBList = new QStringList();
    dataList = new QStringList();
    data_clearKey();  // fill with blank QString
    data_clearData(); // fill with blank QString
    dataPattern = new QRegularExpression("([0-9a-fA-F]{2} ){15}[0-9a-fA-F]{2}");
    keyPattern_res = new QRegularExpression("\\|\\s*\\d{3}\\s*\\|\\s*.+?\\s*\\|\\s*.+?\\s*\\|\\s*.+?\\s*\\|\\s*.+?\\s*\\|");
    keyPattern = new QRegularExpression("\\|\\s*\\d{3}\\s*\\|\\s*.+?\\s*\\|\\s*.+?\\s*\\|");
}

void Mifare::setConfigMap(const QVariantMap& configMap)
{
    this->configMap = configMap;
}

QMap<QString, QString> Mifare::info(bool isRequiringOutput)
{
    QMap<QString, QString> map;
    QVariantMap config = configMap["info"].toMap();
    if(isRequiringOutput)
    {
        QString result = util->execCMDWithOutput(config["cmd"].toString(), 500);
        QStringList lineList = result.split("\n");

        for(auto line = lineList.begin(); line != lineList.end(); line++)
        {
            if(line->contains("UID"))
                map["UID"] = line->replace("UID", "").replace(QRegularExpression("[^0-9a-fA-F]"), "").trimmed();
            else if(line->contains("ATQA"))
                map["ATQA"] = line->replace("ATQA", "").replace(QRegularExpression("[^0-9a-fA-F]"), "").trimmed();
            else if(line->contains("SAK"))
                map["SAK"] = line->replace("SAK", "").replace(QRegularExpression("\\[.+?\\]"), "").replace(QRegularExpression("[^0-9a-fA-F]"), "").trimmed();
        }
    }
    else
    {
        util->execCMD(config["cmd"].toString());
        Util::gotoRawTab();
    }
    return map;
}

void Mifare::chk()
{
    QRegularExpressionMatch reMatch;
    QString result;
    int offset = 0;
    QString data;
    QVariantMap config = configMap["check"].toMap();
    QString cmd = config["cmd"].toString();
    int keyAindex = config["key A index"].toInt();
    int keyBindex = config["key B index"].toInt();
    QRegularExpression keyPattern = QRegularExpression(config["key pattern"].toString(), QRegularExpression::MultilineOption);
    cmd.replace("<card type>", config["card type"].toMap()[cardType.typeText].toString());

    result = util->execCMDWithOutput(
                 cmd,
                 Util::ReturnTrigger(1000 + cardType.sector_size * 200, {"No valid", keyPattern.pattern()}));
    for(int i = 0; i < cardType.sector_size; i++)
    {
        reMatch = keyPattern.match(result, offset);
        offset = reMatch.capturedStart();
        if(reMatch.hasMatch())
        {
            data = reMatch.captured().toUpper();
            offset += data.length();
            QStringList cells = data.remove(" ").split("|");
            if(!cells[keyAindex].contains(QRegularExpression("[^0-9a-fA-F]")))
            {
                keyAList->replace(i, cells[keyAindex]);
            }
            if(!cells[keyBindex].contains(QRegularExpression("[^0-9a-fA-F]")))
            {
                keyBList->replace(i, cells[keyBindex]);
            }
        }
    }

    data_syncWithKeyWidget();
}

void Mifare::nested(bool isStaticNested)
{
    QVariantMap config = configMap["nested"].toMap();
    QString cmd;
    if(isStaticNested)
        cmd = config["static cmd"].toString();
    else
        cmd = config["cmd"].toString();
    int keyAindex = config["key A index"].toInt();
    int keyBindex = config["key B index"].toInt();
    QRegularExpression keyPattern = QRegularExpression(config["key pattern"].toString(), QRegularExpression::MultilineOption);
    QRegularExpressionMatch reMatch;
    QString result;
    int offset = 0;
    QString data;

    cmd.replace("<card type>", config["card type"].toMap()[cardType.typeText].toString());
    if(cmd.contains(QRegularExpression("<.+>"))) // need at least one section key
    {
        QString knownKey, knownKeyType;
        int knownKeySector = -1;
        for(int i = 0; i < cardType.sector_size; i++)
        {
            if(data_isKeyValid(keyAList->at(i)))
            {
                knownKeyType = "A";
                knownKey = keyAList->at(i);
                knownKeySector = i;
                break;
            }
            else if(data_isKeyValid(keyBList->at(i)))
            {
                knownKeyType = "B";
                knownKey = keyBList->at(i);
                knownKeySector = i;
                break;
            }
        }
        if(knownKeySector != -1)
        {
            cmd.replace("<block>", QString::number(cardType.blks[knownKeySector]));
            cmd.replace("<key type>", config["key type"].toMap()[knownKeyType].toString());
            cmd.replace("<key>", knownKey);
        }
        else
        {
            QMessageBox::information(parent, tr("Info"), tr("Plz provide at least one known key"));
            return;
        }

    }
    result = util->execCMDWithOutput(
                 cmd,
                 Util::ReturnTrigger(15000, {"Quit", "Can't found", "Can't authenticate", keyPattern_res->pattern()}),
                 true);

    if(result.contains("static") && !isStaticNested)
    {
        nested(true);
        return;
    }

    for(int i = 0; i < cardType.sector_size; i++)
    {
        reMatch = keyPattern.match(result, offset);
        offset = reMatch.capturedStart();
        if(reMatch.hasMatch())
        {
            data = reMatch.captured().toUpper();
            offset += data.length();
            QStringList cells = data.remove(" ").split("|");
            if(!cells[keyAindex].contains(QRegularExpression("[^0-9a-fA-F]")))
            {
                keyAList->replace(i, cells[keyAindex]);
            }
            if(!cells[keyBindex].contains(QRegularExpression("[^0-9a-fA-F]")))
            {
                keyBList->replace(i, cells[keyBindex]);
            }
        }
    }
    data_syncWithKeyWidget();

}

void Mifare::hardnested()
{
    QVariantMap config = configMap["hardnested"].toMap();
    MF_Attack_hardnestedDialog dialog(cardType.block_size, config);
    connect(&dialog, &MF_Attack_hardnestedDialog::sendCMD, util, &Util::execCMD);
    if(dialog.exec() == QDialog::Accepted)
        Util::gotoRawTab();
}

void Mifare::darkside()
{
    QVariantMap config = configMap["darkside"].toMap();
    util->execCMD(config["cmd"].toString());

    Util::gotoRawTab();
}

void Mifare::sniff()
{
    QVariantMap config = configMap["sniff"].toMap();
    util->execCMD(config["cmd"].toString());

    Util::gotoRawTab();
}

void Mifare::sniff14a()
{
    QVariantMap config = configMap["sniff 14a"].toMap();
    util->execCMD(config["cmd"].toString());

    Util::gotoRawTab();
}

void Mifare::list()
{
    QVariantMap config = configMap["list"].toMap();
    util->execCMD(config["cmd"].toString());

    Util::gotoRawTab();
}

QString Mifare::_readblk(int blockId, KeyType keyType, const QString& key, TargetType targetType, int waitTime)
{
    QString data;
    QString result;
    QRegularExpressionMatch currMatch;
    bool isTrailerBlock = (blockId < 128 && ((blockId + 1) % 4 == 0)) || ((blockId + 1) % 16 == 0);

    if(targetType == TARGET_MIFARE)
    {
        if(!data_isKeyValid(key))
        {
            return "";
        }
        QVariantMap config = configMap["normal read block"].toMap();
        QString cmd = config["cmd"].toString();
        QRegularExpression dataPattern = QRegularExpression(config["data pattern"].toString());
        cmd.replace("<block>", QString::number(blockId));
        cmd.replace("<key type>", config["key type"].toMap()[QString((char)keyType)].toString());
        cmd.replace("<key>", key);
        // use the given key type to read the target block
        result = util->execCMDWithOutput(cmd, waitTime);

        currMatch = dataPattern.match(result);
        if(currMatch.hasMatch())
        {
            data = currMatch.captured().toUpper();
            data.remove(" ");
            // when the target block is a key block and the given key type is KeyA, try to check whether the KeyB is valid(by Access Bits)
            // if the given key type is KeyB, it will never get the KeyA from the key block
            if(isTrailerBlock && keyType == KEY_A) // in this case, the Access Bits is always accessible
            {
                data.replace(0, 12, key);
                QList<quint8> ACBits = data_getACBits(data.mid(12, 8));
                if(ACBits[3] == 2 || ACBits[3] == 3 || ACBits[3] == 5 || ACBits[3] == 6 || ACBits[3] == 7) // in these cases, the KeyB cannot be read by KeyA
                {
                    data.replace(20, 12, "????????????");
                }
            }
            else if(isTrailerBlock && keyType == KEY_B)
            {
                data.replace(20, 12, key);;
                data.replace(0, 12, "????????????"); // fill the keyA part with ?
            }
        }
        else
            data = "";
    }
    else if(targetType == TARGET_UID)
    {
        QVariantMap config = configMap["Magic Card read block"].toMap();
        QString cmd = config["cmd"].toString();
        QRegularExpression dataPattern = QRegularExpression(config["data pattern"].toString());
        cmd.replace("<block>", QString::number(blockId));
        result = util->execCMDWithOutput(cmd, waitTime);
        currMatch = dataPattern.match(result);
        if(currMatch.hasMatch())
        {
            data = currMatch.captured().toUpper();
            data.remove(" ");
        }
        else
            data = "";
    }
    else if(targetType == TARGET_EMULATOR)
    {
        QVariantMap config = configMap["emulator read block"].toMap();
        QString cmd = config["cmd"].toString();
        QRegularExpression dataPattern = QRegularExpression(config["data pattern"].toString());
        cmd.replace("<block>", QString::number(blockId));
        result = util->execCMDWithOutput(cmd, 150);
        data = dataPattern.match(result).captured().toUpper();
        data.remove(" ");
    }

    return data;
}

QStringList Mifare::_readsec(int sectorId, KeyType keyType, const QString& key, TargetType targetType, int waitTime)
{
    QVariantMap config;
    QStringList data;
    QString result, tmp;
    QRegularExpressionMatch reMatch;
    int offset = -1; // for targetType == TARGET_EMULATOR

    for(int i = 0; i < cardType.blk[sectorId]; i++)
    {
        data.append("");
    }

    // try to read all blocks together
    if(targetType == TARGET_MIFARE)
    {
        if(!data_isKeyValid(key))
        {
            return data;
        }
        config = configMap["normal read sector"].toMap();
        QString cmd = config["cmd"].toString();
        cmd.replace("<sector>", QString::number(sectorId));
        cmd.replace("<key type>", config["key type"].toMap()[QString((char)keyType)].toString());
        cmd.replace("<key>", key);
        result = util->execCMDWithOutput(cmd, waitTime);
    }
    else if(targetType == TARGET_UID)
    {
        config = configMap["Magic Card read sector"].toMap();
        QString cmd = config["cmd"].toString();
        cmd.replace("<sector>", QString::number(sectorId));
        result = util->execCMDWithOutput(cmd, waitTime);
    }
    else if(targetType == TARGET_EMULATOR)
    {
        for(int i = 0; i < cardType.blk[sectorId]; i++)
            data[i] = _readblk(cardType.blks[sectorId] + i, keyType, key, targetType, waitTime);
        return data;
    }

    // for TARGET_MIFARE and TARGET_UID
    // if targetType == TARGET_EMULATOR, this function has returned
    QRegularExpression dataPattern = QRegularExpression(config["data pattern"].toString());
    reMatch = dataPattern.match(result);
    offset = reMatch.capturedStart();
    if(reMatch.hasMatch()) // read successful
    {
        for(int i = 0; i < cardType.blk[sectorId]; i++)
        {
            reMatch = dataPattern.match(result, offset);
            offset = reMatch.capturedStart();
            if(reMatch.hasMatch())
            {
                tmp = reMatch.captured().toUpper();
                offset += tmp.length();
                tmp.remove(" ");
                data[i] = tmp;
            }
        }
    }
    // when one of the block cannot be read, the rdsc will return nothing, so you need to read the rest of blocks manually
    // the following rdbl operation is not handled there, for better speed(rdsc_A->rdsc_B->rdbl0~3)
    else if(targetType == TARGET_UID) // treat as MIFARE
        data = _readsec(sectorId, keyType, key, TARGET_MIFARE, waitTime);


    //process trailer(like _readblk())
    QString trailer = data[cardType.blk[sectorId] - 1];
    if(trailer != "" && targetType == TARGET_MIFARE)
    {
        if(keyType == KEY_A) // in this case, the Access Bits is always accessible
        {
            trailer.replace(0, 12, key);
            QList<quint8> ACBits = data_getACBits(trailer.mid(12, 8));
            if(ACBits[3] == 2 || ACBits[3] == 3 || ACBits[3] == 5 || ACBits[3] == 6 || ACBits[3] == 7) // in these cases, the KeyB cannot be read by KeyA
            {
                trailer.replace(20, 12, "????????????");
            }
        }
        else if(keyType == KEY_B)
        {
            trailer.replace(20, 12, key);;
            trailer.replace(0, 12, "????????????"); // fill the keyA part with ?
        }
        data[cardType.blk[sectorId] - 1] = trailer;
    }

    return data;
}

void Mifare::readOne(TargetType targetType)
{
    int blockId = ui->MF_RW_blockBox->currentText().toInt();
    Mifare::KeyType keyType = (Mifare::KeyType)(ui->MF_RW_keyTypeBox->currentData().toInt());
    QString result = _readblk(blockId, keyType, ui->MF_RW_keyEdit->text().toUpper(), targetType);
    if(result != "")
    {
        ui->MF_RW_dataEdit->setText(result);
    }
    else
    {
        ui->MF_RW_dataEdit->setText(tr("Failed!"));
    }
}

void Mifare::readSelected(TargetType targetType)
{
    QString trailerA, trailerB;
    QList<bool> selectedSectors;
    QList<int> selectedBlocks;
    for(int i = 0; i < cardType.block_size; i++)
    {
        if(ui->MF_dataWidget->item(i, 1)->checkState() == Qt::Checked)
            selectedBlocks.append(i);
    }

    for(int i = 0; i < cardType.sector_size; i++)
    {
        selectedSectors.append(false);
    }
    for(int item : selectedBlocks)
    {
        selectedSectors[data_b2s(item)] = true;
    }

    for(int i = 0; i < cardType.sector_size; i++)
    {
        if(!selectedSectors[i])
            continue;

        QStringList data, dataA, dataB;
        for(int j = 0; j < cardType.blk[i]; j++)
        {
            // dataA is always filled with "" because of the _readsec()
            data.append("");
            dataB.append("");
        }

        dataA = _readsec(i, Mifare::KEY_A, keyAList->at(i), targetType);

        // in other situations, the key doesn't matters
        // so the dataA is the final result
        //
        // if the targetType is TARGET_MIFARE and the dataA has unknown part, try to read by keyB
        if(targetType == TARGET_MIFARE && (dataA.contains("") || dataA[cardType.blk[i] - 1].right(12) == "????????????"))
            dataB = _readsec(i, Mifare::KEY_B, keyBList->at(i), targetType);

        // process trailer block seperately
        if(dataA[cardType.blk[i] - 1] == "" && selectedBlocks.contains(getTrailerBlockId(i)))
            dataA[cardType.blk[i] - 1] = _readblk(getTrailerBlockId(i), Mifare::KEY_A, keyAList->at(i), targetType);
        if(dataB[cardType.blk[i] - 1] == "" && dataA[cardType.blk[i] - 1].right(12) == "????????????" && selectedBlocks.contains(getTrailerBlockId(i)))
            dataB[cardType.blk[i] - 1] = _readblk(getTrailerBlockId(i), Mifare::KEY_B, keyBList->at(i), targetType);


        for(int j = 0; j < cardType.blk[i]; j++)
        {
            if(dataA[j] != "")
                data[j] = dataA[j];
            else
                data[j] = dataB[j];

            if(data[j] == "" && selectedBlocks.contains(cardType.blks[i] + j)) // try rdbl seperately
            {
                data[j] = _readblk(cardType.blks[i] + j, Mifare::KEY_A, keyAList->at(i), targetType);
                if(data[j] == "")
                    data[j] = _readblk(cardType.blks[i] + j, Mifare::KEY_B, keyBList->at(i), targetType);
            }
        }

        // process trailer block seperately
        trailerA = dataA[cardType.blk[i] - 1];
        trailerB = dataB[cardType.blk[i] - 1];
        if(trailerA != "" && trailerB != "") // if KeyA and KeyB can both read the trailer, then concat them
        {
            QString ACbits = trailerA.mid(12, 8);
            QString key_A = trailerA.left(12); // KeyA cannot be read by KeyB
            QString key_B = trailerA.at(31) != '?' ? trailerA.right(12) : trailerB.right(12);
            data[cardType.blk[i] - 1] = key_A + ACbits + key_B;
        }

        for(int j = 0; j < cardType.blk[i]; j++)
        {
            if(selectedBlocks.contains(cardType.blks[i] + j))
            {
                dataList->replace(cardType.blks[i] + j, data[j]);
                data_syncWithDataWidget(false, cardType.blks[i] + j);
            }
        }

        if(selectedBlocks.contains(getTrailerBlockId(i)))
        {
            // data widget has been updated, so this is just a temporary varient.
            if(data[cardType.blk[i] - 1] == "")
                data[cardType.blk[i] - 1] = "????????????????????????????????";

            // doesn't replace the existing key.
            if(!data_isKeyValid(keyAList->at(i)))
                keyAList->replace(i, data[cardType.blk[i] - 1].left(12));
            if(!data_isKeyValid(keyBList->at(i)))
                keyBList->replace(i, data[cardType.blk[i] - 1].right(12));
            data_syncWithKeyWidget(false, i, KEY_A);
            data_syncWithKeyWidget(false, i, KEY_B);
        }
    }
}

bool Mifare::_writeblk(int blockId, KeyType keyType, const QString& key, const QString& data, TargetType targetType, int waitTime)
{
    QString result;
    QString input = data.toUpper();

    input.remove(" ");
    if(data_isDataValid(input) != DATA_NOSPACE)
        return false;

    if(targetType == TARGET_MIFARE)
    {
        if(!data_isKeyValid(key))
            return false;
        QVariantMap config = configMap["normal write block"].toMap();
        QString cmd = config["cmd"].toString();
        cmd.replace("<block>", QString::number(blockId));
        cmd.replace("<key type>", config["key type"].toMap()[QString((char)keyType)].toString());
        cmd.replace("<key>", key);
        cmd.replace("<data>", input);
        result = util->execCMDWithOutput(cmd, waitTime);
        if(result.isEmpty())
            return false;

        QVariantList failedFlag = config["failed flag"].toJsonArray().toVariantList();
        for(auto flag = failedFlag.begin(); flag != failedFlag.end(); flag++)
        {
            if(result.contains(flag->toString()))
                return false;
        }
        return true;
    }
    else if(targetType == TARGET_UID)
    {
        QVariantMap config = configMap["Magic Card write block"].toMap();
        QString cmd = config["cmd"].toString();
        cmd.replace("<block>", QString::number(blockId));
        cmd.replace("<data>", input);
        result = util->execCMDWithOutput(cmd, waitTime);
        if(result.isEmpty())
            return false;

        QVariantList failedFlag = config["failed flag"].toJsonArray().toVariantList();
        for(auto flag = failedFlag.begin(); flag != failedFlag.end(); flag++)
        {
            if(result.contains(flag->toString()))
                return false;
        }
        return true;
    }
    else if(targetType == TARGET_EMULATOR)
    {
        QVariantMap config = configMap["emulator write block"].toMap();
        QString cmd = config["cmd"].toString();
        cmd.replace("<block>", QString::number(blockId));
        cmd.replace("<data>", input);
        util->execCMD(cmd);
        util->delay(5);
        return true;
    }

    return false;
}

void Mifare::writeOne(TargetType targetType)
{
    int blockId = ui->MF_RW_blockBox->currentText().toInt();
    Mifare::KeyType keyType = (Mifare::KeyType)(ui->MF_RW_keyTypeBox->currentData().toInt());
    bool isSuccessful = _writeblk(blockId, keyType, ui->MF_RW_keyEdit->text().toUpper(), ui->MF_RW_dataEdit->text(), targetType);
    if(isSuccessful)
    {
        QMessageBox::information(parent, tr("Info"), tr("Succeed!"));
    }
    else
    {
        QMessageBox::information(parent, tr("Info"), tr("Failed!"));
    }
}

void Mifare::writeSelected(TargetType targetType)
{
    QList<int> failedBlocks;
    QList<int> selectedBlocks;
    bool yes2All = false, no2All = false;

    for(int i = 0; i < cardType.block_size; i++)
    {
        if(ui->MF_dataWidget->item(i, 1)->checkState() == Qt::Checked)
            selectedBlocks.append(i);
    }
    for(int item : selectedBlocks)
    {
        bool result = false;
        bool isTrailerBlock = (item < 128 && ((item + 1) % 4 == 0)) || ((item + 1) % 16 == 0);

        if(isTrailerBlock && !data_isACBitsValid(dataList->at(item).mid(12, 8))) // trailer block is invalid
        {
            if(!yes2All && !no2All)
            {
                QMessageBox::StandardButton choice = QMessageBox::information(parent, tr("Info"),
                                                     tr("The Access Bits is invalid!\nIt could make the whole sector blocked irreversibly!\nContinue to write?"),
                                                     QMessageBox::Yes | QMessageBox::YesToAll | QMessageBox::No | QMessageBox::NoToAll);
                if(choice == QMessageBox::No)
                    continue;
                else if(choice == QMessageBox::YesToAll)
                    yes2All = true;
                else if(choice == QMessageBox::NoToAll)
                {
                    no2All = true;
                    continue;
                }
            }
            else if(no2All)
                continue;
        }

        if(targetType == TARGET_MIFARE)
        {
            result = _writeblk(item, KEY_A, keyAList->at(data_b2s(item)), dataList->at(item), TARGET_MIFARE);
            if(!result)
            {
                result = _writeblk(item, KEY_B, keyBList->at(data_b2s(item)), dataList->at(item), TARGET_MIFARE);
            }
            if(!result && keyAList->at(data_b2s(item)) != "FFFFFFFFFFFF")
            {
                result = _writeblk(item, KEY_A, "FFFFFFFFFFFF", dataList->at(item), TARGET_MIFARE);
            }
            if(!result && keyBList->at(data_b2s(item)) != "FFFFFFFFFFFF") // for access bits like "80 f7 87", the block can only be written with keyB
            {
                result = _writeblk(item, KEY_B, "FFFFFFFFFFFF", dataList->at(item), TARGET_MIFARE);
            }
        }
        else // key doesn't matter when writing to Chinese Magic Card and Emulator Memory
        {
            result = _writeblk(item, KEY_A, "FFFFFFFFFFFF", dataList->at(item), targetType);
        }
        if(!result)
        {
            failedBlocks.append(item);
        }
    }
    if(failedBlocks.size() == 0)
        QMessageBox::information(parent, tr("Info"), tr("Succeed!"));
    else
    {
        QString suffix = "";
        int counter = 0;
        for(int failedBlk : failedBlocks)
        {
            suffix += QString::number(failedBlk) + " ";
            counter++;
            counter %= 20;
            if(counter == 0)
                suffix += "\n";
        }
        QMessageBox::StandardButton res = QMessageBox::information(parent, tr("Info"), tr("Failed to write to these blocks:")
                                          + "\n"
                                          + suffix
                                          + "\n"
                                          + tr("Select them?"),
                                          QMessageBox::Yes | QMessageBox::No);
        if(res == QMessageBox::Yes)
        {
            for(int item : selectedBlocks)
            {
                ui->MF_dataWidget->item(item, 1)->setCheckState(Qt::Unchecked);
            }
            for(int failedBlk : failedBlocks)
            {
                ui->MF_dataWidget->item(failedBlk, 1)->setCheckState(Qt::Checked);
            }
        }

    }
}

void Mifare::dump()
{
    QVariantMap config = configMap["dump"].toMap();
    QString cmd = config["cmd"].toString();
    if(cmd.contains("<card type>"))
        cmd.replace("<card type>", config["card type"].toMap()[cardType.typeText].toString());
    util->execCMD(cmd);
    Util::gotoRawTab();
}

void Mifare::restore()
{
    QVariantMap config = configMap["restore"].toMap();
    QString cmd = config["cmd"].toString();
    if(cmd.contains("<card type>"))
        cmd.replace("<card type>", config["card type"].toMap()[cardType.typeText].toString());
    util->execCMD(cmd);
    Util::gotoRawTab();
}

void Mifare::wipeC()
{
    QVariantMap config = configMap["Magic Card wipe"].toMap();
    QString cmd = config["cmd"].toString();
    if(cmd.contains("<card type>"))
        cmd.replace("<card type>", config["card type"].toMap()[cardType.typeText].toString());
    util->execCMD(cmd);
    Util::gotoRawTab();
}

void Mifare::setParameterC()
{
    QVariantMap config = configMap["Magic Card set parameter"].toMap();
    QMap<QString, QString> result = info(true);
    if(result.isEmpty())
    {
        QMessageBox::information(parent, tr("Info"), tr("Failed to read card."));
        return;
    }
    else
    {
        MF_UID_parameterDialog dialog(result["UID"].toUpper(), result["ATQA"].toUpper(), result["SAK"].toUpper(), config);
        connect(&dialog, &MF_UID_parameterDialog::sendCMD, util, &Util::execCMD);
        if(dialog.exec() == QDialog::Accepted)
            Util::gotoRawTab();
    }
}

void Mifare::lockC()
{
    QVariantMap config = configMap["Magic Card lock"].toMap();
    QString cmd = config["cmd"].toString();
    QVariantList list = config["sequence"].toJsonArray().toVariantList();
    for(auto item = list.begin(); item != list.end(); item++)
    {
        qDebug() << cmd + item->toString();
        util->execCMD(cmd + item->toString());
    }
}

void Mifare::wipeE()
{
    QVariantMap config = configMap["emulator wipe"].toMap();
    util->execCMD(config["cmd"].toString());
}

void Mifare::simulate()
{
    MF_Sim_simDialog dialog(cardType.type, cardType.typeText);
    connect(&dialog, &MF_Sim_simDialog::sendCMD, util, &Util::execCMD);
    if(dialog.exec() == QDialog::Accepted)
        Util::gotoRawTab();
}

void Mifare::loadSniff(const QString& file)
{
    QVariantMap config = configMap["load sniff"].toMap();
    QString cmd = config["cmd"].toString();
    cmd.replace("<filename>", file);
    if(config.contains("show cmd"))
    {
        if(util->execCMDWithOutput(cmd, Util::ReturnTrigger({"loaded"})) != "")
            util->execCMD(config["show cmd"].toString());
    }
    else
    {
        util->execCMD(cmd);
    }

    Util::gotoRawTab();
}

void Mifare::saveSniff(const QString& file)
{
    QVariantMap config = configMap["save sniff"].toMap();
    QString cmd = config["cmd"].toString();
    cmd.replace("<filename>", file);
    util->execCMD(cmd);

    Util::gotoRawTab();
}

void Mifare::data_syncWithDataWidget(bool syncAll, int block)
{
    ui->MF_dataWidget->blockSignals(true);
    QString tmp;
    if(syncAll)
    {
        for(int i = 0; i < cardType.block_size; i++)
        {
            tmp = "";
            if(dataList->at(i) != "")
            {
                tmp += dataList->at(i).midRef(0, 2);
                for(int j = 1; j < 16; j++)
                {
                    tmp += " ";
                    tmp += dataList->at(i).midRef(j * 2, 2);
                }
            }
            ui->MF_dataWidget->item(i, 2)->setText(tmp);
        }
    }
    else
    {
        tmp = "";
        if(dataList->at(block) != "")
        {
            tmp += dataList->at(block).midRef(0, 2);
            for(int j = 1; j < 16; j++)
            {
                tmp += " ";
                tmp += dataList->at(block).midRef(j * 2, 2);
            }
        }
        ui->MF_dataWidget->item(block, 2)->setText(tmp);
    }
    ui->MF_dataWidget->blockSignals(false);
}

void Mifare::data_syncWithKeyWidget(bool syncAll, int sector, KeyType keyType)
{
    ui->MF_keyWidget->blockSignals(true);
    if(syncAll)
    {
        for(int i = 0; i < cardType.sector_size; i++)
        {
            ui->MF_keyWidget->item(i, 1)->setText(keyAList->at(i));
            ui->MF_keyWidget->item(i, 2)->setText(keyBList->at(i));
        }
    }
    else
    {
        if(keyType == KEY_A)
            ui->MF_keyWidget->item(sector, 1)->setText(keyAList->at(sector));
        else
            ui->MF_keyWidget->item(sector, 2)->setText(keyBList->at(sector));
    }
    ui->MF_keyWidget->blockSignals(false);
}

void Mifare::data_clearData(bool clearAll)
{
    if(clearAll)
    {
        dataList->clear();
    }

    int delta = cardType.block_size - dataList->length()  ;
    if(delta >= 0)
    {
        for(int i = 0; i < delta; i++)
            dataList->append("");
    }
    else if(delta < 0)
    {
        for(int i = 0; i < -delta; i++)

            dataList->removeLast();
    }
}

void Mifare::data_clearKey(bool clearAll)
{
    if(clearAll)
    {
        keyAList->clear();
        keyBList->clear();
    }

    int delta = cardType.sector_size - keyAList->length()  ;
    if(delta >= 0)
    {
        for(int i = 0; i < delta; i++)
        {
            keyAList->append("");
            keyBList->append("");
        }
    }
    else if(delta < 0)
    {
        for(int i = 0; i < -delta; i++)
        {
            keyAList->removeLast();
            keyBList->removeLast();
        }
    }
}

bool Mifare::data_isKeyValid(const QString& key)
{
    if(key.length() != 12)
        return false;
    for(int i = 0; i < 12; i++)
    {
        if(!((key[i] >= '0' && key[i] <= '9') || (key[i] >= 'A' && key[i] <= 'F')))
            return false;
    }
    return true;
}

Mifare::DataType Mifare::data_isDataValid(const QString& data) // "?" will not been processd there
{
    if(data.length() == 47)
    {
        for(int i = 0; i < 47; i++)
        {
            if(i % 3 != 0)
            {
                if(!((data[i] >= '0' && data[i] <= '9') || (data[i] >= 'A' && data[i] <= 'F') || data[i] == '?'))
                    return DATA_INVALID;
            }
            else
            {
                if(data[i] != ' ')
                    return DATA_INVALID;
            }
        }
        return DATA_WITHSPACE;
    }
    else if(data.length() == 32)
    {
        for(int i = 0; i < 32; i++)
        {
            if(!((data[i] >= '0' && data[i] <= '9') || (data[i] >= 'A' && data[i] <= 'F') || data[i] == '?'))
                return DATA_INVALID;
        }
        return DATA_NOSPACE;
    }
    else
        return DATA_INVALID;
}

Mifare::CardType Mifare::getCardType()
{
    return cardType;
}

void Mifare::setCardType(int type)
{
    if(type == 0 || type == 1 || type == 2 || type == 4)
    {
        if(type == 0)
            cardType = card_mini;
        else if(type == 1)
            cardType = card_1k;
        else if(type == 2)
            cardType = card_2k;
        else if(type == 4)
            cardType = card_4k;
        data_clearKey(false);
        data_clearData(false);
    }
}

bool Mifare::data_loadDataFile(const QString& filename)
{
    QFile file(filename, this);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray buff;
        buff = file.read(10000);
        bool isBin = false;
        for(int i = 0; i < cardType.block_size * 16; i++)  // Detect the file type
        {
            //                qDebug() << (unsigned char)buff[i];
            if(!((buff[i] >= 'A' && buff[i] <= 'F') || (buff[i] >= 'a' && buff[i] <= 'f') || (buff[i] >= '0' && buff[i] <= '9') || buff[i] == '\n' || buff[i] == '\r'))
            {
                isBin = true;
                break;
            }
        }
        if(isBin)
        {
            if(file.size() < cardType.block_size * 16)
                return false;
            for(int i = 0; i < cardType.block_size; i++)
            {
                QString tmp = bin2text(buff, i, 16);
                dataList->replace(i, tmp.toUpper());
            }
        }
        else
        {
            QString tmp = buff.left(cardType.block_size * 34);
            QStringList tmpList = tmp.split("\n");
            for(int i = 0; i < cardType.block_size; i++)
            {
                dataList->replace(i, tmpList[i].toUpper());
                qDebug() << tmpList[i];
            }
        }
        file.close();
        data_syncWithDataWidget();
        return true;
    }
    else
    {
        return false;
    }
}

bool Mifare::data_loadKeyFile(const QString& filename)
{
    QFile file(filename, this);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray buff;
        buff = file.read(10000);
        bool isKey = file.size() <= cardType.sector_size * 14;
        if(isKey)
        {
            for(int i = 0; i < cardType.sector_size; i++)
            {
                QString tmp = bin2text(buff, i, 12);
                keyAList->replace(i, tmp.left(12).toUpper());
                keyBList->replace(i, tmp.right(12).toUpper());
            }
        }
        else
        {
            for(int i = 0; i < cardType.sector_size; i++)
            {
                int blk = getTrailerBlockId(i);
                QString tmp = bin2text(buff, blk, 16);
                keyAList->replace(i, tmp.left(12).toUpper());
                keyBList->replace(i, tmp.right(12).toUpper());
            }
        }
        file.close();
        data_syncWithKeyWidget();
        return true;
    }
    else
    {
        return false;
    }
}

QString Mifare::bin2text(const QByteArray& buff, int i, int length)
{
    QString ret = "";
    char LByte, RByte;
    char map[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
                   };
    for(int j = 0; j < length; j++)
    {
        LByte = map[(unsigned char)buff[i * length + j] >> 4];
        RByte = map[(unsigned char)buff[i * length + j] & 0xF];
        ret += LByte;
        ret += RByte;
    }
    qDebug() << ret;
    return ret;
}

bool Mifare::data_saveDataFile(const QString& filename, bool isBin)
{
    QFile file(filename, this);
    if(file.open(QIODevice::WriteOnly))
    {
        QByteArray buff;
        QChar tmp;
        if(isBin)
        {
            for(int i = 0; i < cardType.block_size; i++)
            {
                for(int j = 0; j < 16; j++)
                {
                    unsigned char Byt[2] = {0x0, 0x0};
                    for(int k = 0; k < 2; k++)
                    {
                        tmp = dataList->at(i).at(j * 2 + k).toUpper();
                        if(tmp >= '0' && tmp <= '9')
                            Byt[k] = tmp.toLatin1() - '0';
                        else if(tmp >= 'A' && tmp <= 'F')
                            Byt[k] = tmp.toLatin1() - 'A' + 10;
                    }
                    buff += (Byt[0] << 4) | Byt[1];
                }
            }
        }
        else
        {
            for(int i = 0; i < cardType.block_size; i++)
            {
                buff += dataList->at(i);
                buff += "\n";
            }
        }
        bool ret = file.write(buff) != -1;
        file.close();
        return ret;
    }
    else
    {
        return false;
    }
}

bool Mifare::data_saveKeyFile(const QString& filename, bool isBin)
{
    QFile file(filename, this);
    if(file.open(QIODevice::WriteOnly))
    {
        QByteArray buff;
        QChar tmp;
        if(isBin)
        {
            for(int i = 0; i < cardType.sector_size; i++)
            {
                for(int j = 0; j < 6; j++)
                {
                    unsigned char Byt[2] = {0x0, 0x0};
                    for(int k = 0; k < 2; k++)
                    {
                        tmp = keyAList->at(i).at(j * 2 + k).toUpper();
                        if(tmp >= '0' && tmp <= '9')
                            Byt[k] = tmp.toLatin1() - '0';
                        else if(tmp >= 'A' && tmp <= 'F')
                            Byt[k] = tmp.toLatin1() - 'A' + 10;
                    }
                    buff += (Byt[0] << 4) | Byt[1];
                }
                for(int j = 0; j < 6; j++)
                {
                    unsigned char Byt[2] = {0x0, 0x0};
                    for(int k = 0; k < 2; k++)
                    {
                        tmp = keyBList->at(i).at(j * 2 + k).toUpper();
                        if(tmp >= '0' && tmp <= '9')
                            Byt[k] = tmp.toLatin1() - '0';
                        else if(tmp >= 'A' && tmp <= 'F')
                            Byt[k] = tmp.toLatin1() - 'A' + 10;
                    }
                    buff += (Byt[0] << 4) | Byt[1];
                }
            }
        }
        else
        {
        }
        bool ret = file.write(buff) != -1;
        file.close();
        return ret;
    }
    else
    {
        return false;
    }
}

void Mifare::data_key2Data()
{
    for(int i = 0; i < cardType.sector_size; i++)
    {
        QString tmp = "";
        if(data_isKeyValid(keyAList->at(i)))
            tmp += keyAList->at(i);
        else
            tmp += "????????????";

        if(dataList->at(getTrailerBlockId(i)) == "")
            tmp += "FF078069"; // default control bytes
        else
            tmp += dataList->at(getTrailerBlockId(i)).midRef(12, 8);

        if(data_isKeyValid(keyBList->at(i)))
            tmp += keyBList->at(i);
        else
            tmp += "????????????";

        dataList->replace(getTrailerBlockId(i), tmp);
        data_syncWithDataWidget();
    }
}

void Mifare::data_data2Key()
{
    for(int i = 0; i < cardType.sector_size; i++)
    {
        if(dataList->at(getTrailerBlockId(i)) == "")
        {
            keyAList->replace(i, "????????????");
            keyBList->replace(i, "????????????");
        }
        else
        {
            keyAList->replace(i, dataList->at(getTrailerBlockId(i)).left(12));
            keyBList->replace(i, dataList->at(getTrailerBlockId(i)).right(12));
        }
        data_syncWithKeyWidget();
    }
}

void Mifare::data_setData(int block, const QString& data)
{
    dataList->replace(block, data);
}

void Mifare::data_setKey(int sector, KeyType keyType, const QString& key)
{
    if(keyType == KEY_A)
        keyAList->replace(sector, key);
    else
        keyBList->replace(sector, key);
}

void Mifare::data_fillKeys()
{
    for(int i = 0; i < cardType.sector_size; i++)
    {
        if(!data_isKeyValid(keyAList->at(i)))
        {
            keyAList->replace(i, "FFFFFFFFFFFF");
        }
        if(!data_isKeyValid(keyBList->at(i)))
        {
            keyBList->replace(i, "FFFFFFFFFFFF");
        }
    }
    data_syncWithKeyWidget();
}

int Mifare::data_b2s(int block)
{
    if(block >= 0 && block < 128)
        return block / 4;
    else if(block < 256)
        return (block - 128) / 16 + 32;
    else
        return -1;
}

bool Mifare::data_isACBitsValid(const QString& text, QList<quint8>* returnHalfBytes)
{
    QString input = text;
    input.remove(" ");
    if(input.length() < 6)
    {
        return false;
    }
    input = input.left(6);
    quint32 val = input.toUInt(nullptr, 16);
    QList<quint8> halfBytes;
    for(int i = 0; i < 6; i++)
    {
        // 6  7  8
        // AB CD EF->
        // {0xA, 0xB, 0xC, 0xD, 0xE, 0xF}
        // {~C2x, ~C1x, C1x, ~C3x, C3, C2}
        halfBytes.append((val >> ((5 - i) * 4)) & 0xf);
    }
    // qDebug() << val;
    if((~halfBytes[0] & 0xf) == halfBytes[5] && (~halfBytes[1] & 0xf) == halfBytes[2] && (~halfBytes[3] & 0xf) == halfBytes[4])
    {
        if(returnHalfBytes != nullptr)
            *returnHalfBytes = halfBytes;
        return true;
    }
    else
        return false;
}

QList<quint8> Mifare::data_getACBits(const QString& text) //return empty QList if the text is invalid
{
    QList<quint8> halfBytes, result;
    if(data_isACBitsValid(text, &halfBytes))
    {
        // data in halfbits:
        // {~C2x, ~C1x, C1x, ~C3x, C3, C2}
        for(int i = 0; i < 4; i++)
        {
            result.append((((halfBytes[4] >> i) & 1) << 2) | (((halfBytes[5] >> i) & 1) << 1) | (((halfBytes[2] >> i) & 1) << 0));
            // {Cx0, Cx1, Cx2, Cx3} (Cx0={C30, C20, C10})
        }
    }
    return result;
}

QString Mifare::data_getUID()
{
    if(data_isDataValid(dataList->at(0)))
        return dataList->at(0).left(8);
    else
        return "";
}

quint16 Mifare::getTrailerBlockId(quint8 sectorId, qint8 cardTypeId)
{
    if(cardTypeId == 0)
        return (card_mini.blks[sectorId] + card_mini.blk[sectorId] - 1);
    else if(cardTypeId == 1)
        return (card_1k.blks[sectorId] + card_1k.blk[sectorId] - 1);
    else if(cardTypeId == 2)
        return (card_2k.blks[sectorId] + card_2k.blk[sectorId] - 1);
    else if(cardTypeId == 4)
        return (card_4k.blks[sectorId] + card_4k.blk[sectorId] - 1);
    else
        // other cardTypeId: use current cardtype(include default -1)
        return (cardType.blks[sectorId] + cardType.blk[sectorId] - 1);
}
