#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pm3=new PM3Process;
    connect(pm3,&PM3Process::readyRead,this,&MainWindow::refresh);
    connect(ui->commandEdit,&QLineEdit::editingFinished,this,&MainWindow::sendMSG);
    ui->portBox->addItem("");
    foreach(QString port,pm3->findPort())
    {
        ui->portBox->addItem(port);
    }
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
    qDebug()<<(ui->commandEdit->text().toLocal8Bit());
    pm3->write((ui->commandEdit->text()+"\r\n").toLocal8Bit());
    pm3->waitForBytesWritten(3000);
}

void MainWindow::refresh()
{
    QByteArray btay=pm3->readLine();
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
