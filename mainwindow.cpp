#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pm3=new PM3Process;
    connect(pm3,PM3Process::readyReadStandardError,this,MainWindow::on_pushButton_3_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<pm3->init("E:/Documents/source/qt/pm3/win64/proxmark3.exe","COM4");
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<ui->plainTextEdit_2->toPlainText().toLocal8Bit();
    pm3->write(ui->plainTextEdit_2->toPlainText().toLocal8Bit());
    pm3->waitForBytesWritten(3000);
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray btay=pm3->readAllStandardOutput();
    qDebug()<<btay;
    ui->plainTextEdit->appendPlainText(btay);
}
