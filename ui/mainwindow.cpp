#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MF_simGroupBox->setVisible(false); // developing...
    ui->MF_sniffGroupBox->setVisible(false); // developing...

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

void MainWindow::initUI() // will be called by main.app
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

void MainWindow::on_MF_data2KeyBotton_clicked()
{
    mifare->data_data2Key();
}

void MainWindow::on_MF_key2DataBotton_clicked()
{
    mifare->data_key2Data();
}

void MainWindow::on_MF_fontButton_clicked()
{
    bool isOK = false;
    QFont font = QFontDialog::getFont(&isOK, ui->MF_keyWidget->font(), this, tr("Plz select the font of data widget and key widget"));

    if(isOK)
    {
        ui->MF_keyWidget->setFont(font);
        ui->MF_dataWidget->setFont(font);
    }
}

void MainWindow::on_MF_dataWidget_itemChanged(QTableWidgetItem *item)
{

    if(item->column() == 2)
    {
        QString data = item->text().replace(" ", "");
        if(data == "" || mifare->data_isDataValid(data) == Mifare::DATA_NOSPACE)
        {
            mifare->data_setData(item->row(), data);
        }
        else
        {
            QMessageBox::information(this, tr("Info"), tr("Data must consists of 32 Hex symbols(Whitespace is allowed)"));
        }
        mifare->data_syncWithDataWidget(false, item->row());
    }
}

void MainWindow::on_MF_keyWidget_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 1)
    {
        QString key = item->text().replace(" ", "");
        if(key == "" || mifare->data_isKeyValid(key))
        {
            mifare->data_setKey(item->row(), true, key);
        }
        else
        {
            QMessageBox::information(this, tr("Info"), tr("Key must consists of 12 Hex symbols(Whitespace is allowed)"));
        }
        mifare->data_syncWithKeyWidget(false, item->row(), true);
    }
    else if(item->column() == 2)
    {
        QString key = item->text().replace(" ", "");
        if(key == "" || mifare->data_isKeyValid(key))
        {
            mifare->data_setKey(item->row(), false, key);
        }
        else
        {
            QMessageBox::information(this, tr("Info"), tr("Key must consists of 12 Hex symbols(Whitespace is allowed)"));
        }
        mifare->data_syncWithKeyWidget(false, item->row(), false);
    }
}

void MainWindow::on_MF_File_loadButton_clicked()
{
    QString title = "";
    QString filename = "";
    if(ui->MF_File_dataBox->isChecked())
    {
        title = tr("Plz select the data file:");
        filename = QFileDialog::getOpenFileName(this, title, "./", tr("Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml);;All Files(*.*)"));
        qDebug() << filename;
        if(filename != "")
        {
            if(!mifare->data_loadDataFile(filename))
            {
                QMessageBox::information(this, tr("Info"), tr("Failed to open") + "\n" + filename);
            }
        }
    }
    else if(ui->MF_File_keyBox->isChecked())
    {
        title = tr("Plz select the key file:");
        filename = QFileDialog::getOpenFileName(this, title, "./", tr("Binary Key Files(*.bin *.dump);;All Files(*.*)"));
        qDebug() << filename;
        if(filename != "")
        {
            if(!mifare->data_loadKeyFile(filename))
            {
                QMessageBox::information(this, tr("Info"), tr("Failed to open") + "\n" + filename);
            }
        }
    }

}

void MainWindow::on_MF_File_saveButton_clicked()
{

    QString title = "";
    QString filename = "";
    QString selectedType = "";

    if(ui->MF_File_dataBox->isChecked())
    {
        title = tr("Plz select the location to save data file:");
        filename = QFileDialog::getSaveFileName(this, title, "./", tr("Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml)"), &selectedType);
        qDebug() << filename;
        if(filename != "")
        {
            if(!mifare->data_saveDataFile(filename, selectedType == "Binary Data Files(*.bin *.dump)"))
            {
                QMessageBox::information(this, tr("Info"), tr("Failed to save to") + "\n" + filename);
            }
        }
    }
    else if(ui->MF_File_keyBox->isChecked())
    {
        title = tr("Plz select the location to save key file:");
        filename = QFileDialog::getSaveFileName(this, title, "./", tr("Binary Key Files(*.bin *.dump)"), &selectedType);
        qDebug() << filename;
        if(filename != "")
        {
            if(!mifare->data_saveKeyFile(filename, selectedType == "Binary Key Files(*.bin *.dump)"))
            {
                QMessageBox::information(this, tr("Info"), tr("Failed to save to") + "\n" + filename);
            }
        }
    }
    qDebug() << filename << selectedType;
}

void MainWindow::on_MF_File_clearButton_clicked()
{
    if(ui->MF_File_keyBox->isChecked())
    {
        mifare->data_clearKey();
        mifare->data_syncWithKeyWidget();
    }
    else if(ui->MF_File_dataBox->isChecked())
    {
        mifare->data_clearData();
        mifare->data_syncWithDataWidget();
    }
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

void MainWindow::on_MF_UID_wipeButton_clicked()
{
    mifare->wipeC();
}

void MainWindow::on_MF_UID_aboutUIDButton_clicked()
{
    QString msg;
    msg += tr("    Normally, the Block 0 of a typical Mifare card, which contains the UID, is locked during the manufacture. Users cannot write anything to Block 0 or set a new UID to a normal Mifare card.\n");
    msg += tr("    Chinese Magic Cards(aka UID Cards) are some special cards whose Block 0 are writeable. And you can change UID by writing to it.\n");
    msg += "\n";
    msg += tr("There are two versions of Chinese Magic Cards, the Gen1 and the Gen2.\n");
    msg += tr("    Gen1:\n    also called UID card in China. It responses to some backdoor commands so you can access any blocks without password. The Proxmark3 has a bunch of related commands(csetblk, cgetblk, ...) to deal with this type of card, and my GUI also support these commands.\n");
    msg += tr("    Gen2:\n    doesn't response to the backdoor commands, which means that a reader cannot detect whether it is a Chinese Magic Card or not by sending backdoor commands.\n");
    msg += "\n";
    msg += tr("There are some types of Chinese Magic Card Gen2.\n");
    msg += tr("    CUID Card:\n    the Block 0 is writeable, you can write to this block repeatedly by normal wrbl command.\n");
    msg += tr("    (hf mf wrbl 0 A FFFFFFFFFFFF <the data you want to write>)\n");
    msg += tr("    FUID Card:\n    you can only write to Block 0 once. After that, it seems like a typical Mifare card(Block 0 cannot be written to).\n");
    msg += tr("    (some readers might try changing the Block 0, which could detect the CUID Card. In that case, you should use FUID card.)\n");
    msg += tr("    UFUID Card:\n    It behaves like a CUID card(or UID card? I'm not sure) before you send some special command to lock it. Once it is locked, you cannot change its Block 0(just like a typical Mifare card).\n");
    msg += "\n";
    msg += tr("    Seemingly, these Chinese Magic Cards are more easily to be compromised by Nested Attack(it takes little time to get an unknown key).\n");
    QMessageBox::information(this, tr("About UID Card"), msg);
}

void MainWindow::on_MF_UID_setParaButton_clicked()
{
    mifare->setParameterC();
}

void MainWindow::on_MF_UID_lockButton_clicked()
{
    mifare->lockC();
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
    ui->MF_dataWidget->setColumnWidth(2, 430);

    ui->MF_keyWidget->setColumnCount(3);
    ui->MF_keyWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Sec")));
    ui->MF_keyWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("KeyA")));
    ui->MF_keyWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("KeyB")));
    ui->MF_keyWidget->verticalHeader()->setVisible(false);
    ui->MF_keyWidget->setColumnWidth(0, 35);
    ui->MF_keyWidget->setColumnWidth(1, 115);
    ui->MF_keyWidget->setColumnWidth(2, 115);

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
