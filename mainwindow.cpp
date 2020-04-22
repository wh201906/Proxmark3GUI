#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pm3Thread=new QThread(this);
    pm3 = new PM3Process(pm3Thread);
//    pm3->moveToThread(pm3Thread);
//    pm3->init();
    pm3Thread->start();
    pm3state=false;

    mifare = new Mifare;

    uiInit();
    signalInit();
}

MainWindow::~MainWindow()
{
    delete ui;
    emit killPM3();
    pm3Thread->exit(0);
    pm3Thread->wait(5000);
    delete pm3;
    delete pm3Thread;
}

// ******************** basic functions ********************

void MainWindow::on_PM3_refreshPortButton_clicked()
{
    ui->PM3_portBox->clear();
    ui->PM3_portBox->addItem("");
    QSerialPort serial;
    QStringList serialList;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug()<<info.isBusy()<<info.isNull()<<info.portName();
        serial.setPort(info);

        if(serial.open(QIODevice::ReadWrite))
        {
            serialList<<info.portName();
            serial.close();
        }
    }
    foreach(QString port, serialList)
    {
        ui->PM3_portBox->addItem(port);
    }
}

void MainWindow::on_PM3_connectButton_clicked()
{
    qDebug()<<"Main:"<<QThread::currentThread();
    QString port = ui->PM3_portBox->currentText();
    if(port == "")
        QMessageBox::information(NULL, "Info", "Plz choose a port first", QMessageBox::Ok);
    else
    {
        emit connectPM3(ui->PM3_pathEdit->text(), port);
    }
}

void MainWindow::onPM3StateChanged(bool st, QString info)
{
    pm3state=st;
    if(st==true)
    {
        setStatusBar(PM3VersionBar,info);
        setStatusBar(connectStatusBar,"Connected");
    }
    else
    {
        setStatusBar(connectStatusBar,"Not Connected");
    }
}

void MainWindow::on_PM3_disconnectButton_clicked()
{
    pm3state=false;
    emit killPM3();
    emit setSerialListener("", false);
    setStatusBar(connectStatusBar,"Not Connected");
}

// *********************************************************

// ******************** raw command ********************

void MainWindow::on_Raw_sendCMDButton_clicked()
{
    execCMD(ui->Raw_CMDEdit->text());
}

void MainWindow::on_Raw_clearOutputButton_clicked()
{
    ui->Raw_outputEdit->clear();
}

void MainWindow::on_Raw_CMDHistoryBox_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
    {
        ui->Raw_CMDHistoryWidget->setVisible(true);
        ui->Raw_clearHistoryButton->setVisible(true);
        ui->Raw_CMDHistoryBox->setText("History:");
    }
    else
    {
        ui->Raw_CMDHistoryWidget->setVisible(false);
        ui->Raw_clearHistoryButton->setVisible(false);
        ui->Raw_CMDHistoryBox->setText("");
    }
}

void MainWindow::on_Raw_clearHistoryButton_clicked()
{
    ui->Raw_CMDHistoryWidget->clear();
}

void MainWindow::on_Raw_CMDHistoryWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->Raw_CMDEdit->setText(item->text());
    ui->Raw_CMDEdit->setFocus();
}

// *****************************************************

// ******************** mifare ********************

void MainWindow::on_MF_Attack_infoButton_clicked()
{
    execCMD("hf 14a info", true);
}

void MainWindow::on_MF_Attack_chkButton_clicked()
{
    QString result = execCMDWithOutput("hf mf chk *1 ?");
    result = result.mid(result.indexOf("|---|----------------|----------------|"));
    QStringList keys = result.split("\r\n");
    for(int i = 0; i < 16; i++)
    {
        ui->MF_keyWidget->setItem(i, 1, new QTableWidgetItem(keys[i + 3].mid(7, 12).trimmed().toUpper()));
        ui->MF_keyWidget->setItem(i, 2, new QTableWidgetItem(keys[i + 3].mid(24, 12).trimmed().toUpper()));
    }
    qDebug() << "***********\n" << keys << "***********\n";
}

void MainWindow::on_MF_Attack_nestedButton_clicked()
{
    QString result = execCMDWithOutput("hf mf nested 1 *");
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

void MainWindow::on_MF_Attack_hardnestedButton_clicked()
{
    MF_Attack_hardnestedDialog dialog;
    connect(&dialog, &MF_Attack_hardnestedDialog::sendCMD, this, &MainWindow::execCMD);
    dialog.exec();
}

void MainWindow::on_MF_Attack_sniffButton_clicked()
{
    execCMD("hf mf sniff", true);
}

void MainWindow::on_MF_Attack_listButton_clicked()
{
    execCMD("hf list mf", true);
}

void MainWindow::on_MF_RW_readAllButton_clicked()
{
    QString result;
    bool isKeyAValid;
    bool isKeyBValid;
    const int waitTime = 500;
    for(int i = 0; i < 16; i++)
    {
        QApplication::processEvents();
        result = "";
        isKeyAValid = false;
        isKeyBValid = false;

        // check keys and read the first block of each sector
        if(ui->MF_keyWidget->item(i, 1) != nullptr && MF_isKeyValid(ui->MF_keyWidget->item(i, 1)->text()))
        {
            result = execCMDWithOutput("hf mf rdbl "
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
        if(ui->MF_keyWidget->item(i, 2) != nullptr && MF_isKeyValid(ui->MF_keyWidget->item(i, 2)->text()))
        {
            result = execCMDWithOutput("hf mf rdbl "
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
                result = execCMDWithOutput("hf mf rdbl "
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
                result = execCMDWithOutput("hf mf rdbl "
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

void MainWindow::on_MF_RW_readBlockButton_clicked()
{
    QString result = execCMDWithOutput("hf mf rdbl "
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
                result = execCMDWithOutput("hf mf rdbl "
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

    }
}

void MainWindow::on_MF_RW_writeBlockButton_clicked()
{
    QString result = execCMDWithOutput("hf mf wrbl "
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

void MainWindow::on_MF_RW_writeAllButton_clicked()
{
    QString result;
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            result = execCMDWithOutput("hf mf wrbl "
                                       + QString::number(i * 4 + j)
                                       + " A "
                                       + ui->MF_keyWidget->item(i, 1)->text()
                                       + " "
                                       + ui->MF_dataWidget->item(2, i * 4 + j)->text().replace(" ", ""));
            if(result.indexOf("isOk:01") == -1)
            {
                result = execCMDWithOutput("hf mf wrbl "
                                           + QString::number(i * 4 + j)
                                           + " B "
                                           + ui->MF_keyWidget->item(i, 2)->text()
                                           + " "
                                           + ui->MF_dataWidget->item(2, i * 4 + j)->text().replace(" ", ""));
            }
        }
    }
}

// ************************************************


// ******************** other ********************

void MainWindow::refresh()
{
    QString btay = pm3->readLine();
    while(btay != "")
    {
        qDebug() << btay;
        ui->Raw_outputEdit->insertPlainText(btay);
        btay = pm3->readLine();
    }
    ui->Raw_outputEdit->moveCursor(QTextCursor::End);
}

void MainWindow::sendMSG()
{
    if(ui->Raw_CMDEdit->hasFocus())
        on_Raw_sendCMDButton_clicked();
}

void MainWindow::uiInit()
{
    connect(ui->Raw_CMDEdit, &QLineEdit::editingFinished, this, &MainWindow::sendMSG);

    connectStatusBar = new QLabel(this);
    programStatusBar = new QLabel(this);
    PM3VersionBar = new QLabel(this);
    setStatusBar(connectStatusBar, "Not Connected");
    setStatusBar(programStatusBar, "Idle");
    setStatusBar(PM3VersionBar, "");
    ui->statusbar->addPermanentWidget(PM3VersionBar, 1);
    ui->statusbar->addPermanentWidget(connectStatusBar, 1);
    ui->statusbar->addPermanentWidget(programStatusBar, 1);

    ui->MF_dataWidget->setColumnCount(3);
    ui->MF_dataWidget->setRowCount(64);
    ui->MF_dataWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Sector"));
    ui->MF_dataWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Block"));
    ui->MF_dataWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Data"));
    for(int i = 0; i < 64; i++)
        ui->MF_dataWidget->setItem(i, 1, new QTableWidgetItem(QString::number(i)));
    for(int i = 0; i < 16; i++)
        ui->MF_dataWidget->setItem(i * 4, 0, new QTableWidgetItem(QString::number(i)));
    ui->MF_dataWidget->verticalHeader()->setVisible(false);
    ui->MF_dataWidget->setColumnWidth(0, 50);
    ui->MF_dataWidget->setColumnWidth(1, 40);
    ui->MF_dataWidget->setColumnWidth(2, 400);

    ui->MF_keyWidget->setColumnCount(3);
    ui->MF_keyWidget->setRowCount(16);
    ui->MF_keyWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Sector"));
    ui->MF_keyWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("KeyA"));
    ui->MF_keyWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("KeyB"));
    for(int i = 0; i < 16; i++)
        ui->MF_keyWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
    ui->MF_keyWidget->verticalHeader()->setVisible(false);
    ui->MF_keyWidget->setColumnWidth(0, 50);
    ui->MF_keyWidget->setColumnWidth(1, 200);
    ui->MF_keyWidget->setColumnWidth(2, 200);

    for(int i = 0; i < 64; i++)
    {
        ui->MF_RW_blockBox->addItem(QString::number(i));
        ui->MF_UID_blockBox->addItem(QString::number(i));
    }

    on_Raw_CMDHistoryBox_stateChanged(Qt::Unchecked);
    on_PM3_refreshPortButton_clicked();
}

void MainWindow::signalInit()
{
    connect(pm3, &PM3Process::readyRead, this, &MainWindow::refresh);

    connect(this,&MainWindow::requiringOutput,pm3,&PM3Process::setRequiringOutput);
    connect(this,&MainWindow::connectPM3,pm3,&PM3Process::connectPM3);
    connect(pm3, &PM3Process::PM3StatedChanged, this, &MainWindow::onPM3StateChanged);
    connect(this,&MainWindow::killPM3,pm3,&PM3Process::kill);

    connect(this,&MainWindow::write,pm3,&PM3Process::write);
}

void MainWindow::setStatusBar(QLabel* target, const QString & text)
{
    if(target == PM3VersionBar)
        target->setText("HW Version:" + text);
    else if(target == connectStatusBar)
        target->setText("Connecton State:" + text);
    else if(target == programStatusBar)
        target->setText("Program State:" + text);
}

void MainWindow::execCMD(QString cmd, bool gotoRawTab)
{
    ui->Raw_CMDEdit->setText(cmd);
    if(ui->Raw_CMDHistoryWidget->count() == 0 || ui->Raw_CMDHistoryWidget->item(ui->Raw_CMDHistoryWidget->count() - 1)->text() != cmd)
        ui->Raw_CMDHistoryWidget->addItem(cmd);
    qDebug() << cmd;
    emit write(cmd + "\r\n");
    if(gotoRawTab)
        ui->funcTab->setCurrentIndex(1);
}

QString MainWindow::execCMDWithOutput(QString cmd, int msec)
{
    emit requiringOutput(true);
    execCMD(cmd);
    while(pm3->waitForReadyRead(msec))
        ;
    pm3->setRequiringOutput(false);
    return pm3->getRequiredOutput();
}

bool MainWindow::MF_isKeyValid(const QString key)
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
// ***********************************************



