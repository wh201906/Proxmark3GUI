#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pm3Thread = new QThread(this);
    pm3 = new PM3Process(pm3Thread);
//    pm3->moveToThread(pm3Thread);
//    pm3->init();
    pm3Thread->start();
    pm3state = false;

    util = new Util(this);
    mifare = new Mifare(ui, util, this);


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

void MainWindow::initUI()
{
    ui->retranslateUi(this);
    uiInit();
    signalInit();
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
        qDebug() << info.isBusy() << info.isNull() << info.portName();
        serial.setPort(info);

        if(serial.open(QIODevice::ReadWrite))
        {
            serialList << info.portName();
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
    qDebug() << "Main:" << QThread::currentThread();
    QString port = ui->PM3_portBox->currentText();
    if(port == "")
        QMessageBox::information(NULL, tr("Info"), tr("Plz choose a port first"), QMessageBox::Ok);
    else
    {
        emit connectPM3(ui->PM3_pathEdit->text(), port);
    }
}

void MainWindow::onPM3StateChanged(bool st, QString info)
{
    pm3state = st;
    if(st == true)
    {
        setStatusBar(PM3VersionBar, info);
        setStatusBar(connectStatusBar, tr("Connected"));
    }
    else
    {
        setStatusBar(connectStatusBar, tr("Not Connected"));
    }
}

void MainWindow::on_PM3_disconnectButton_clicked()
{
    pm3state = false;
    emit killPM3();
    emit setSerialListener("", false);
    setStatusBar(connectStatusBar, tr("Not Connected"));
}

void MainWindow::refreshOutput(const QString& output)
{
//    qDebug() << "MainWindow::refresh:" << output;
    ui->Raw_outputEdit->insertPlainText(output);
    ui->Raw_outputEdit->moveCursor(QTextCursor::End);
}

void MainWindow::refreshCMD(const QString& cmd)
{
    ui->Raw_CMDEdit->setText(cmd);
    if(cmd != "" && (ui->Raw_CMDHistoryWidget->count() == 0 || ui->Raw_CMDHistoryWidget->item(ui->Raw_CMDHistoryWidget->count() - 1)->text() != cmd))
        ui->Raw_CMDHistoryWidget->addItem(cmd);
}

// *********************************************************

// ******************** raw command ********************

void MainWindow::on_Raw_sendCMDButton_clicked()
{
    util->execCMD(ui->Raw_CMDEdit->text());
    refreshCMD(ui->Raw_CMDEdit->text());
}

void MainWindow::on_Raw_clearOutputButton_clicked()
{
    ui->Raw_outputEdit->clear();
}

void MainWindow::on_Raw_CMDHistoryBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        ui->Raw_CMDHistoryWidget->setVisible(true);
        ui->Raw_clearHistoryButton->setVisible(true);
        ui->Raw_CMDHistoryBox->setText(tr("History:"));
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

void MainWindow::sendMSG() // send command when pressing Enter
{
    if(ui->Raw_CMDEdit->hasFocus())
        on_Raw_sendCMDButton_clicked();
}

// *****************************************************

// ******************** mifare ********************
void MainWindow::MF_onTypeChanged(int id, bool st)
{
    typeBtnGroup->blockSignals(true);
    qDebug() << id << typeBtnGroup->checkedId();
    if(!st)
    {
        int result = QMessageBox::question(this, tr("Info"), tr("When Changeing card type, the data and keys in this app will be cleard.\nContinue?"), QMessageBox::Yes | QMessageBox::No);
        if(result == QMessageBox::Yes)
        {
            qDebug() << "Yes";
            mifare->setCardType(typeBtnGroup->checkedId());
            MF_widgetReset();
        }
        else
        {
            qDebug() << "No";
            typeBtnGroup->button(id)->setChecked(true);
        }
    }
    typeBtnGroup->blockSignals(false);
}

void MainWindow::on_MF_Attack_infoButton_clicked()
{
    mifare->info();
}

void MainWindow::on_MF_Attack_chkButton_clicked()
{
    mifare->chk();
}

void MainWindow::on_MF_Attack_nestedButton_clicked()
{
    mifare->nested();
}

void MainWindow::on_MF_Attack_hardnestedButton_clicked()
{
    mifare->hardnested();
}

void MainWindow::on_MF_RW_readAllButton_clicked()
{
    mifare->readAll();
}

void MainWindow::on_MF_RW_readBlockButton_clicked()
{
    mifare->read();
}

void MainWindow::on_MF_RW_writeBlockButton_clicked()
{
    mifare->write();
}

void MainWindow::on_MF_RW_writeAllButton_clicked()
{
    mifare->writeAll();
}

void MainWindow::on_MF_RW_dumpButton_clicked()
{
    mifare->dump();
}

void MainWindow::on_MF_RW_restoreButton_clicked()
{
    mifare->restore();
}

void MainWindow::on_MF_UID_readAllButton_clicked()
{
    mifare->readAllC();
}

void MainWindow::on_MF_UID_readBlockButton_clicked()
{
    mifare->readC();
}

void MainWindow::on_MF_UID_writeAllButton_clicked()
{
    mifare->writeAllC();
}

void MainWindow::on_MF_UID_writeBlockButton_clicked()
{
    mifare->writeC();
}

void MainWindow::on_MF_Sniff_sniffButton_clicked()
{
    mifare->sniff();
}

void MainWindow::on_MF_Sniff_listButton_clicked()
{
    mifare->list();
}

void MainWindow::MF_widgetReset()
{
    int secs = mifare->cardType.sectors;
    int blks = mifare->cardType.blocks;
    ui->MF_RW_blockBox->clear();
    ui->MF_keyWidget->setRowCount(secs);
    ui->MF_dataWidget->setRowCount(blks);

    for(int i = 0; i < blks; i++)
    {
        setTableItem(ui->MF_dataWidget, i, 0, "");
        setTableItem(ui->MF_dataWidget, i, 1, QString::number(i));
        setTableItem(ui->MF_dataWidget, i, 2, "");
        ui->MF_RW_blockBox->addItem(QString::number(i));
    }

    for(int i = 0; i < secs; i++)
    {
        setTableItem(ui->MF_keyWidget, i, 0, QString::number(i));
        setTableItem(ui->MF_keyWidget, i, 1, "");
        setTableItem(ui->MF_keyWidget, i, 2, "");
        setTableItem(ui->MF_dataWidget, mifare->cardType.blks[i], 0, QString::number(i));
    }
}
// ************************************************


// ******************** other ********************

void MainWindow::uiInit()
{
    connect(ui->Raw_CMDEdit, &QLineEdit::editingFinished, this, &MainWindow::sendMSG);

    connectStatusBar = new QLabel(this);
    programStatusBar = new QLabel(this);
    PM3VersionBar = new QLabel(this);
    setStatusBar(connectStatusBar, tr("Not Connected"));
    setStatusBar(programStatusBar, tr("Idle"));
    setStatusBar(PM3VersionBar, "");
    ui->statusbar->addPermanentWidget(PM3VersionBar, 1);
    ui->statusbar->addPermanentWidget(connectStatusBar, 1);
    ui->statusbar->addPermanentWidget(programStatusBar, 1);

    ui->MF_dataWidget->setColumnCount(3);
    ui->MF_dataWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Sec")));
    ui->MF_dataWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Blk")));
    ui->MF_dataWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Data")));
    ui->MF_dataWidget->verticalHeader()->setVisible(false);
    ui->MF_dataWidget->setColumnWidth(0, 35);
    ui->MF_dataWidget->setColumnWidth(1, 35);
    ui->MF_dataWidget->setColumnWidth(2, 400);
//    for(int i = 0; i < 256; i++)
//    {
//        ui->MF_dataWidget->setItem(i, 0, new QTableWidgetItem());
//        ui->MF_dataWidget->setItem(i, 1, new QTableWidgetItem());
//        ui->MF_dataWidget->setItem(i, 2, new QTableWidgetItem());
//    }

    ui->MF_keyWidget->setColumnCount(3);
    ui->MF_keyWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Sec")));
    ui->MF_keyWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("KeyA")));
    ui->MF_keyWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("KeyB")));
    ui->MF_keyWidget->verticalHeader()->setVisible(false);
    ui->MF_keyWidget->setColumnWidth(0, 35);
    ui->MF_keyWidget->setColumnWidth(1, 110);
    ui->MF_keyWidget->setColumnWidth(2, 110);
//    for(int i = 0; i < 40; i++)
//    {
//        ui->MF_keyWidget->setItem(i, 0, new QTableWidgetItem());
//        ui->MF_keyWidget->setItem(i, 1, new QTableWidgetItem());
//        ui->MF_keyWidget->setItem(i, 2, new QTableWidgetItem());
//    }

    MF_widgetReset();
    typeBtnGroup = new QButtonGroup(this);
    typeBtnGroup->addButton(ui->MF_Type_miniButton, 0);
    typeBtnGroup->addButton(ui->MF_Type_1kButton, 1);
    typeBtnGroup->addButton(ui->MF_Type_2kButton, 2);
    typeBtnGroup->addButton(ui->MF_Type_4kButton, 4);
    connect(typeBtnGroup, QOverload<int, bool>::of(&QButtonGroup::buttonToggled), this, &MainWindow::MF_onTypeChanged);

    on_Raw_CMDHistoryBox_stateChanged(Qt::Unchecked);
    on_PM3_refreshPortButton_clicked();
}

void MainWindow::signalInit()
{
    connect(pm3, &PM3Process::newOutput, util, &Util::processOutput);
    connect(util, &Util::refreshOutput, this, &MainWindow::refreshOutput);

    connect(this, &MainWindow::connectPM3, pm3, &PM3Process::connectPM3);
    connect(pm3, &PM3Process::PM3StatedChanged, this, &MainWindow::onPM3StateChanged);
    connect(this, &MainWindow::killPM3, pm3, &PM3Process::kill);

    connect(util, &Util::write, pm3, &PM3Process::write);
}

void MainWindow::setStatusBar(QLabel* target, const QString & text)
{
    if(target == PM3VersionBar)
        target->setText(tr("HW Version:") + text);
    else if(target == connectStatusBar)
        target->setText(tr("PM3:") + text);
    else if(target == programStatusBar)
        target->setText(tr("State:") + text);
}

void MainWindow::setTableItem(QTableWidget* widget, int row, int column, const QString& text)
{
    if(widget->item(row, column) == nullptr)
        widget->setItem(row, column, new QTableWidgetItem());
    widget->item(row, column)->setText(text);
}
// ***********************************************
