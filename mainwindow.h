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
    void setStatusBar(QLabel* target,const QString & text);
private slots:

    void on_PM3_connectButton_clicked();

    void on_Raw_sendCMDButton_clicked();

    void on_PM3_disconnectButton_clicked();

    void on_Raw_clearOutputButton_clicked();

    void sendMSG();
    void on_PM3_refreshPortButton_clicked();

    void on_Raw_moreFuncCheckBox_stateChanged(int arg1);

    void on_Raw_clearHistoryButton_clicked();

    void on_Raw_CMDHistoryWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_MF_Attack_chkButton_clicked();

    void on_MF_Attack_nestedButton_clicked();

    void on_MF_Attack_hardnestedButton_clicked();

    void on_MF_Attack_sniffButton_clicked();

    void on_MF_Attack_listButton_clicked();

private:
    Ui::MainWindow *ui;
    PM3Process* pm3;
    Mifare* mifare;
    void uiInit();
    QLabel* connectStatusBar;
    QLabel* programStatusBar;
    QLabel* PM3VersionBar;
};
#endif // MAINWINDOW_H
