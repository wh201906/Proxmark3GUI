#include "mainwindow.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pm3=new PM3Process;
    mifare=new Mifare;
    connect(pm3,&PM3Process::readyRead,this,&MainWindow::refresh);
    connect(ui->commandEdit,&QLineEdit::editingFinished,this,&MainWindow::sendMSG);
    uiInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectButton_clicked()
{
    QString port=ui->portBox->currentText();
    if(port=="")
        QMessageBox::information(NULL, "Info", "Plz choose a port first", QMessageBox::Ok);
    else
        qDebug()<<pm3->start(ui->PM3PathEdit->text(),port);
}

void MainWindow::on_sendButton_clicked()
{
    if(ui->CMDHistoryWidget->count()==0 || ui->CMDHistoryWidget->item(ui->CMDHistoryWidget->count()-1)->text()!=ui->commandEdit->text())
        ui->CMDHistoryWidget->addItem(ui->commandEdit->text());
    qDebug()<<(ui->commandEdit->text().toLocal8Bit());
    pm3->write((ui->commandEdit->text()+"\r\n").toLocal8Bit());
    pm3->waitForBytesWritten(3000);
}

void MainWindow::refresh()
{
    QString btay=pm3->readLine();
    while(btay!="")
    {
        qDebug()<<btay;
        ui->outputEdit->insertPlainText(btay);
        btay=pm3->readLine();
    }
    ui->outputEdit->moveCursor(QTextCursor::End);
}

void MainWindow::sendMSG()
{
    if(ui->commandEdit->hasFocus())
        on_sendButton_clicked();
}

void MainWindow::on_disconnectButton_clicked()
{
    pm3->kill();
}

void MainWindow::on_clearButton_clicked()
{
    ui->outputEdit->clear();
}

void MainWindow::on_portButton_clicked()
{
    ui->portBox->clear();
    ui->portBox->addItem("");
    foreach(QString port,pm3->findPort())
    {
        ui->portBox->addItem(port);
    }
}

void MainWindow::on_moreFuncCheckBox_stateChanged(int arg1)
{
    if(ui->moreFuncCheckBox->isChecked())
    {
        ui->CMDTreeWidget->setVisible(true);
        ui->CMDTreeLabel->setVisible(true);
        ui->CMDHistoryWidget->setVisible(true);
        ui->CMDHistoryLabel->setVisible(true);
        ui->clearHistoryButton->setVisible(true);
    }
    else
    {
        ui->CMDTreeWidget->setVisible(false);
        ui->CMDTreeLabel->setVisible(false);
        ui->CMDHistoryWidget->setVisible(false);
        ui->CMDHistoryLabel->setVisible(false);
        ui->clearHistoryButton->setVisible(false);
    }
}

void MainWindow::on_clearHistoryButton_clicked()
{
    ui->CMDHistoryWidget->clear();
}

void MainWindow::on_CMDHistoryWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->commandEdit->setText(item->text());
    ui->commandEdit->setFocus();
}

void MainWindow::uiInit()
{
    ui->MFDataWidget->setColumnCount(3);
    ui->MFDataWidget->setRowCount(64);
    ui->MFDataWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Sector"));
    ui->MFDataWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Block"));
    ui->MFDataWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Data"));
    for(int i=0;i<64;i++)
        ui->MFDataWidget->setItem(i,1,new QTableWidgetItem(QString::number(i)));
    for(int i=0;i<16;i++)
        ui->MFDataWidget->setItem(i*4,0,new QTableWidgetItem(QString::number(i)));
    ui->MFDataWidget->verticalHeader()->setVisible(false);
    ui->MFDataWidget->setColumnWidth(0,50);
    ui->MFDataWidget->setColumnWidth(1,40);
    ui->MFDataWidget->setColumnWidth(2,400);

    ui->MFKeyWidget->setColumnCount(3);
    ui->MFKeyWidget->setRowCount(16);
    ui->MFKeyWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Sector"));
    ui->MFKeyWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("KeyA"));
    ui->MFKeyWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("KeyB"));
    for(int i=0;i<16;i++)
        ui->MFKeyWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
    ui->MFKeyWidget->verticalHeader()->setVisible(false);
    ui->MFKeyWidget->setColumnWidth(0,50);
    ui->MFKeyWidget->setColumnWidth(1,200);
    ui->MFKeyWidget->setColumnWidth(2,200);

    on_moreFuncCheckBox_stateChanged(0);
    on_portButton_clicked();
}
