#include "mifare.h"

Mifare::Mifare(Ui::MainWindow *ui, Util *addr, QObject *parent) : QObject(parent)
{
    util = addr;
    this->ui = ui;
}


bool Mifare::isKeyValid(const QString key)
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
        ui->MF_keyWidget->setItem(i, 1, new QTableWidgetItem(keys[i + 3].mid(7, 12).trimmed().toUpper()));
        ui->MF_keyWidget->setItem(i, 2, new QTableWidgetItem(keys[i + 3].mid(24, 12).trimmed().toUpper()));
    }
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
            ui->MF_keyWidget->setItem(i, 1, new QTableWidgetItem(keys[i + 3].mid(7, 12).trimmed().toUpper()));
        if(keys[i + 3].at(44) == '1')
            ui->MF_keyWidget->setItem(i, 2, new QTableWidgetItem(keys[i + 3].mid(28, 12).trimmed().toUpper()));
    }
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
    for(int i = 0; i < 16; i++)
    {
        QApplication::processEvents();
        result = "";
        isKeyAValid = false;
        isKeyBValid = false;

        // check keys and read the first block of each sector
        if(ui->MF_keyWidget->item(i, 1) != nullptr && isKeyValid(ui->MF_keyWidget->item(i, 1)->text()))
        {
            result = util->execCMDWithOutput("hf mf rdbl "
                                             + QString::number(4 * i)
                                             + " A "
                                             + ui->MF_keyWidget->item(i, 1)->text(), waitTime);
            if(result.indexOf("isOk:01") != -1)
            {
                isKeyAValid = true;
                ui->MF_dataWidget->setItem(4 * i, 2, new QTableWidgetItem(result.mid(result.indexOf("isOk:01") + 13, 47).toUpper()));
            }
        }
        QApplication::processEvents();
        if(ui->MF_keyWidget->item(i, 2) != nullptr && isKeyValid(ui->MF_keyWidget->item(i, 2)->text()))
        {
            result = util->execCMDWithOutput("hf mf rdbl "
                                             + QString::number(4 * i)
                                             + " B "
                                             + ui->MF_keyWidget->item(i, 2)->text(), waitTime);
            if(result.indexOf("isOk:01") != -1)
            {
                isKeyBValid = true;
                ui->MF_dataWidget->setItem(4 * i, 2, new QTableWidgetItem(result.mid(result.indexOf("isOk:01") + 13, 47).toUpper()));
            }
        }

        // read the rest blocks of a sector
        if(isKeyAValid || isKeyBValid)
        {
            for(int j = 1; j < 4; j++)
            {
                QApplication::processEvents();
                result = util->execCMDWithOutput("hf mf rdbl "
                                                 + QString::number(4 * i + j)
                                                 + " "
                                                 + (isKeyAValid ? "A" : "B")
                                                 + " "
                                                 + ui->MF_keyWidget->item(i, (isKeyAValid ? 1 : 2))->text(), waitTime);
                result = result.mid(result.indexOf("isOk:01") + 13, 47).toUpper();
                ui->MF_dataWidget->setItem(4 * i + j, 2, new QTableWidgetItem(result));
            }

            QApplication::processEvents();
            // fill the MF_dataWidget with the known valid key
            //
            // check whether the MF_dataWidget contains the valid key,
            // and fill MF_keyWidget(when you only have KeyA but the ReadBlock output contains the KeyB)
            //
            // the structure is not symmetric, since you cannot get KeyA from output
            // this program will only process the provided KeyA(in MF_keyWidget)
            result = ui->MF_dataWidget->item(4 * i + 3, 2)->text();
            if(isKeyAValid)
            {
                for(int j = 0; j < 6; j++)
                {
                    result = result.replace(j * 3, 2, ui->MF_keyWidget->item(i, 1)->text().mid(j * 2, 2));
                }
            }
            else
            {
                result = result.replace(0, 18, "?? ?? ?? ?? ?? ?? ");
            }
            ui->MF_dataWidget->setItem(4 * i + 3, 2, new QTableWidgetItem(result));

            if(isKeyBValid)
            {
                for(int j = 0; j < 6; j++)
                {
                    result = result.replace(30 + j * 3, 2, ui->MF_keyWidget->item(i, 2)->text().mid(j * 2, 2));
                    ui->MF_dataWidget->setItem(4 * i + 3, 2, new QTableWidgetItem(result));
                }
            }
            else
            {
                QString tmpKey = result.right(18).replace(" ", "");
                result = util->execCMDWithOutput("hf mf rdbl "
                                                 + QString::number(4 * i + 3)
                                                 + " B "
                                                 + tmpKey, waitTime);
                if(result.indexOf("isOk:01") != -1)
                {
                    ui->MF_keyWidget->setItem(i, 2, new QTableWidgetItem(tmpKey));
                }
                else
                {
                    result = ui->MF_dataWidget->item(4 * i + 3, 2)->text();
                    result = result.replace(30, 17, "?? ?? ?? ?? ?? ??");
                    ui->MF_dataWidget->setItem(4 * i + 3, 2, new QTableWidgetItem(result));
                }
            }
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
    QString result;
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            result = util->execCMDWithOutput("hf mf wrbl "
                                             + QString::number(i * 4 + j)
                                             + " A "
                                             + ui->MF_keyWidget->item(i, 1)->text()
                                             + " "
                                             + ui->MF_dataWidget->item(2, i * 4 + j)->text().replace(" ", ""));
            if(result.indexOf("isOk:01") == -1)
            {
                result = util->execCMDWithOutput("hf mf wrbl "
                                                 + QString::number(i * 4 + j)
                                                 + " B "
                                                 + ui->MF_keyWidget->item(i, 2)->text()
                                                 + " "
                                                 + ui->MF_dataWidget->item(2, i * 4 + j)->text().replace(" ", ""));
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
