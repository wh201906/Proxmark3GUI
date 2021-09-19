#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dockAllWindows = new QAction(tr("Dock all windows"), this);
    myInfo = new QAction("wh201906", this);
    currVersion = new QAction(tr("Ver: ") + QApplication::applicationVersion().section('.', 0, -2), this); // ignore the 4th version number
    checkUpdate = new QAction(tr("Check Update"), this);
    connect(dockAllWindows, &QAction::triggered, [ = ]()
    {
        for(int i = 0; i < dockList.size(); i++)
            dockList[i]->setFloating(false);
    });
    connect(myInfo, &QAction::triggered, [ = ]()
    {
        QDesktopServices::openUrl(QUrl("https://github.com/wh201906"));
    });
    connect(checkUpdate, &QAction::triggered, [ = ]()
    {
        QDesktopServices::openUrl(QUrl("https://github.com/wh201906/Proxmark3GUI/releases"));
    });

    settings = new QSettings("GUIsettings.ini", QSettings::IniFormat);
    settings->setIniCodec("UTF-8");

    pm3Thread = new QThread(this);
    pm3 = new PM3Process(pm3Thread);
    pm3Thread->start();
    pm3state = false;
    clientWorkingDir = new QDir;

    util = new Util(this);
    Util::setUI(ui);
    mifare = new Mifare(ui, util, this);
    lf = new LF(ui, util, this);

    keyEventFilter = new MyEventFilter(QEvent::KeyPress);
    resizeEventFilter = new MyEventFilter(QEvent::Resize);

    // hide unused tabs
//    ui->funcTab->removeTab(1);
    ui->funcTab->removeTab(2);

    portSearchTimer = new QTimer(this);
    portSearchTimer->setInterval(2000);
    connect(portSearchTimer, &QTimer::timeout, this, &MainWindow::on_portSearchTimer_timeout);
    portSearchTimer->start();

    contextMenu = new QMenu();
    contextMenu->addAction(dockAllWindows);
    contextMenu->addSeparator();
    contextMenu->addAction(myInfo);
    currVersion->setEnabled(false);
    contextMenu->addAction(currVersion);
    contextMenu->addAction(checkUpdate);

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

void MainWindow::loadConfig()
{
    QFile configList(ui->Set_Client_configPathEdit->text());
    if(!configList.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, tr("Info"), tr("Failed to load config file"));
        return;
    }

    QByteArray configData = configList.readAll();
    QJsonDocument configJson(QJsonDocument::fromJson(configData));
    mifare->setConfigMap(configJson.object()["mifare classic"].toObject().toVariantMap());

}

void MainWindow::initUI() // will be called by main.app
{
    ui->retranslateUi(this);
    uiInit();
    signalInit();
    setState(false);
    dockInit();
}

// ******************** basic functions ********************

void MainWindow::on_portSearchTimer_timeout()
{
    QStringList newPortList;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
//        qDebug() << info.isBusy() << info.isNull() << info.portName() << info.description();
        if(!info.isNull())
            newPortList << info.portName();
    }
    if(newPortList != portList) // update PM3_portBox when available ports changed
    {
        portList = newPortList;
        ui->PM3_portBox->clear();
        ui->PM3_portBox->addItems(portList);
    }
}

void MainWindow::on_PM3_connectButton_clicked()
{
    qDebug() << "Main:" << QThread::currentThread();

    QString port = ui->PM3_portBox->currentText();
    QString startArgs = ui->Set_Client_startArgsEdit->text();

    // on RRG repo, if no port is specified, the client will search the available port
    if(port == "" && startArgs.contains("<port>")) // has <port>, no port
    {
        QMessageBox::information(this, tr("Info"), tr("Plz choose a port first"), QMessageBox::Ok);
        return;
    }

    if(!startArgs.contains("<port>")) // no <port>
        port = ""; // a symbol

    QStringList args = startArgs.replace("<port>", port).split(' ');
    saveClientPath(ui->PM3_pathEdit->text());

    QProcess envSetProcess;
    QFileInfo envScriptPath(ui->Set_Client_envScriptEdit->text());
    if(envScriptPath.exists())
    {
        qDebug() << envScriptPath.absoluteFilePath();
        // use the shell session to keep the environment then read it
#ifdef Q_OS_WIN
        // cmd /c "<path>">>nul && set
        envSetProcess.start("cmd", {}, QProcess::Unbuffered | QProcess::ReadWrite | QProcess::Text);
        envSetProcess.write(QString("\"" + envScriptPath.absoluteFilePath() + "\">>nul\n").toLatin1());
        envSetProcess.waitForReadyRead(10000);
        envSetProcess.readAll();
        envSetProcess.write("set\n");
#else
        // need implementation(or test if space works)
        // sh -c '. "<path>">>/dev/null && env'
        envSetProcess.start("sh -c \' . \"" + envScriptPath.absoluteFilePath() + "\">>/dev/null && env");
#endif
        envSetProcess.waitForReadyRead(10000);
        QString envSetResult = QString(envSetProcess.readAll());
        clientEnv = envSetResult.split("\n", QString::SkipEmptyParts);
        if(clientEnv.size() > 2) // the first element is "set" and the last element is the current path
        {
            clientEnv.removeFirst();
            clientEnv.removeLast();
            emit setProcEnv(&clientEnv);
        }
//      qDebug() << "Get Env List" << clientEnv;
    }
    else
        clientEnv.clear();

    clientWorkingDir->setPath(QApplication::applicationDirPath());
    qDebug() << clientWorkingDir->absolutePath();
    clientWorkingDir->mkpath(ui->Set_Client_workingDirEdit->text());
    qDebug() << clientWorkingDir->absolutePath();
    clientWorkingDir->cd(ui->Set_Client_workingDirEdit->text());
    qDebug() << clientWorkingDir->absolutePath();
    emit setWorkingDir(clientWorkingDir->absolutePath());

    loadConfig();
    emit connectPM3(ui->PM3_pathEdit->text(), args);
    if(port != "" && !keepClientActive)
        emit setSerialListener(port, true);
    else if(!keepClientActive)
        emit setSerialListener(false);

    envSetProcess.kill();
}

void MainWindow::onPM3StateChanged(bool st, const QString& info)
{
    pm3state = st;
    setState(st);
    if(st == true)
    {
        portSearchTimer->stop();
        setStatusBar(PM3VersionBar, info);
        setStatusBar(connectStatusBar, tr("Connected"));
    }
    else
    {
        portSearchTimer->start();
        setStatusBar(PM3VersionBar, "");
        setStatusBar(connectStatusBar, tr("Not Connected"));
    }
}

void MainWindow::on_PM3_disconnectButton_clicked()
{
    emit killPM3();
    emit setSerialListener(false);
}

void MainWindow::refreshOutput(const QString& output)
{
//    qDebug() << "MainWindow::refresh:" << output;
    ui->Raw_outputEdit->appendPlainText(output);
    ui->Raw_outputEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_stopButton_clicked()
{
    if(!pm3state)
        on_PM3_disconnectButton_clicked();
    else
    {
        on_PM3_disconnectButton_clicked();
        for(int i = 0; i < 10; i++)
        {
            util->delay(200);
            if(!pm3state)
                break;
        }
        emit reconnectPM3();
        emit setSerialListener(!keepClientActive);
    }
}
// *********************************************************

// ******************** raw command ********************

void MainWindow::on_Raw_CMDEdit_textChanged(const QString &arg1)
{
    stashedCMDEditText = arg1;
}

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


void MainWindow::refreshCMD(const QString& cmd)
{
    ui->Raw_CMDEdit->blockSignals(true);
    ui->Raw_CMDEdit->setText(cmd);
    if(cmd != "" && (ui->Raw_CMDHistoryWidget->count() == 0 || ui->Raw_CMDHistoryWidget->item(ui->Raw_CMDHistoryWidget->count() - 1)->text() != cmd))
        ui->Raw_CMDHistoryWidget->addItem(cmd);
    stashedCMDEditText = cmd;
    stashedIndex = -1;
    ui->Raw_CMDEdit->blockSignals(false);
}

void MainWindow::on_Raw_keyPressed(QObject* obj_addr, QEvent& event)
{
    if(event.type() == QEvent::KeyPress)
    {
        QKeyEvent& keyEvent = static_cast<QKeyEvent&>(event);
        if(obj_addr == ui->Raw_CMDEdit)
        {
            if(keyEvent.key() == Qt::Key_Up)
            {
                if(stashedIndex > 0)
                    stashedIndex--;
                else if(stashedIndex == -1)
                    stashedIndex = ui->Raw_CMDHistoryWidget->count() - 1;
            }
            else if(keyEvent.key() == Qt::Key_Down)
            {
                if(stashedIndex < ui->Raw_CMDHistoryWidget->count() - 1 && stashedIndex != -1)
                    stashedIndex++;
                else if(stashedIndex == ui->Raw_CMDHistoryWidget->count() - 1)
                    stashedIndex = -1;
            }
            if(keyEvent.key() == Qt::Key_Up || keyEvent.key() == Qt::Key_Down)
            {
                ui->Raw_CMDEdit->blockSignals(true);
                if(stashedIndex == -1)
                    ui->Raw_CMDEdit->setText(stashedCMDEditText);
                else
                    ui->Raw_CMDEdit->setText(ui->Raw_CMDHistoryWidget->item(stashedIndex)->text());
                ui->Raw_CMDEdit->blockSignals(false);
            }
        }
        else if(obj_addr == ui->Raw_outputEdit)
        {
            if(keyEvent.key() == Qt::Key_Up || keyEvent.key() == Qt::Key_Down)
                ui->Raw_CMDEdit->setFocus();
        }
    }
}
// *****************************************************

// ******************** mifare ********************
void MainWindow::on_MF_keyWidget_resized(QObject* obj_addr, QEvent& event)
{
    if(obj_addr == ui->MF_keyWidget && event.type() == QEvent::Resize)
    {
        QTableWidget* widget = (QTableWidget*)obj_addr;
        int keyItemWidth = widget->width();
        keyItemWidth -= widget->verticalScrollBar()->width();
        keyItemWidth -= 2 * widget->frameWidth();
        keyItemWidth -= widget->horizontalHeader()->sectionSize(0);
        widget->horizontalHeader()->resizeSection(1, keyItemWidth / 2);
        widget->horizontalHeader()->resizeSection(2, keyItemWidth / 2);
    }
}

void MainWindow::MF_onMFCardTypeChanged(int id, bool st)
{
    MFCardTypeBtnGroup->blockSignals(true);
    qDebug() << id << MFCardTypeBtnGroup->checkedId();
    if(!st)
    {
        int result;
        if(id > MFCardTypeBtnGroup->checkedId()) // id is specified in uiInit() with a proper order, so I can compare the size by id.
        {
            result = QMessageBox::question(this, tr("Info"), tr("Some of the data and key will be cleared.") + "\n" + tr("Continue?"), QMessageBox::Yes | QMessageBox::No);
        }
        else
        {
            result = QMessageBox::Yes;
        }
        if(result == QMessageBox::Yes)
        {
            qDebug() << "Yes";
            mifare->setCardType(MFCardTypeBtnGroup->checkedId());
            MF_widgetReset();
            mifare->data_syncWithDataWidget();
            mifare->data_syncWithKeyWidget();
        }
        else
        {
            qDebug() << "No";
            MFCardTypeBtnGroup->button(id)->setChecked(true);
        }
    }
    MFCardTypeBtnGroup->blockSignals(false);
}

void MainWindow::on_MF_selectAllBox_stateChanged(int arg1)
{
    ui->MF_dataWidget->blockSignals(true);
    ui->MF_selectAllBox->blockSignals(true);
    ui->MF_selectTrailerBox->blockSignals(true);
    if(arg1 == Qt::PartiallyChecked)
    {
        ui->MF_selectAllBox->setTristate(false);
        ui->MF_selectAllBox->setCheckState(Qt::Checked);
    }
    for(int i = 0; i < mifare->cardType.block_size; i++)
    {
        ui->MF_dataWidget->item(i, 1)->setCheckState(ui->MF_selectAllBox->checkState());
    }
    for(int i = 0; i < mifare->cardType.sector_size; i++)
    {
        ui->MF_dataWidget->item(mifare->cardType.blks[i], 0)->setCheckState(ui->MF_selectAllBox->checkState());
    }
    ui->MF_selectTrailerBox->setCheckState(ui->MF_selectAllBox->checkState());
    ui->MF_dataWidget->blockSignals(false);
    ui->MF_selectAllBox->blockSignals(false);
    ui->MF_selectTrailerBox->blockSignals(false);
}


void MainWindow::on_MF_selectTrailerBox_stateChanged(int arg1)
{
    int selectedSubBlocks = 0;

    ui->MF_dataWidget->blockSignals(true);
    ui->MF_selectAllBox->blockSignals(true);
    ui->MF_selectTrailerBox->blockSignals(true);
    if(arg1 == Qt::PartiallyChecked)
    {
        ui->MF_selectTrailerBox->setTristate(false);
        ui->MF_selectTrailerBox->setCheckState(Qt::Checked);
    }
    for(int i = 0; i < mifare->cardType.sector_size; i++)
    {
        ui->MF_dataWidget->item(mifare->cardType.blks[i] + mifare->cardType.blk[i] - 1, 1)->setCheckState(ui->MF_selectTrailerBox->checkState());
        selectedSubBlocks = 0;
        for(int j = 0; j < mifare->cardType.blk[i]; j++)
        {
            if(ui->MF_dataWidget->item(j + mifare->cardType.blks[i], 1)->checkState() == Qt::Checked)
                selectedSubBlocks++;
        }
        if(selectedSubBlocks == 0)
        {
            ui->MF_dataWidget->item(mifare->cardType.blks[i], 0)->setCheckState(Qt::Unchecked);
        }
        else if(selectedSubBlocks == mifare->cardType.blk[i])
        {
            ui->MF_dataWidget->item(mifare->cardType.blks[i], 0)->setCheckState(Qt::Checked);
        }
        else
        {
            ui->MF_dataWidget->item(mifare->cardType.blks[i], 0)->setCheckState(Qt::PartiallyChecked);
        }
    }

    ui->MF_dataWidget->blockSignals(false);
    ui->MF_selectAllBox->blockSignals(false);
    ui->MF_selectTrailerBox->blockSignals(false);
}


void MainWindow::on_MF_data2KeyButton_clicked()
{
    mifare->data_data2Key();
}

void MainWindow::on_MF_key2DataButton_clicked()
{
    mifare->data_key2Data();
}

void MainWindow::on_MF_fillKeysButton_clicked()
{
    mifare->data_fillKeys();
}

void MainWindow::on_MF_trailerDecoderButton_clicked()
{
    decDialog = new MF_trailerDecoderDialog(this);
    decDialog->show();
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
    ui->MF_dataWidget->blockSignals(true);
    ui->MF_selectAllBox->blockSignals(true);
    ui->MF_selectTrailerBox->blockSignals(true);
    if(item->column() == 0)
    {
        int selectedSectors = 0;
        for(int i = 0; i < mifare->cardType.blk[Mifare::data_b2s(item->row())]; i++)
        {
            ui->MF_dataWidget->item(i + item->row(), 1)->setCheckState(item->checkState());
            qDebug() << i << mifare->cardType.blk[item->row()] << i + item->row() << ui->MF_dataWidget->item(i + item->row(), 1)->text();
        }
        for(int i = 0; i < mifare->cardType.sector_size; i++)
        {
            if(ui->MF_dataWidget->item(mifare->cardType.blks[i], 0)->checkState() == Qt::Checked)
            {
                selectedSectors++;
            }
        }
        if(selectedSectors == 0)
        {
            ui->MF_selectAllBox->setCheckState(Qt::Unchecked);
            ui->MF_selectTrailerBox->setCheckState(Qt::Unchecked);
        }
        else if(selectedSectors == mifare->cardType.sector_size)
        {
            ui->MF_selectAllBox->setCheckState(Qt::Checked);
            ui->MF_selectTrailerBox->setCheckState(Qt::Checked);
        }
        else
        {
            ui->MF_selectAllBox->setCheckState(Qt::PartiallyChecked);
            ui->MF_selectTrailerBox->setCheckState(Qt::PartiallyChecked);
        }
    }
    else if(item->column() == 1)
    {
        int selectedSubBlocks = 0;
        int selectedBlocks = 0;
        int selectedTrailers = 0;

        for(int i = 0; i < mifare->cardType.block_size; i++)
        {
            if(ui->MF_dataWidget->item(i, 1)->checkState() == Qt::Checked)
                selectedBlocks++;
        }
        for(int i = 0; i < mifare->cardType.blk[Mifare::data_b2s(item->row())]; i++)
        {
            if(ui->MF_dataWidget->item(i + mifare->cardType.blks[Mifare::data_b2s(item->row())], 1)->checkState() == Qt::Checked)
                selectedSubBlocks++;
        }
        for(int i = 0; i < mifare->cardType.sector_size; i++)
        {
            int targetBlock = mifare->cardType.blks[i] + mifare->cardType.blk[i] - 1;
            if(ui->MF_dataWidget->item(targetBlock, 1)->checkState() == Qt::Checked)
                selectedTrailers++;
        }
        if(selectedBlocks == 0)
        {
            ui->MF_selectAllBox->setCheckState(Qt::Unchecked);
        }
        else if(selectedBlocks == mifare->cardType.block_size)
        {
            ui->MF_selectAllBox->setCheckState(Qt::Checked);
        }
        else
        {
            ui->MF_selectAllBox->setCheckState(Qt::PartiallyChecked);
        }
        if(selectedSubBlocks == 0)
        {
            ui->MF_dataWidget->item(mifare->cardType.blks[Mifare::data_b2s(item->row())], 0)->setCheckState(Qt::Unchecked);
        }
        else if(selectedSubBlocks == mifare->cardType.blk[Mifare::data_b2s(item->row())])
        {
            ui->MF_dataWidget->item(mifare->cardType.blks[Mifare::data_b2s(item->row())], 0)->setCheckState(Qt::Checked);
        }
        else
        {
            ui->MF_dataWidget->item(mifare->cardType.blks[Mifare::data_b2s(item->row())], 0)->setCheckState(Qt::PartiallyChecked);
        }
        if(selectedTrailers == 0)
        {
            ui->MF_selectTrailerBox->setCheckState(Qt::Unchecked);
        }
        else if(selectedTrailers == mifare->cardType.sector_size)
        {
            ui->MF_selectTrailerBox->setCheckState(Qt::Checked);
        }
        else
        {
            ui->MF_selectTrailerBox->setCheckState(Qt::PartiallyChecked);
        }
    }
    else if(item->column() == 2)
    {
        QString data = item->text().replace(" ", "").toUpper();
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
    ui->MF_dataWidget->blockSignals(false);
    ui->MF_selectAllBox->blockSignals(false);
    ui->MF_selectTrailerBox->blockSignals(false);
}

void MainWindow::on_MF_keyWidget_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 1)
    {
        QString key = item->text().replace(" ", "").toUpper();
        if(key == "" || mifare->data_isKeyValid(key))
        {
            mifare->data_setKey(item->row(), Mifare::KEY_A, key);
        }
        else
        {
            QMessageBox::information(this, tr("Info"), tr("Key must consists of 12 Hex symbols(Whitespace is allowed)"));
        }
        mifare->data_syncWithKeyWidget(false, item->row(), Mifare::KEY_A);
    }
    else if(item->column() == 2)
    {
        QString key = item->text().replace(" ", "").toUpper();
        if(key == "" || mifare->data_isKeyValid(key))
        {
            mifare->data_setKey(item->row(), Mifare::KEY_B, key);
        }
        else
        {
            QMessageBox::information(this, tr("Info"), tr("Key must consists of 12 Hex symbols(Whitespace is allowed)"));
        }
        mifare->data_syncWithKeyWidget(false, item->row(), Mifare::KEY_B);
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
        filename = QFileDialog::getOpenFileName(this, title, "./", tr("Binary Key Files(*.bin *.dump);;Binary Data Files(*.bin *.dump);;All Files(*.*)"));
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
    QString defaultName = mifare->data_getUID();
    if(defaultName != "")
        defaultName += "_";
    defaultName += QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");

    if(ui->MF_File_dataBox->isChecked())
    {
        title = tr("Plz select the location to save data file:");
        filename = QFileDialog::getSaveFileName(this, title, "./data_" + defaultName, tr("Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml)"), &selectedType);
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
        filename = QFileDialog::getSaveFileName(this, title, "./key_" + defaultName, tr("Binary Key Files(*.bin *.dump)"), &selectedType);
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
    setState(false);
    mifare->chk();
    setState(true);
}

void MainWindow::on_MF_Attack_nestedButton_clicked()
{
    setState(false);
    mifare->nested();
    setState(true);
}

void MainWindow::on_MF_Attack_hardnestedButton_clicked()
{
    mifare->hardnested();
}

void MainWindow::on_MF_RW_readSelectedButton_clicked()
{
    setState(false);
    mifare->readSelected(Mifare::TARGET_MIFARE);
    setState(true);
}

void MainWindow::on_MF_RW_readBlockButton_clicked()
{
    setState(false);
    mifare->readOne(Mifare::TARGET_MIFARE);
    setState(true);
}

void MainWindow::on_MF_RW_writeBlockButton_clicked()
{
    setState(false);
    mifare->writeOne();
    setState(true);
}

void MainWindow::on_MF_RW_writeSelectedButton_clicked()
{
    setState(false);
    mifare->writeSelected(Mifare::TARGET_MIFARE);
    setState(true);
}

void MainWindow::on_MF_RW_dumpButton_clicked()
{
    mifare->dump();
}

void MainWindow::on_MF_RW_restoreButton_clicked()
{
    mifare->restore();
}

void MainWindow::on_MF_UID_readSelectedButton_clicked()
{
    setState(false);
    mifare->readSelected(Mifare::TARGET_UID);
    setState(true);
}

void MainWindow::on_MF_UID_readBlockButton_clicked()
{
    setState(false);
    mifare->readOne(Mifare::TARGET_UID);
    setState(true);
}

void MainWindow::on_MF_UID_writeSelectedButton_clicked()
{
    setState(false);
    mifare->writeSelected(Mifare::TARGET_UID);
    setState(true);
}

void MainWindow::on_MF_UID_writeBlockButton_clicked()
{
    setState(false);
    mifare->writeOne(Mifare::TARGET_UID);
    setState(true);
}

void MainWindow::on_MF_UID_wipeButton_clicked()
{
    mifare->wipeC();
}

void MainWindow::on_MF_UID_aboutUIDButton_clicked()
{
    QString msg;
    msg += tr("    Normally, the Block 0 of a typical Mifare card, which contains the UID, is locked during the manufacture. Users cannot write anything to Block 0 or set a new UID to a normal Mifare card.") + "\n";
    msg += tr("    Chinese Magic Cards(aka UID Cards) are some special cards whose Block 0 are writeable. And you can change UID by writing to it.") + "\n";
    msg += "\n";
    msg += tr("There are two versions of Chinese Magic Cards, the Gen1 and the Gen2.") + "\n";
    msg += tr("    Gen1:") + "\n" + tr("    also called UID card in China. It responses to some backdoor commands so you can access any blocks without password. The Proxmark3 has a bunch of related commands(csetblk, cgetblk, ...) to deal with this type of card, and my GUI also support these commands.") + "\n";
    msg += tr("    Gen2:") + "\n" + tr("    doesn't response to the backdoor commands, which means that a reader cannot detect whether it is a Chinese Magic Card or not by sending backdoor commands.") + "\n";
    msg += "\n";
    msg += tr("There are some types of Chinese Magic Card Gen2.") + "\n";
    msg += tr("    CUID Card:") + "\n" + tr("    the Block 0 is writeable, you can write to this block repeatedly by normal wrbl command.") + "\n";
    msg += tr("    (hf mf wrbl 0 A FFFFFFFFFFFF <the data you want to write>)") + "\n";
    msg += tr("    FUID Card:") + "\n" + tr("    you can only write to Block 0 once. After that, it seems like a typical Mifare card(Block 0 cannot be written to).") + "\n";
    msg += tr("    (some readers might try changing the Block 0, which could detect the CUID Card. In that case, you should use FUID card.)") + "\n";
    msg += tr("    UFUID Card:") + "\n" + tr("    It behaves like a CUID card(or UID card? I'm not sure) before you send some special command to lock it. Once it is locked, you cannot change its Block 0(just like a typical Mifare card).") + "\n";
    msg += "\n";
    msg += tr("    Seemingly, these Chinese Magic Cards are more easily to be compromised by Nested Attack(it takes little time to get an unknown key).") + "\n";
    QMessageBox::information(this, tr("About UID Card"), msg);
}

void MainWindow::on_MF_UID_setParaButton_clicked()
{
    setState(false);
    mifare->setParameterC();
    setState(true);
}

void MainWindow::on_MF_UID_lockButton_clicked()
{
    mifare->lockC();
}

void MainWindow::on_MF_Sim_readSelectedButton_clicked()
{
    setState(false);
    mifare->readSelected(Mifare::TARGET_EMULATOR);
    setState(true);
}

void MainWindow::on_MF_Sim_writeSelectedButton_clicked()
{
    setState(false);
    mifare->writeSelected(Mifare::TARGET_EMULATOR);
    setState(true);
}

void MainWindow::on_MF_Sim_clearButton_clicked()
{
    mifare->wipeE();
}

void MainWindow::on_MF_Sim_simButton_clicked()
{
    mifare->simulate();
}

void MainWindow::on_MF_Sniff_loadButton_clicked() // use a tmp file to support complicated path
{
    QString title = "";
    QString filename = "";

    title = tr("Plz select the trace file:");
    filename = QFileDialog::getOpenFileName(this, title, clientWorkingDir->absolutePath(), tr("Trace Files(*.trc);;All Files(*.*)"));
    qDebug() << filename;
    if(filename != "")
    {
        QString tmpFile = "tmp" + QString::number(QDateTime::currentDateTime().toTime_t()) + ".trc";
        if(QFile::copy(filename, clientWorkingDir->absolutePath() + "/" + tmpFile))
        {
            mifare->loadSniff(tmpFile);
            util->delay(3000);
            QFile::remove(clientWorkingDir->absolutePath() + "/" + tmpFile);
        }
        else
        {
            QMessageBox::information(this, tr("Info"), tr("Failed to open") + "\n" + filename);
        }
    }
}

void MainWindow::on_MF_Sniff_saveButton_clicked()
{
    QString title = "";
    QString filename = "";

    title = tr("Plz select the location to save trace file:");
    filename = QFileDialog::getSaveFileName(this, title, clientWorkingDir->absolutePath(), tr("Trace Files(*.trc)"));
    qDebug() << filename;
    if(filename != "")
    {
        QString tmpFile = "tmp" + QString::number(QDateTime::currentDateTime().toTime_t()) + ".trc";
        mifare->saveSniff(tmpFile);
        for(int i = 0; i < 100; i++)
        {
            util->delay(100);
            if(QFile::exists(clientWorkingDir->absolutePath() + "/" + tmpFile))
                break;
        }
        if(!QFile::copy(clientWorkingDir->absolutePath() + "/" + tmpFile, filename))
        {
            QMessageBox::information(this, tr("Info"), tr("Failed to save to") + "\n" + filename);
        }
        QFile::remove(clientWorkingDir->absolutePath() + "/" + tmpFile);
    }

}

void MainWindow::on_MF_Sniff_sniffButton_clicked()
{
    setState(false);
    mifare->sniff();
    setState(true);
}

void MainWindow::on_MF_14aSniff_snoopButton_clicked()
{
    setState(false);
    mifare->sniff14a();
    setState(true);
}

void MainWindow::on_MF_Sniff_listButton_clicked()
{
    mifare->list();
}

void MainWindow::MF_widgetReset()
{
    int secs = mifare->cardType.sector_size;
    int blks = mifare->cardType.block_size;
    QBrush trailerItemForeColor = QBrush(QColor(0, 160, 255));
    ui->MF_RW_blockBox->clear();
    ui->MF_keyWidget->setRowCount(secs);
    ui->MF_dataWidget->setRowCount(blks);

    ui->MF_dataWidget->blockSignals(true);
    ui->MF_keyWidget->blockSignals(true);
    ui->MF_selectAllBox->blockSignals(true);
    ui->MF_selectTrailerBox->blockSignals(true);

    for(int i = 0; i < blks; i++)
    {
        setTableItem(ui->MF_dataWidget, i, 0, "");
        setTableItem(ui->MF_dataWidget, i, 1, QString::number(i));
        ui->MF_dataWidget->item(i, 1)->setCheckState(Qt::Checked);
        setTableItem(ui->MF_dataWidget, i, 2, "");
        ui->MF_RW_blockBox->addItem(QString::number(i));
    }

    for(int i = 0; i < secs; i++)
    {
        setTableItem(ui->MF_keyWidget, i, 0, QString::number(i));
        setTableItem(ui->MF_keyWidget, i, 1, "");
        setTableItem(ui->MF_keyWidget, i, 2, "");
        setTableItem(ui->MF_dataWidget, mifare->cardType.blks[i], 0, QString::number(i));
        ui->MF_dataWidget->item(mifare->cardType.blks[i] + mifare->cardType.blk[i] - 1, 2)->setForeground(trailerItemForeColor);
        ui->MF_dataWidget->item(mifare->cardType.blks[i], 0)->setCheckState(Qt::Checked);
    }
    ui->MF_dataWidget->item(0, 2)->setForeground(QBrush(QColor(255, 160, 0)));
    ui->MF_selectAllBox->setCheckState(Qt::Checked);
    ui->MF_selectTrailerBox->setCheckState(Qt::Checked);

    ui->MF_dataWidget->blockSignals(false);
    ui->MF_keyWidget->blockSignals(false);
    ui->MF_selectAllBox->blockSignals(false);
    ui->MF_selectTrailerBox->blockSignals(false);
}
// ************************************************


// ******************** other ********************

void MainWindow::uiInit()
{
    connect(ui->Raw_CMDEdit, &QLineEdit::returnPressed, this, &MainWindow::sendMSG);
    ui->Raw_CMDEdit->installEventFilter(keyEventFilter);
    connect(keyEventFilter, &MyEventFilter::eventHappened, this, &MainWindow::on_Raw_keyPressed);
    ui->MF_keyWidget->installEventFilter(resizeEventFilter);
    connect(resizeEventFilter, &MyEventFilter::eventHappened, this, &MainWindow::on_MF_keyWidget_resized);
    ui->Raw_outputEdit->installEventFilter(keyEventFilter);

    connectStatusBar = new QLabel(this);
    programStatusBar = new QLabel(this);
    PM3VersionBar = new QLabel(this);
    stopButton = new QPushButton(this);
    setStatusBar(connectStatusBar, tr("Not Connected"));
    setStatusBar(programStatusBar, tr("Idle"));
    setStatusBar(PM3VersionBar, "");
    stopButton->setText(tr("Stop"));
    ui->statusbar->addPermanentWidget(PM3VersionBar, 1);
    ui->statusbar->addPermanentWidget(connectStatusBar, 1);
    ui->statusbar->addPermanentWidget(programStatusBar, 1);
    ui->statusbar->addPermanentWidget(stopButton);

    ui->MF_dataWidget->setColumnWidth(0, 55);
    ui->MF_dataWidget->setColumnWidth(1, 55);

    ui->MF_keyWidget->setColumnWidth(0, 45);

    MF_widgetReset();
    MFCardTypeBtnGroup = new QButtonGroup(this);
    MFCardTypeBtnGroup->addButton(ui->MF_Type_miniButton, 0);
    MFCardTypeBtnGroup->addButton(ui->MF_Type_1kButton, 1);
    MFCardTypeBtnGroup->addButton(ui->MF_Type_2kButton, 2);
    MFCardTypeBtnGroup->addButton(ui->MF_Type_4kButton, 4);
    connect(MFCardTypeBtnGroup, QOverload<int, bool>::of(&QButtonGroup::buttonToggled), this, &MainWindow::MF_onMFCardTypeChanged);

    ui->MF_keyWidget->installEventFilter(this);
    ui->MF_dataWidget->installEventFilter(this);

    settings->beginGroup("UI_grpbox_preference");

    QStringList boxNames = settings->allKeys();
    QGroupBox * boxptr;
    foreach(QString name, boxNames)
    {
        boxptr = this->findChild<QGroupBox*>(name);
        if(boxptr == nullptr)
            continue;
        if(settings->value(name, true).toBool())
        {
            boxptr->setMaximumHeight(16777215);
            boxptr->setChecked(true);
        }
        else
        {
            boxptr->setMaximumHeight(20);
            boxptr->setChecked(false);
        }
    }
    settings->endGroup();

    settings->beginGroup("Client_Path");
    ui->PM3_pathEdit->setText(settings->value("path", "proxmark3").toString());
    settings->endGroup();

    settings->beginGroup("Client_Args");
    ui->Set_Client_startArgsEdit->setText(settings->value("args", "<port> -f").toString());
    settings->endGroup();

    settings->beginGroup("Client_forceButtonsEnabled");
    keepButtonsEnabled = settings->value("state", false).toBool();
    ui->Set_Client_forceEnabledBox->setChecked(keepButtonsEnabled);
    settings->endGroup();

    settings->beginGroup("Client_keepClientActive");
    keepClientActive = settings->value("state", false).toBool();
    ui->Set_Client_keepClientActiveBox->setChecked(keepClientActive);
    settings->endGroup();

    settings->beginGroup("Client_Env");
    ui->Set_Client_envScriptEdit->setText(settings->value("scriptPath").toString());
    ui->Set_Client_workingDirEdit->setText(settings->value("workingDir", "../data").toString());
    ui->Set_Client_configPathEdit->setText(settings->value("configPath", "config.json").toString());
    settings->endGroup();

    ui->MF_RW_keyTypeBox->addItem("A", Mifare::KEY_A);
    ui->MF_RW_keyTypeBox->addItem("B", Mifare::KEY_B);

    on_Raw_CMDHistoryBox_stateChanged(Qt::Unchecked);

}

void MainWindow::signalInit()
{
    connect(pm3, &PM3Process::newOutput, util, &Util::processOutput);
    connect(pm3, &PM3Process::changeClientType, util, &Util::setClientType);
    connect(util, &Util::refreshOutput, this, &MainWindow::refreshOutput);

    connect(this, &MainWindow::connectPM3, pm3, &PM3Process::connectPM3);
    connect(this, &MainWindow::reconnectPM3, pm3, &PM3Process::reconnectPM3);
    connect(pm3, &PM3Process::PM3StatedChanged, this, &MainWindow::onPM3StateChanged);
    connect(pm3, &PM3Process::PM3StatedChanged, util, &Util::setRunningState);
    connect(this, &MainWindow::killPM3, pm3, &PM3Process::killPM3);
    connect(this, &MainWindow::setProcEnv, pm3, &PM3Process::setProcEnv);
    connect(this, &MainWindow::setWorkingDir, pm3, &PM3Process::setWorkingDir);
    connect(this, QOverload<bool>::of(&MainWindow::setSerialListener), pm3, QOverload<bool>::of(&PM3Process::setSerialListener));
    connect(this, QOverload<const QString&, bool>::of(&MainWindow::setSerialListener), pm3, QOverload<const QString&, bool>::of(&PM3Process::setSerialListener));

    connect(util, &Util::write, pm3, &PM3Process::write);

    connect(ui->MF_typeGroupBox, &QGroupBox::clicked, this, &MainWindow::on_GroupBox_clicked);
    connect(ui->MF_fileGroupBox, &QGroupBox::clicked, this, &MainWindow::on_GroupBox_clicked);
    connect(ui->MF_RWGroupBox, &QGroupBox::clicked, this, &MainWindow::on_GroupBox_clicked);
    connect(ui->MF_normalGroupBox, &QGroupBox::clicked, this, &MainWindow::on_GroupBox_clicked);
    connect(ui->MF_UIDGroupBox, &QGroupBox::clicked, this, &MainWindow::on_GroupBox_clicked);
    connect(ui->MF_simGroupBox, &QGroupBox::clicked, this, &MainWindow::on_GroupBox_clicked);
    connect(ui->MF_sniffGroupBox, &QGroupBox::clicked, this, &MainWindow::on_GroupBox_clicked);

    connect(stopButton, &QPushButton::clicked, this, &MainWindow::on_stopButton_clicked);
}

void MainWindow::setStatusBar(QLabel * target, const QString& text)
{
    if(target == PM3VersionBar)
        target->setText(tr("HW Version:") + text);
    else if(target == connectStatusBar)
        target->setText(tr("PM3:") + text);
    else if(target == programStatusBar)
        target->setText(tr("State:") + text);
}

void MainWindow::setTableItem(QTableWidget * widget, int row, int column, const QString& text)
{
    if(widget->item(row, column) == nullptr)
        widget->setItem(row, column, new QTableWidgetItem());
    widget->item(row, column)->setText(text);
}

bool MainWindow::eventFilter(QObject * watched, QEvent * event) // drag support
{
    if(event->type() == QEvent::DragEnter)
    {
        QDragEnterEvent* dragEvent = static_cast<QDragEnterEvent*>(event);
        dragEvent->acceptProposedAction();
        return true;
    }
    else if(event->type() == QEvent::Drop)
    {
        QDropEvent* dropEvent = static_cast<QDropEvent*>(event);
        if(watched == ui->MF_keyWidget)
        {
            const QMimeData* mime = dropEvent->mimeData();
            if(mime->hasUrls())
            {
                QList<QUrl> urls = mime->urls();
                if(urls.length() == 1)
                {
                    mifare->data_loadKeyFile(urls[0].toLocalFile());
                    return true;
                }
            }
        }
        else if(watched == ui->MF_dataWidget)
        {
            const QMimeData* mime = dropEvent->mimeData();
            if(mime->hasUrls())
            {
                QList<QUrl> urls = mime->urls();
                if(urls.length() == 1)
                {
                    mifare->data_loadDataFile(urls[0].toLocalFile());
                    return true;
                }
            }
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::setState(bool st)
{
    if(!st && pm3state)
    {
        setStatusBar(programStatusBar, tr("Running"));
    }
    else
    {
        setStatusBar(programStatusBar, tr("Idle"));
    }
    setButtonsEnabled(st || keepButtonsEnabled);
}

void MainWindow::setButtonsEnabled(bool st)
{
    ui->MF_attackGroupBox->setEnabled(st);
    ui->MF_normalGroupBox->setEnabled(st);
    ui->MF_UIDGroupBox->setEnabled(st);
    ui->MF_simGroupBox->setEnabled(st);
    ui->MF_sniffGroupBox->setEnabled(st);
    ui->Raw_CMDEdit->setEnabled(st);
    ui->Raw_sendCMDButton->setEnabled(st);
    ui->LF_configGroupBox->setEnabled(st);
    ui->LF_operationGroupBox->setEnabled(st);
}

void MainWindow::on_GroupBox_clicked(bool checked)
{
    QGroupBox* box = dynamic_cast<QGroupBox*>(sender());

    settings->beginGroup("UI_grpbox_preference");
    if(checked)
    {
        box->setMaximumHeight(16777215);
        settings->setValue(box->objectName(), true);
    }
    else
    {
        box->setMaximumHeight(20);
        settings->setValue(box->objectName(), false);
    }
    settings->endGroup();
}

void MainWindow::saveClientPath(const QString& path)
{
    settings->beginGroup("Client_Path");
    settings->setValue("path", path);
    settings->endGroup();
}
// ***********************************************



void MainWindow::on_MF_Attack_darksideButton_clicked()
{
    setState(false);
    mifare->darkside();
    setState(true);
}

void MainWindow::on_Set_Client_startArgsEdit_editingFinished()
{
    settings->beginGroup("Client_Args");
    settings->setValue("args", ui->Set_Client_startArgsEdit->text());
    settings->endGroup();
}

void MainWindow::on_Set_Client_forceEnabledBox_stateChanged(int arg1)
{
    settings->beginGroup("Client_forceButtonsEnabled");
    keepButtonsEnabled = (arg1 == Qt::Checked);
    settings->setValue("state", keepButtonsEnabled);
    settings->endGroup();
    if(keepButtonsEnabled)
        setButtonsEnabled(true);
}

void MainWindow::on_Set_GUI_setLanguageButton_clicked()
{
    Util::chooseLanguage(settings, this);
}

void MainWindow::on_PM3_refreshPortButton_clicked()
{
    on_portSearchTimer_timeout();
}

void MainWindow::on_Set_Client_envScriptEdit_editingFinished()
{
    settings->beginGroup("Client_Env");
    settings->setValue("scriptPath", ui->Set_Client_envScriptEdit->text());
    settings->endGroup();
}

void MainWindow::on_Set_Client_workingDirEdit_editingFinished()
{
    settings->beginGroup("Client_Env");
    settings->setValue("workingDir", ui->Set_Client_workingDirEdit->text());
    settings->endGroup();
}


void MainWindow::on_Set_Client_configPathEdit_editingFinished()
{
    settings->beginGroup("Client_Env");
    settings->setValue("configPath", ui->Set_Client_configPathEdit->text());
    settings->endGroup();
}

void MainWindow::on_Set_Client_keepClientActiveBox_stateChanged(int arg1)
{
    settings->beginGroup("Client_keepClientActive");
    keepClientActive = (arg1 == Qt::Checked);
    settings->setValue("state", keepClientActive);
    settings->endGroup();
    emit setSerialListener(!keepClientActive);
}

void MainWindow::on_LF_Conf_freqSlider_valueChanged(int value)
{
    onLFfreqConfChanged(value, true);
}

void MainWindow::onLFfreqConfChanged(int value, bool isCustomized)
{
    ui->LF_Conf_freqDivisorBox->blockSignals(true);
    ui->LF_Conf_freqSlider->blockSignals(true);

    if(isCustomized)
        ui->LF_Conf_freqOtherButton->setChecked(true);
    ui->LF_Conf_freqLabel->setText(tr("Actural Freq: ") + QString("%1kHz").arg(LF::divisor2Freq(value), 0, 'f', 3));
    ui->LF_Conf_freqDivisorBox->setValue(value);
    ui->LF_Conf_freqSlider->setValue(value);

    ui->LF_Conf_freqDivisorBox->blockSignals(false);
    ui->LF_Conf_freqSlider->blockSignals(false);
}

void MainWindow::on_LF_Conf_freqDivisorBox_valueChanged(int arg1)
{
    onLFfreqConfChanged(arg1, true);
}

void MainWindow::on_LF_Conf_freq125kButton_clicked()
{
    onLFfreqConfChanged(95, false);
}

void MainWindow::on_LF_Conf_freq134kButton_clicked()
{
    onLFfreqConfChanged(88, false);
}

void MainWindow::on_LF_Op_searchButton_clicked()
{
    setState(false);
    lf->search();
    setState(true);
}

void MainWindow::on_LF_Op_readButton_clicked()
{
    setState(false);
    lf->read();
    setState(true);
}

void MainWindow::on_LF_Op_tuneButton_clicked()
{
    setState(false);
    lf->tune();
    setState(true);
}

void MainWindow::on_LF_Op_sniffButton_clicked()
{
    setState(false);
    lf->sniff();
    setState(true);
}

void MainWindow::dockInit()
{
    setDockNestingEnabled(true);
    QDockWidget* dock;
    QWidget* widget;
    int count = ui->funcTab->count();
    qDebug() << "dock count" << count;
    for(int i = 0; i < count; i++)
    {
        dock = new QDockWidget(ui->funcTab->tabText(0), this);
        qDebug() << "dock name" << ui->funcTab->tabText(0);
        dock->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);// movable is necessary, otherwise the dock cannot be dragged
        dock->setAllowedAreas(Qt::BottomDockWidgetArea);
        dock->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        widget = ui->funcTab->widget(0);
        dock->setWidget(widget);
        if(widget->objectName() == "rawTab")
            Util::setRawTab(dock, i);
        addDockWidget(Qt::BottomDockWidgetArea, dock);
        if(!dockList.isEmpty())
            tabifyDockWidget(dockList[0], dock);
        dockList.append(dock);
    }
    ui->funcTab->setVisible(false);
    dockList[0]->setVisible(true);
    dockList[0]->raise();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    contextMenu->exec(event->globalPos());
}

void MainWindow::on_LF_Conf_getButton_clicked()
{
    setState(false);
    lf->getConfig();
    setState(true);
}

void MainWindow::on_LF_Conf_setButton_clicked()
{
    LF::Config config;
    setState(false);
    config.divisor = ui->LF_Conf_freqDivisorBox->value();
    config.bitPerSample = ui->LF_Conf_bitPerSampleBox->value();
    config.decimation = ui->LF_Conf_decimationBox->value();
    config.averaging = ui->LF_Conf_averagingBox->isChecked();
    config.triggerThreshold = ui->LF_Conf_thresholdBox->value();
    config.samplesToSkip = ui->LF_Conf_skipsBox->value();
    lf->setConfig(config);
    Util::gotoRawTab();
    setState(true);
}

void MainWindow::on_LF_Conf_resetButton_clicked()
{
    setState(false);
    lf->resetConfig();
    setState(true);
}

