#include "mifare.h"

const Mifare::CardType Mifare::card_mini =
{
    0,
    5,
    20,
    {4, 4, 4, 4, 4},
    {0, 4, 8, 12, 16}
};
const Mifare::CardType Mifare::card_1k =
{
    1,
    16,
    64,
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60}
};
const Mifare::CardType Mifare::card_2k =
{
    2,
    32,
    128,
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124}
};
const Mifare::CardType Mifare::card_4k =
{
    4,
    40,
    256,
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 16, 16, 16, 16, 16, 16, 16, 16},
    {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 144, 160, 176, 192, 208, 224, 240}
};

const Mifare::AccessType Mifare::dataCondition[8][4] =
{
    {ACC_KEY_AB, ACC_KEY_AB, ACC_KEY_AB, ACC_KEY_AB},
    {ACC_KEY_AB, ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_AB, ACC_KEY_B, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_AB, ACC_KEY_B, ACC_KEY_B, ACC_KEY_AB},
    {ACC_KEY_AB, ACC_NEVER, ACC_NEVER, ACC_KEY_AB},
    {ACC_KEY_B, ACC_KEY_B, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_B, ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER, ACC_NEVER},
};
const Mifare::AccessType Mifare::trailerReadCondition[8][3] =
{
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A},
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_A, ACC_KEY_A},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
    {ACC_NEVER, ACC_KEY_AB, ACC_NEVER},
};
const Mifare::AccessType Mifare::trailerWriteCondition[8][3] =
{
    {ACC_KEY_A, ACC_NEVER, ACC_KEY_A},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_B, ACC_NEVER, ACC_KEY_B},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER},
    {ACC_KEY_A, ACC_KEY_A, ACC_KEY_A},
    {ACC_KEY_B, ACC_KEY_B, ACC_KEY_B},
    {ACC_NEVER, ACC_KEY_B, ACC_NEVER},
    {ACC_NEVER, ACC_NEVER, ACC_NEVER},
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
    keyPattern_res = new QRegularExpression("\\|\\d{3}\\|.+?\\|.+?\\|.+?\\|.+?\\|");
    keyPattern = new QRegularExpression("\\|\\d{3}\\|.+?\\|.+?\\|");
}

QString Mifare::info(bool isRequiringOutput)
{
    if(util->getClientType() == Util::CLIENTTYPE_OFFICIAL || util->getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        if(isRequiringOutput)
        {
            QString result = util->execCMDWithOutput("hf 14a info", 500);
            result.replace("UID :", "|||");
            result.replace("ATQA :", "|||");
            result.replace("SAK :", "|||");
            result.replace("TYPE :", "|||");
            QStringList lis = result.split("|||");
            if(lis.length() > 4)
            {
                qDebug() << lis[1] + lis[2] + lis[3];
                return lis[1] + lis[2] + lis[3];
            }
            else
                return "";
        }
        else
        {
            util->execCMD("hf 14a info");
            ui->funcTab->setCurrentIndex(1);
            return "";
        }
    }
}

void Mifare::chk()
{
    QRegularExpressionMatch reMatch;
    QString result = util->execCMDWithOutput(
                         "hf mf chk *"
                         + QString::number(cardType.type)
                         + " ?",
                         1000 + cardType.type * 1000);
    qDebug() << result;

    int offset = 0;
    QString data;
    if(util->getClientType() == Util::CLIENTTYPE_OFFICIAL)
    {
        for(int i = 0; i < cardType.sector_size; i++)
        {
            reMatch = keyPattern->match(result, offset);
            offset = reMatch.capturedStart();
            if(reMatch.hasMatch())
            {
                data = reMatch.captured().toUpper();
                offset += data.length();
                QStringList cells = data.remove(" ").split("|");
                if(!cells[2].contains("?"))
                {
                    keyAList->replace(i, cells[2]);
                }
                if(!cells[3].contains("?"))
                {
                    keyBList->replace(i, cells[3]);
                }
            }
        }
    }
    else if(util->getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        for(int i = 0; i < cardType.sector_size; i++)
        {
            reMatch = keyPattern_res->match(result, offset);
            offset = reMatch.capturedStart();
            if(reMatch.hasMatch())
            {
                data = reMatch.captured().toUpper();
                offset += data.length();
                QStringList cells = data.remove(" ").split("|");
                if(cells[3] == "1")
                {
                    keyAList->replace(i, cells[2]);
                }
                if(cells[5] == "1")
                {
                    keyBList->replace(i, cells[4]);
                }
            }
        }

    }
    data_syncWithKeyWidget();
}

void Mifare::nested()
{
    QRegularExpressionMatch reMatch;
    QString result;
    int offset = 0;
    QString data;
    if(util->getClientType() == Util::CLIENTTYPE_OFFICIAL)
    {
        result = util->execCMDWithOutput(
                     "hf mf nested "
                     + QString::number(cardType.type)
                     + " *", 10000);
    }
    else if(util->getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        QString knownKeyInfo = "";
        for(int i = 0; i < cardType.sector_size; i++)
        {
            if(data_isKeyValid(keyAList->at(i)))
            {
                knownKeyInfo = " " + QString::number(i * 4) + " A " + keyAList->at(i);
                break;
            }
        }
        if(knownKeyInfo == "")
        {
            for(int i = 0; i < cardType.sector_size; i++)
            {
                if(data_isKeyValid(keyBList->at(i)))
                {
                    knownKeyInfo = " " + QString::number(i * 4) + " B " + keyBList->at(i);
                    break;
                }
            }
        }
        if(knownKeyInfo != "")
        {
            result = util->execCMDWithOutput(
                         "hf mf nested "
                         + QString::number(cardType.type)
                         + knownKeyInfo, 10000);
        }
        else
        {
            QMessageBox::information(parent, tr("Info"), tr("Plz provide at least one known key"));
        }

    }
    for(int i = 0; i < cardType.sector_size; i++)
    {
        reMatch = keyPattern_res->match(result, offset);
        offset = reMatch.capturedStart();
        if(reMatch.hasMatch())
        {
            data = reMatch.captured().toUpper();
            offset += data.length();
            QStringList cells = data.remove(" ").split("|");
            if(cells[3] == "1")
            {
                keyAList->replace(i, cells[2]);
            }
            if(cells[5] == "1")
            {
                keyBList->replace(i, cells[4]);
            }
        }
    }
    data_syncWithKeyWidget();

}

void Mifare::hardnested()
{
    MF_Attack_hardnestedDialog dialog(cardType.block_size);
    connect(&dialog, &MF_Attack_hardnestedDialog::sendCMD, util, &Util::execCMD);
    if(dialog.exec() == QDialog::Accepted)
        ui->funcTab->setCurrentIndex(1);
}

void Mifare::sniff()
{
    util->execCMD("hf mf sniff");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::snoop()
{
    util->execCMD("hf 14a snoop");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::list()
{
    util->execCMD("hf list mf");
    ui->funcTab->setCurrentIndex(1);
}

QString Mifare::_readblk(int blockId, KeyType keyType, const QString& key, int waitTime)
{
    QString data;
    QString result;
    bool isKeyBlock = (blockId < 128 && ((blockId + 1) % 4 == 0)) || ((blockId + 1) % 16 == 0);

    if(!data_isKeyValid(key))
    {
        return "";
    }

    if(util->getClientType() == Util::CLIENTTYPE_OFFICIAL || util->getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        // use the given key type to read the target block
        result = util->execCMDWithOutput(
                     "hf mf rdbl "
                     + QString::number(blockId)
                     + " "
                     + (char)keyType
                     + " "
                     + key,
                     waitTime);
        if(result.indexOf("isOk:01") != -1)
        {
            data = dataPattern->match(result).captured().toUpper();
            data.remove(" ");
            // when the target block is a key block and the given key type is KeyA, try to check whether the KeyB is valid(by Access Bits)
            // if the given key type is KeyB, it will never get the KeyA from the key block
            if(isKeyBlock && keyType == KEY_A) // in this case, the Access Bits is always accessible
            {
                data.replace(0, 12, key);
                QList<quint8> ACBits = data_getACBits(data.mid(12, 8));
                if(ACBits[3] == 2 || ACBits[3] == 3 || ACBits[3] == 5 || ACBits[3] == 6 || ACBits[3] == 7) // in these cases, the KeyB cannot be read by KeyA
                {
                    data.replace(20, 12, "????????????");
                }
            }
            else if(isKeyBlock && keyType == KEY_B)
            {
                data.replace(20, 12, key);;
                data.replace(0, 12, "????????????"); // fill the keyA part with ?
            }
        }
        else
        {
            data = "";
        }
    }
    return data;
}

QStringList Mifare::_readsec(int sectorId, KeyType keyType, const QString& key, int waitTime)
{
    QStringList data;
    QString result, tmp;
    QRegularExpressionMatch reMatch;
    int offset = 0;

    for(int i = 0; i < cardType.blk[sectorId]; i++)
    {
        data.append("");
    }
    if(!data_isKeyValid(key))
    {
        return data;
    }

    if(util->getClientType() == Util::CLIENTTYPE_OFFICIAL || util->getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        // try to read all blocks together
        result = util->execCMDWithOutput(
                     "hf mf rdsc "
                     + QString::number(sectorId)
                     + " "
                     + (char)keyType
                     + " "
                     + key,
                     waitTime);
        offset = result.indexOf("isOk:01");
        if(offset != -1)
        {
            for(int i = 0; i < cardType.blk[sectorId]; i++)
            {
                reMatch = dataPattern->match(result, offset);
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
        // if failed, try to read them seperately.
        // (when one of the block cannot be read, the rdsc will return nothing, so you need to read the rest of blocks manually)
        else
        {
            for(int i = 0; i < cardType.blk[sectorId]; i++)
            {
                data[i] = _readblk(cardType.blks[sectorId] + i, keyType, key, waitTime);
            }
        }

        //process trailer(like _readblk())
        QString trailer = data[cardType.blk[sectorId] - 1];
        if(trailer != "")
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
    }
    return data;
}

void Mifare::readOne()
{
    int blockId = ui->MF_RW_blockBox->currentText().toInt();
    Mifare::KeyType keyType = (Mifare::KeyType)(ui->MF_RW_keyTypeBox->currentData().toInt());
    QString result = _readblk(blockId, keyType, ui->MF_RW_keyEdit->text().toUpper());
    if(result != "")
    {
        ui->MF_RW_dataEdit->setText(result);
    }
    else
    {
        ui->MF_RW_dataEdit->setText(tr("Failed!"));
    }
}

void Mifare::readSelected(const QList<int>& selectedBlocks)
{
    QStringList data, dataA, dataB;
    QString trailerA, trailerB;
    QList<bool> selectedSectors;

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
        {
            continue;
        }
        for(int j = 0; j < cardType.blk[i]; j++)
        {
            // dataA is always filled with "" because of the _readsec()
            data.append("");
            dataB.append("");
        }

        dataA = _readsec(i, Mifare::KEY_A, keyAList->at(i));
        if(dataA.contains("") || dataA[cardType.blk[i] - 1].right(12) == "????????????")
            dataB = _readsec(i, Mifare::KEY_B, keyBList->at(i));

        for(int j = 0; j < cardType.blk[i]; j++)
        {
            if(dataA[j] != "")
                data[j] = dataA[j];
            else
                data[j] = dataB[j];
        }

        // process trailer block seperately
        trailerA = dataA[cardType.blk[i] - 1];
        trailerB = dataB[cardType.blk[i] - 1];
        if(trailerA != "" && trailerB != "")
        {
            QString ACbits = trailerA.mid(12, 8);
            QString key_A = trailerA.left(12);
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

        if(selectedBlocks.contains(cardType.blks[i] + cardType.blk[i] - 1))
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

bool Mifare::_writeblk(int blockId, KeyType keyType, const QString& key, const QString& data, int waitTime)
{
    QString input = data.toUpper();
    input.remove(" ");

    if(!data_isKeyValid(key) || data_isDataValid(input) != DATA_NOSPACE)
        return false;

    if(util->getClientType() == Util::CLIENTTYPE_OFFICIAL || util->getClientType() == Util::CLIENTTYPE_ICEMAN)
    {
        QString result = util->execCMDWithOutput(
                             "hf mf wrbl "
                             + QString::number(blockId)
                             + " "
                             + (char)keyType
                             + " "
                             + key
                             + " "
                             + input,
                             waitTime);
        return (result.indexOf("isOk:01") != -1);
    }
}

void Mifare::writeOne()
{
    int blockId = ui->MF_RW_blockBox->currentText().toInt();
    Mifare::KeyType keyType = (Mifare::KeyType)(ui->MF_RW_keyTypeBox->currentData().toInt());
    bool isSuccessful = _writeblk(blockId, keyType, ui->MF_RW_keyEdit->text().toUpper(), ui->MF_RW_dataEdit->text());
    if(isSuccessful)
    {
        QMessageBox::information(parent, tr("Info"), tr("Success!"));
    }
    else
    {
        QMessageBox::information(parent, tr("Info"), tr("Failed!"));
    }
}

void Mifare::writeSelected(const QList<int>& selectedBlocks)
{
    for(int item : selectedBlocks)
    {
        bool result = false;
        result = _writeblk(item, KEY_A, keyAList->at(data_b2s(item)), dataList->at(item));
        if(!result)
        {
            result = _writeblk(item, KEY_B, keyBList->at(data_b2s(item)), dataList->at(item));
        }
        if(!result)
        {
            result = _writeblk(item, KEY_A, "FFFFFFFFFFFF", dataList->at(item));
        }
    }
}

void Mifare::readC()
{
    int waitTime = 300;
    int currblk = ui->MF_RW_blockBox->currentText().toInt();
    QString result = util->execCMDWithOutput(
                         "hf mf cgetblk "
                         + QString::number(currblk),
                         waitTime);
    if(result.indexOf("No chinese") == -1)
    {
//        result = result.mid(dataPattern->indexIn(result), 47).toUpper();
        ui->MF_RW_dataEdit->setText(result);
    }
}

void Mifare::readAllC()
{
    QString result;
    const int waitTime = 150;

    QString tmp;
    int offset = 0;
    for(int i = 0; i < cardType.sector_size; i++)
    {
        result = util->execCMDWithOutput(
                     "hf mf cgetsc "
                     + QString::number(i),
                     waitTime);
        qDebug() << result;
        if(result.indexOf("No chinese") == -1)
        {
            offset = 0;
            for(int j = 0; j < cardType.blk[i]; j++)
            {
//                offset = dataPattern->indexIn(result, offset);
//                offset = result.indexOf(*dataPattern, offset);
                tmp = result.mid(offset, 47).toUpper();
                offset += 47;
                qDebug() << tmp;
                tmp.replace(" ", "");
                dataList->replace(cardType.blks[i] + j, tmp);
                data_syncWithDataWidget(false, cardType.blks[i] + j);
            }
            keyAList->replace(i, dataList->at(cardType.blks[i] + cardType.blk[i] - 1).left(12));
            keyBList->replace(i, dataList->at(cardType.blks[i] + cardType.blk[i] - 1).right(12));
            data_syncWithKeyWidget(false, i, KEY_A);
            data_syncWithKeyWidget(false, i, KEY_B);
        }
    }
}

void Mifare::writeC()
{
    int waitTime = 150;
    QString result = util->execCMDWithOutput(
                         "hf mf csetblk "
                         + ui->MF_RW_blockBox->currentText()
                         + " "
                         + ui->MF_RW_dataEdit->text().replace(" ", ""),
                         waitTime);
    if(result.indexOf("No chinese") == -1)
    {
        QMessageBox::information(parent, tr("Info"), tr("Success!"));
    }
    else
    {
        QMessageBox::information(parent, tr("Info"), tr("Failed!"));
    }
}

void Mifare::writeAllC()
{
    const int waitTime = 150;
    QString result;
    for(int i = 0; i < cardType.sector_size; i++)
    {
        for(int j = 0; j < cardType.blk[i]; j++)
        {
            result = "";
            if(data_isDataValid(dataList->at(cardType.blks[i] + j)) != DATA_NOSPACE || dataList->at(cardType.blks[i] + j).contains('?'))
                continue;
            result = util->execCMDWithOutput(
                         "hf mf csetblk "
                         + QString::number(cardType.blks[i] + j)
                         + " "
                         + dataList->at(cardType.blks[i] + j),
                         waitTime);
        }
    }
}

void Mifare::dump()
{
    util->execCMD("hf mf dump");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::restore()
{
    util->execCMD("hf mf restore");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::wipeC()
{
    util->execCMD(
        "hf mf cwipe "
        + QString::number(cardType.type)
        + " f");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::setParameterC()
{
    QString result = info(true);
    if(result == "")
        QMessageBox::information(parent, tr("Info"), tr("Failed to read card."));
    else
    {
        QStringList lis = result.split("\r\n");
        lis[0].replace(" ", "");
        lis[1].replace(" ", "");
        lis[2].replace(" ", "");
        MF_UID_parameterDialog dialog(lis[0].toUpper(), lis[1].toUpper(), lis[2].mid(0, 2).toUpper());
        connect(&dialog, &MF_UID_parameterDialog::sendCMD, util, &Util::execCMD);
        if(dialog.exec() == QDialog::Accepted)
            ui->funcTab->setCurrentIndex(1);
    }
}

void Mifare::lockC()
{
    util->execCMD("hf 14a raw -pa -b7 40");
    util->execCMD("hf 14a raw -pa 43");
    util->execCMD("hf 14a raw -pa E0 00 39 F7");
    util->execCMD("hf 14a raw -pa E1 00 E1 EE");
    util->execCMD("hf 14a raw -pa 85  00  00  00  00  00  00  00  00  00  00  00  00  00  00  08  18  47");
    util->execCMD("hf 14a raw 52");
}

void Mifare::writeAllE()
{
    const int waitTime = 200;
    QString result;
    for(int i = 0; i < cardType.sector_size; i++)
    {
        for(int j = 0; j < cardType.blk[i]; j++)
        {
            result = "";
            if(data_isDataValid(dataList->at(cardType.blks[i] + j)) != DATA_NOSPACE || dataList->at(cardType.blks[i] + j).contains('?'))
                continue;
            result = util->execCMDWithOutput(
                         "hf mf eset "
                         + QString::number(cardType.blks[i] + j)
                         + " "
                         + dataList->at(cardType.blks[i] + j),
                         waitTime);
        }
    }
    util->execCMDWithOutput("hf mf eget", waitTime); // to refresh output buffer;
}

void Mifare::readAllE()
{
    QString result;
    const int waitTime = 200;

    QString tmp;
    int offset = 0;
    for(int i = 0; i < cardType.sector_size; i++)
    {
        offset = 0;
        for(int j = 0; j < cardType.blk[i]; j++)
        {

            qDebug() << "**********" ;
            result = util->execCMDWithOutput(
                         "hf mf eget "
                         + QString::number(cardType.blks[i] + j),
                         waitTime);
            qDebug() << result ;

//            offset = dataPattern->indexIn(result);
//          offset = result.indexOf(*dataPattern, offset); // When I find the data position in this way, the Regex might fail to match.

            tmp = result.mid(offset, 47).toUpper();
            qDebug() << tmp << offset;
            qDebug() << "**********" ;

            if(offset == -1)
                continue;
            tmp.replace(" ", "");
            dataList->replace(cardType.blks[i] + j, tmp);
            data_syncWithDataWidget(false, cardType.blks[i] + j);
        }
        keyAList->replace(i, dataList->at(cardType.blks[i] + cardType.blk[i] - 1).left(12));
        keyBList->replace(i, dataList->at(cardType.blks[i] + cardType.blk[i] - 1).right(12));
        data_syncWithKeyWidget(false, i, KEY_A);
        data_syncWithKeyWidget(false, i, KEY_B);

    }
}

void Mifare::wipeE()
{
    util->execCMD("hf mf eclr");
}

void Mifare::simulate()
{
    MF_Sim_simDialog dialog(cardType.type);
    connect(&dialog, &MF_Sim_simDialog::sendCMD, util, &Util::execCMD);
    if(dialog.exec() == QDialog::Accepted)
        ui->funcTab->setCurrentIndex(1);
}

void Mifare::loadSniff(const QString& file)
{
    util->execCMD("hf list mf -l " + file);
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::saveSniff(const QString& file)
{
    util->execCMD("hf list mf -s " + file);
    ui->funcTab->setCurrentIndex(1);
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
                tmp += dataList->at(i).mid(0, 2);
                for(int j = 1; j < 16; j++)
                {
                    tmp += " ";
                    tmp += dataList->at(i).mid(j * 2, 2);
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
            tmp += dataList->at(block).mid(0, 2);
            for(int j = 1; j < 16; j++)
            {
                tmp += " ";
                tmp += dataList->at(block).mid(j * 2, 2);
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

bool Mifare::data_isKeyValid(const QString &key)
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

bool Mifare::data_loadDataFile(const QString &filename)
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
            QStringList tmpList = tmp.split("\r\n");
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

bool Mifare::data_loadKeyFile(const QString &filename)
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
                int blk = cardType.blks[i] + cardType.blk[i] - 1;
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

QString Mifare::bin2text(const QByteArray &buff, int i, int length)
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

bool Mifare::data_saveDataFile(const QString &filename, bool isBin)
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
                buff += "\r\n";
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

bool Mifare::data_saveKeyFile(const QString &filename, bool isBin)
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

        if(dataList->at(cardType.blks[i] + cardType.blk[i] - 1) == "")
            tmp += "FF078069"; // default control bytes
        else
            tmp += dataList->at(cardType.blks[i] + cardType.blk[i] - 1).mid(12, 8);

        if(data_isKeyValid(keyBList->at(i)))
            tmp += keyBList->at(i);
        else
            tmp += "????????????";

        dataList->replace(cardType.blks[i] + cardType.blk[i] - 1, tmp);
        data_syncWithDataWidget();
    }
}

void Mifare::data_data2Key()
{
    for(int i = 0; i < cardType.sector_size; i++)
    {
        if(dataList->at(cardType.blks[i] + cardType.blk[i] - 1) == "")
        {
            keyAList->replace(i, "????????????");
            keyBList->replace(i, "????????????");
        }
        else
        {
            keyAList->replace(i, dataList->at(cardType.blks[i] + cardType.blk[i] - 1).left(12));
            keyBList->replace(i, dataList->at(cardType.blks[i] + cardType.blk[i] - 1).right(12));
        }
        data_syncWithKeyWidget();
    }
}

void Mifare::data_setData(int block, const QString &data)
{
    dataList->replace(block, data);
}

void Mifare::data_setKey(int sector, KeyType keyType, const QString &key)
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

QList<quint8> Mifare::data_getACBits(const QString& text) //return empty QList if the text is invalid
{
    QString input = text;
    QList<quint8> result;
    input.remove(" ");
    if(input.length() < 6)
    {
        return result;
    }
    input = input.left(6);
    quint32 val = input.toUInt(nullptr, 16);
    quint8 halfBytes[6];
    for(int i = 0; i < 6; i++)
    {
        halfBytes[i] = (val >> ((5 - i) * 4)) & 0xf;
    }
    qDebug() << val;
    if((~halfBytes[0] & 0xf) == halfBytes[5] && (~halfBytes[1] & 0xf) == halfBytes[2] && (~halfBytes[3] & 0xf) == halfBytes[4])
    {
        for(int i = 0; i < 4; i++)
        {
            result.append((((halfBytes[4] >> i) & 1) << 2) | (((halfBytes[5] >> i) & 1) << 1) | (((halfBytes[2] >> i) & 1) << 0));
        }
    }
    return result;
}

