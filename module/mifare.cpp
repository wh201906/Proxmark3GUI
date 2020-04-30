#include "mifare.h"

Mifare::Mifare(Ui::MainWindow *ui, Util *addr, QWidget *parent): QObject(parent)
{
    this->parent = parent;
    util = addr;
    this->ui = ui;
    cardType = card_1k;
    keyAList = new QStringList();
    keyBList = new QStringList();
    dataList = new QStringList();
    data_clearKey();  // fill with blank Qstring
    data_clearData(); // fill with blank Qstring
    dataPattern = new QRegExp("([0-9a-fA-F]{2} ){15}[0-9a-fA-F]{2}");
    chkKeyPattern = new QRegExp("\\|\\d{3}\\|.+\\|.+\\|");
    nestedKeyPattern = new QRegExp("\\|\\d{3}\\|.+\\|.+\\|.+\\|.+\\|");
}

QString Mifare::info(bool isRequiringOutput)
{
    if(isRequiringOutput)
    {
        QString result = util->execCMDWithOutput("hf 14a info", 500);
        qDebug() << result << result.indexOf(QRegExp(ui->MF_RW_dataEdit->text()), 0);
        result.replace("UID :", "|");
        result.replace("ATQA :", "|");
        result.replace("SAK :", "|");
        result.replace("TYPE :", "|");
        QStringList lis = result.split("|");
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

void Mifare::chk()
{
    QString result = util->execCMDWithOutput(
                         "hf mf chk *"
                         + QString::number(cardType.type)
                         + " ?",
                         1000 + cardType.type * 1000);
    qDebug() << result;

    int offset = 0;
    QString tmp, tmp2;
    for(int i = 0; i < cardType.sectors; i++)
    {
        offset = chkKeyPattern->indexIn(result, offset);
//        offset = result.indexOf(*chkKeyPattern, offset);
        tmp = result.mid(offset, 39).toUpper();
        offset += 39;
        qDebug() << tmp << offset;
        tmp2 = tmp.mid(7, 12).trimmed();
        if(tmp2 != "?")
            keyAList->replace(i, tmp2);
        tmp2 = tmp.mid(24, 12).trimmed();
        if(tmp2 != "?")
            keyBList->replace(i, tmp2);
    }
    data_syncWithKeyWidget();
}

void Mifare::nested()
{
    QString result = util->execCMDWithOutput(
                         "hf mf nested "
                         + QString::number(cardType.type)
                         + " *");

    int offset = 0;
    QString tmp;
    for(int i = 0; i < cardType.sectors; i++)
    {
        offset = nestedKeyPattern->indexIn(result, offset);
//        offset = result.indexOf(*nestedKeyPattern, offset);
        tmp = result.mid(offset, 47).toUpper();
        offset += 47;
        if(tmp.at(23) == '1')
            keyAList->replace(i, tmp.mid(7, 12).trimmed());
        if(tmp.at(44) == '1')
            keyBList->replace(i, tmp.mid(28, 12).trimmed());
    }
    data_syncWithKeyWidget();
}

void Mifare::hardnested()
{
    MF_Attack_hardnestedDialog dialog(cardType.blocks);
    connect(&dialog, &MF_Attack_hardnestedDialog::sendCMD, util, &Util::execCMD);
    if(dialog.exec() == QDialog::Accepted)
        ui->funcTab->setCurrentIndex(1);
}

void Mifare::sniff()
{
    util->execCMD("hf mf sniff");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::list()
{
    util->execCMD("hf list mf");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::read()
{
    int waitTime = 300;
    int currblk = ui->MF_RW_blockBox->currentText().toInt();
    QString result = util->execCMDWithOutput(
                         "hf mf rdbl "
                         + QString::number(currblk)
                         + " "
                         + ui->MF_RW_keyTypeBox->currentText()
                         + " "
                         + ui->MF_RW_keyEdit->text(),
                         waitTime);
    if(result.indexOf("isOk:01") != -1)
    {
        result = result.mid(dataPattern->indexIn(result), 47).toUpper();
        if((currblk < 128 && ((currblk + 1) % 4 == 0)) || ((currblk + 1) % 8 == 0)) // process key block
        {
            if(ui->MF_RW_keyTypeBox->currentText() == "A")
            {
                for(int i = 0; i < 6; i++)
                {
                    result = result.replace(i * 3, 2, ui->MF_RW_keyEdit->text().mid(i * 2, 2));
                }
                ui->MF_RW_dataEdit->setText(result);
                QString tmpKey = result.right(18).replace(" ", "");
                result = util->execCMDWithOutput(
                             "hf mf rdbl "
                             + ui->MF_RW_keyTypeBox->currentText()
                             + " B "
                             + tmpKey,
                             waitTime);
                if(result.indexOf("isOk:01") == -1)
                {
                    result = ui->MF_RW_dataEdit->text();
                    result = result.replace(30, 17, "?? ?? ?? ?? ?? ??");
                    ui->MF_RW_dataEdit->setText(result);
                }
            }
            else
            {
                for(int i = 0; i < 6; i++)
                {
                    result = result.replace(
                                 30 + i * 3,
                                 2,
                                 ui->MF_RW_keyEdit->text().mid(i * 2, 2));
                }
                result = result.replace(0, 18, "?? ?? ?? ?? ?? ?? ");
                ui->MF_RW_dataEdit->setText(result);
            }
        }
        else
        {
            ui->MF_RW_dataEdit->setText(result);
        }
    }
}

void Mifare::readAll()
{
    QString result;
    bool isKeyAValid;
    bool isKeyBValid;
    const int waitTime = 150;

    QString tmp;
    int offset = 0;
    for(int i = 0; i < cardType.sectors; i++)
    {
        result = "";
        isKeyAValid = false;
        isKeyBValid = false;

        // check keys and read the first block of each sector
        if(data_isKeyValid(keyAList->at(i)))
        {
            result = util->execCMDWithOutput(
                         "hf mf rdsc "
                         + QString::number(i)
                         + " A "
                         + keyAList->at(i),
                         waitTime);
            qDebug() << result;
            offset = result.indexOf("isOk:01");
            if(offset != -1)
            {
                isKeyAValid = true;
                for(int j = 0; j < cardType.blk[i]; j++)
                {
                    offset = dataPattern->indexIn(result, offset);
//                    offset = result.indexOf(*dataPattern, offset);
                    tmp = result.mid(offset, 47).toUpper();
                    offset += 47;
                    qDebug() << tmp;
                    tmp.replace(" ", "");
                    dataList->replace(cardType.blks[i] + j, tmp);
                    data_syncWithDataWidget(false, cardType.blks[i] + j);
                }
            }
        }
        if(data_isKeyValid(keyBList->at(i)))
        {
            result = util->execCMDWithOutput(
                         "hf mf rdsc "
                         + QString::number(i)
                         + " B "
                         + keyBList->at(i),
                         waitTime);
            qDebug() << result;
            offset = result.indexOf("isOk:01");
            if(offset != -1)
            {
                isKeyBValid = true;
                for(int j = 0; j < cardType.blk[i]; j++)
                {
                    offset = dataPattern->indexIn(result, offset);
//                    offset = result.indexOf(*dataPattern, offset);
                    tmp = result.mid(offset, 47).toUpper();
                    offset += 47;
                    qDebug() << tmp;
                    tmp.replace(" ", "");
                    dataList->replace(cardType.blks[i] + j, tmp);
                    data_syncWithDataWidget(false, cardType.blks[i] + j);
                }
            }
        }

        if(isKeyAValid || isKeyBValid)
        {

            // fill the MF_dataWidget with the known valid key
            //
            // check whether the MF_dataWidget contains the valid key,
            // and fill MF_keyWidget(when you only have KeyA but the ReadBlock output
            // contains the KeyB)
            //
            // the structure is not symmetric, since you cannot get KeyA from output
            // this program will only process the provided KeyA(in MF_keyWidget)
            result = dataList->at(cardType.blks[i] + cardType.blk[i] - 1);
            if(isKeyAValid)
            {
                result.replace(0, 12, keyAList->at(i));
            }
            else
            {
                result = result.replace(0, 12, "????????????");
            }
            dataList->replace(cardType.blks[i] + cardType.blk[i] - 1, result);

            if(isKeyBValid)
            {
                result.replace(20, 12, keyBList->at(i));
                dataList->replace(cardType.blks[i] + cardType.blk[i] - 1, result);
                data_syncWithDataWidget(false, cardType.blks[i] + cardType.blk[i] - 1);
            }
            else   // now isKeyAValid == true, the output might contains the KeyB
            {
                QString tmpKey =
                    dataList->at(cardType.blks[i] + cardType.blk[i] - 1).right(12);
                result = util->execCMDWithOutput(
                             "hf mf rdbl "
                             + QString::number(cardType.blks[i] + cardType.blk[i] - 1)
                             + " B "
                             + tmpKey,
                             waitTime);
                if(result.indexOf("isOk:01") != -1)
                {
                    keyBList->replace(i, tmpKey);
                    data_syncWithKeyWidget(false, i, false);
                }
                else
                {
                    result = dataList->at(cardType.blks[i] + cardType.blk[i] - 1);
                    result = result.replace(20, 12, "????????????");
                    dataList->replace(cardType.blks[i] + cardType.blk[i] - 1, result);
                }
            }
            data_syncWithDataWidget(false, cardType.blks[i] + cardType.blk[i] - 1);
        }
    }
}

void Mifare::write()
{
    int waitTime = 300;
    QString result = util->execCMDWithOutput(
                         "hf mf wrbl " + ui->MF_RW_blockBox->currentText() + " " +
                         ui->MF_RW_keyTypeBox->currentText() + " " +
                         ui->MF_RW_keyEdit->text() + " " +
                         ui->MF_RW_dataEdit->text().replace(" ", ""),
                         waitTime);
    if(result.indexOf("isOk:01") != -1)
    {
        QMessageBox::information(parent, tr("Info"), tr("Success!"));
    }
    else
    {
        QMessageBox::information(parent, tr("Info"), tr("Failed!"));
    }
}

void Mifare::writeAll()
{
    const int waitTime = 300;
    QString result;
    for(int i = 0; i < cardType.sectors; i++)
    {
        for(int j = 0; j < cardType.blk[i]; j++)
        {
            result = ""; // if the KeyA is invalid and the result is not empty, the
            // KeyB will not be tested.
            if(data_isDataValid(dataList->at(cardType.blks[i] + j)) != DATA_NOSPACE || dataList->at(cardType.blks[i] + j).contains('?'))
                continue;
            if(data_isKeyValid(keyAList->at(i)))
            {
                result = util->execCMDWithOutput(
                             "hf mf wrbl " +
                             QString::number(cardType.blks[i] + j)
                             + " A "
                             + keyAList->at(i)
                             + " "
                             + dataList->at(cardType.blks[i] + j),
                             waitTime);
            }
            qDebug() << i << j << result.indexOf("isOk:01") << data_isKeyValid(keyBList->at(i));
            if(result.indexOf("isOk:01") == -1 && data_isKeyValid(keyBList->at(i)))
            {
                result = util->execCMDWithOutput(
                             "hf mf wrbl "
                             + QString::number(cardType.blks[i] + j)
                             + " B "
                             + keyBList->at(i)
                             + " "
                             + dataList->at(cardType.blks[i] + j),
                             waitTime);
            }
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
        result = result.mid(dataPattern->indexIn(result), 47).toUpper();
        ui->MF_RW_dataEdit->setText(result);
    }
}

void Mifare::readAllC()
{
    QString result;
    const int waitTime = 150;

    QString tmp;
    int offset = 0;
    for(int i = 0; i < cardType.sectors; i++)
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
                offset = dataPattern->indexIn(result, offset);
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
            data_syncWithKeyWidget(false, i, true);
            data_syncWithKeyWidget(false, i, false);
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
    for(int i = 0; i < cardType.sectors; i++)
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
    for(int i = 0; i < cardType.sectors; i++)
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
    for(int i = 0; i < cardType.sectors; i++)
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

            offset = dataPattern->indexIn(result);
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
        data_syncWithKeyWidget(false, i, true);
        data_syncWithKeyWidget(false, i, false);

    }
}

void Mifare::wipeE()
{
    util->execCMD("hf mf eclr");
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

void Mifare::data_syncWithDataWidget(bool syncAll, int block)
{
    QString tmp;
    if(syncAll)
    {
        for(int i = 0; i < cardType.blocks; i++)
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
}

void Mifare::data_syncWithKeyWidget(bool syncAll, int sector, bool isKeyA)
{
    if(syncAll)
    {
        for(int i = 0; i < cardType.sectors; i++)
        {
            ui->MF_keyWidget->item(i, 1)->setText(keyAList->at(i));
            ui->MF_keyWidget->item(i, 2)->setText(keyBList->at(i));
        }
    }
    else
    {
        if(isKeyA)
            ui->MF_keyWidget->item(sector, 1)->setText(keyAList->at(sector));
        else
            ui->MF_keyWidget->item(sector, 2)->setText(keyBList->at(sector));
    }
}

void Mifare::data_clearData()
{
    dataList->clear();
    for(int i = 0; i < cardType.blocks; i++)
        dataList->append("");
}

void Mifare::data_clearKey()
{
    keyAList->clear();
    keyBList->clear();
    for(int i = 0; i < cardType.sectors; i++)
    {
        keyAList->append("");
        keyBList->append("");
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

Mifare::DataType
Mifare::data_isDataValid(QString data) // "?" will not been processd there
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
        data_clearKey();
        data_clearData();
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
        for(int i = 0; i < cardType.blocks * 16; i++)  // Detect the file type
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
            if(file.size() < cardType.blocks * 16)
                return false;
            for(int i = 0; i < cardType.blocks; i++)
            {
                QString tmp = bin2text(buff, i, 16);
                dataList->replace(i, tmp.toUpper());
            }
        }
        else
        {
            QString tmp = buff.left(cardType.blocks * 34);
            QStringList tmpList = tmp.split("\r\n");
            for(int i = 0; i < cardType.blocks; i++)
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
        bool isKey = file.size() <= cardType.sectors * 14;
        if(isKey)
        {
            for(int i = 0; i < cardType.sectors; i++)
            {
                QString tmp = bin2text(buff, i, 12);
                keyAList->replace(i, tmp.left(12).toUpper());
                keyBList->replace(i, tmp.right(12).toUpper());
            }
        }
        else
        {
            for(int i = 0; i < cardType.sectors; i++)
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
            for(int i = 0; i < cardType.blocks; i++)
            {
                for(int j = 0; j < 16; j++)
                {
                    unsigned char Byt[2];
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
            for(int i = 0; i < cardType.blocks; i++)
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
            for(int i = 0; i < cardType.sectors; i++)
            {
                for(int j = 0; j < 6; j++)
                {
                    unsigned char Byt[2];
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
                    unsigned char Byt[2];
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
    for(int i = 0; i < cardType.sectors; i++)
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
    for(int i = 0; i < cardType.sectors; i++)
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

void Mifare::data_setKey(int sector, bool isKeyA, const QString &key)
{
    if(isKeyA)
        keyAList->replace(sector, key);
    else
        keyBList->replace(sector, key);
}
