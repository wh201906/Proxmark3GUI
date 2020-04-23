#include "mifare.h"

Mifare::Mifare(Ui::MainWindow *ui, Util *addr, QObject *parent) : QObject(parent)
{
    util = addr;
    this->ui = ui;
    keyAList = new QStringList();
    keyBList = new QStringList();
    dataList = new QStringList();
    data_clearKey(); // fill with blank Qstring
    data_clearData(); // fill with blank Qstring
}



void Mifare::info()
{
    util->execCMD("hf 14a info");
    ui->funcTab->setCurrentIndex(1);
}

void Mifare::chk()
{
    QString result = util->execCMDWithOutput("hf mf chk *1 ?");
    result = result.mid(result.indexOf("|---|----------------|----------------|"));
    QStringList keys = result.split("\r\n");
    for(int i = 0; i < 16; i++)
    {
        keyAList->replace(i, keys[i + 3].mid(7, 12).trimmed().toUpper());
        if(keyAList->at(i) == "?")
            keyAList->replace(i, "");
        keyBList->replace(i, keys[i + 3].mid(24, 12).trimmed().toUpper());
        if(keyBList->at(i) == "?")
            keyBList->replace(i, "");
    }
    data_syncWithKeyWidget();
    qDebug() << "***********\n" << keys << "***********\n";
}

void Mifare::nested()
{
    QString result = util->execCMDWithOutput("hf mf nested 1 *");
    result = result.mid(result.indexOf("|---|----------------|---|----------------|---|"));
    QStringList keys = result.split("\r\n");
    for(int i = 0; i < 16; i++)
    {
        if(keys[i + 3].at(23) == '1')
            keyAList->replace(i, keys[i + 3].mid(7, 12).trimmed().toUpper());
        if(keys[i + 3].at(44) == '1')
            keyBList->replace(i, keys[i + 3].mid(28, 12).trimmed().toUpper());
    }
    data_syncWithKeyWidget();
    qDebug() << "***********\n" << keys << "***********\n";
}

void Mifare::hardnested()
{
    MF_Attack_hardnestedDialog dialog;
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
    QString result = util->execCMDWithOutput("hf mf rdbl "
                     + ui->MF_RW_blockBox->currentText()
                     + " "
                     + ui->MF_RW_keyTypeBox->currentText()
                     + " "
                     + ui->MF_RW_keyEdit->text());
    if(result.indexOf("isOk:01") != -1)
    {
        result = result.mid(result.indexOf("isOk:01") + 13, 47).toUpper();
        if((ui->MF_RW_blockBox->currentText().toInt() + 1) % 4 == 0)
        {
            if(ui->MF_RW_keyTypeBox->currentText() == "A")
            {
                for(int i = 0; i < 6; i++)
                {
                    result = result.replace(i * 3, 2, ui->MF_RW_keyEdit->text().mid(i * 2, 2));
                }
                ui->MF_RW_dataEdit->setText(result);
                QString tmpKey = result.right(18).replace(" ", "");
                result = util->execCMDWithOutput("hf mf rdbl "
                                                 + ui->MF_RW_keyTypeBox->currentText()
                                                 + " B "
                                                 + tmpKey);
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
                    result = result.replace(30 + i * 3, 2, ui->MF_RW_keyEdit->text().mid(i * 2, 2));
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
    const int waitTime = 300;
    for(int i = 0; i < sectors; i++)
    {
        result = "";
        isKeyAValid = false;
        isKeyBValid = false;

        // check keys and read the first block of each sector
        if(data_isKeyValid(keyAList->at(i)))
        {
            result = util->execCMDWithOutput("hf mf rdbl "
                                             + QString::number(4 * i)
                                             + " A "
                                             + keyAList->at(i), waitTime);
            if(result.indexOf("isOk:01") != -1)
            {
                isKeyAValid = true;
                result = result.mid(result.indexOf("isOk:01") + 13, 47).toUpper();
                result.replace(" ", "");
                dataList->replace(4 * i, result);
            }
        }
        if(data_isKeyValid(keyBList->at(i)))
        {
            result = util->execCMDWithOutput("hf mf rdbl "
                                             + QString::number(4 * i)
                                             + " B "
                                             + keyBList->at(i), waitTime);
            if(result.indexOf("isOk:01") != -1)
            {
                isKeyBValid = true;
                result = result.mid(result.indexOf("isOk:01") + 13, 47).toUpper();
                result.replace(" ", "");
                dataList->replace(4 * i, result);
            }
        }
        data_syncWithDataWidget(false, 4 * i);
        // read the rest blocks of a sector
        if(isKeyAValid || isKeyBValid)
        {
            for(int j = 1; j < 4; j++)
            {
                result = util->execCMDWithOutput("hf mf rdbl "
                                                 + QString::number(4 * i + j)
                                                 + " "
                                                 + (isKeyAValid ? "A" : "B")
                                                 + " "
                                                 + (isKeyAValid ? keyAList : keyBList)->at(i), waitTime);
                result = result.mid(result.indexOf("isOk:01") + 13, 47).toUpper();
                result.replace(" ", "");
                dataList->replace(4 * i + j, result);
                data_syncWithDataWidget(false, 4 * i + j);
            }

            // fill the MF_dataWidget with the known valid key
            //
            // check whether the MF_dataWidget contains the valid key,
            // and fill MF_keyWidget(when you only have KeyA but the ReadBlock output contains the KeyB)
            //
            // the structure is not symmetric, since you cannot get KeyA from output
            // this program will only process the provided KeyA(in MF_keyWidget)
            result = dataList->at(4 * i + 3);
            if(isKeyAValid)
            {
                result.replace(0, 12, keyAList->at(i));
            }
            else
            {
                result = result.replace(0, 12, "????????????");
            }
            dataList->replace(4 * i + 3, result);

            if(isKeyBValid)
            {
                result.replace(20, 12, keyBList->at(i));
                dataList->replace(4 * i + 3, result);
                data_syncWithDataWidget(false, 4 * i + 3);
            }
            else // now isKeyAValid == true, the output might contains the KeyB
            {
                QString tmpKey = dataList->at(4 * i + 3).right(12);
                result = util->execCMDWithOutput("hf mf rdbl "
                                                 + QString::number(4 * i + 3)
                                                 + " B "
                                                 + tmpKey, waitTime);
                if(result.indexOf("isOk:01") != -1)
                {
                    keyBList->replace(i, tmpKey);
                    data_syncWithKeyWidget(false, i, false);
                }
                else
                {
                    result = dataList->at(4 * i + 3);
                    result = result.replace(20, 12, "????????????");
                    dataList->replace(4 * i + 3, result);

                }
            }
            data_syncWithDataWidget(false, 4 * i + 3);
        }
    }
}

void Mifare::write()
{
    QString result = util->execCMDWithOutput("hf mf wrbl "
                     + ui->MF_RW_blockBox->currentText()
                     + " "
                     + ui->MF_RW_keyTypeBox->currentText()
                     + " "
                     + ui->MF_RW_keyEdit->text()
                     + " "
                     + ui->MF_RW_dataEdit->text().replace(" ", ""));
    if(result.indexOf("isOk:01") != -1)
    {

    }
}

void Mifare::writeAll()
{
    const int waitTime = 300;
    QString result;
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            result = ""; // if the KeyA is invalid and the result is not empty, the KeyB will not be tested.
            if(data_isDataValid(dataList->at(i * 4 + j)) != DATA_NOSPACE || dataList->at(i * 4 + j).contains('?'))
                continue;
            if(data_isKeyValid(keyAList->at(i)))
            {
                result = util->execCMDWithOutput("hf mf wrbl "
                                                 + QString::number(i * 4 + j)
                                                 + " A "
                                                 + keyAList->at(i)
                                                 + " "
                                                 + dataList->at(i * 4 + j), waitTime);
            }
            qDebug() << i << j << result.indexOf("isOk:01") << data_isKeyValid(keyBList->at(i));
            if(result.indexOf("isOk:01") == -1 && data_isKeyValid(keyBList->at(i)))
            {
                result = util->execCMDWithOutput("hf mf wrbl "
                                                 + QString::number(i * 4 + j)
                                                 + " B "
                                                 + keyBList->at(i)
                                                 + " "
                                                 + dataList->at(i * 4 + j), waitTime);
            }
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

void Mifare::data_syncWithDataWidget(bool syncAll, int block)
{
    QString tmp = "";
    if(syncAll)
    {
        for(int i = 0; i < blocks; i++)
        {
            tmp += dataList->at(i).mid(0, 2);
            for(int j = 1; j < 16; j++)
            {
                tmp += " ";
                tmp += dataList->at(i).mid(j * 2, 2);
            }
            ui->MF_dataWidget->item(i, 2)->setText(tmp);
        }
    }
    else
    {
        tmp += dataList->at(block).mid(0, 2);
        for(int j = 1; j < 16; j++)
        {
            tmp += " ";
            tmp += dataList->at(block).mid(j * 2, 2);
        }
        ui->MF_dataWidget->item(block, 2)->setText(tmp);
    }
}

void Mifare::data_syncWithKeyWidget(bool syncAll, int sector, bool isKeyA)
{
    if(syncAll)
    {
        for(int i = 0; i < sectors; i++)
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
    for(int i = 0; i < blocks; i++)
        dataList->append("");
}

void Mifare::data_clearKey()
{
    keyAList->clear();
    keyBList->clear();
    for(int i = 0; i < sectors; i++)
    {
        keyAList->append("");
        keyBList->append("");
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

Mifare::DataType Mifare::data_isDataValid(QString data) // "?" will not been processd there
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
            return DATA_WITHSPACE;
        }
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
