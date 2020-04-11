#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>
#include "pm3process.h"
#include "mifare.h"

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
    void on_portButton_clicked();

    void on_moreFuncCheckBox_stateChanged(int arg1);

    void on_clearHistoryButton_clicked();

    void on_CMDHistoryWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_MFChkButton_clicked();

private:
    Ui::MainWindow *ui;
    PM3Process* pm3;
    Mifare* mifare;
    void uiInit();
};
#endif // MAINWINDOW_H
