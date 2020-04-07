#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>
#include "pm3process.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void refresh();
private slots:
    void on_connectButton_clicked();

    void on_sendButton_clicked();

    void on_disconnectButton_clicked();

    void on_clearButton_clicked();

    void sendMSG();
private:
    Ui::MainWindow *ui;
    PM3Process* pm3;
    QStandardItemModel* dataModel;
    QStandardItemModel* keyModel;
};
#endif // MAINWINDOW_H
