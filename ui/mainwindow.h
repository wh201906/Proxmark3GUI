#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QButtonGroup>
#include <QRadioButton>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

#include "common/pm3process.h"
#include "module/mifare.h"
#include "common/util.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void refreshOutput(const QString &output);
    void refreshCMD(const QString &cmd);
    void setStatusBar(QLabel* target, const QString & text);
    void onPM3StateChanged(bool st, QString info);
    void MF_onTypeChanged(int id, bool st);
private slots:

    void on_PM3_connectButton_clicked();

    void on_Raw_sendCMDButton_clicked();

    void on_PM3_disconnectButton_clicked();

    void on_Raw_clearOutputButton_clicked();

    void sendMSG();
    void on_PM3_refreshPortButton_clicked();

    void on_Raw_CMDHistoryBox_stateChanged(int arg1);

    void on_Raw_clearHistoryButton_clicked();

    void on_Raw_CMDHistoryWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_MF_Attack_chkButton_clicked();

    void on_MF_Attack_nestedButton_clicked();

    void on_MF_Attack_hardnestedButton_clicked();

    void on_MF_Attack_sniffButton_clicked();

    void on_MF_Attack_listButton_clicked();

    void on_MF_RW_readAllButton_clicked();

    void on_MF_RW_readBlockButton_clicked();

    void on_MF_RW_writeBlockButton_clicked();

    void on_MF_Attack_infoButton_clicked();

    void on_MF_RW_writeAllButton_clicked();


    void on_MF_RW_dumpButton_clicked();

    void on_MF_RW_restoreButton_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup* typeBtnGroup;
    QLabel* connectStatusBar;
    QLabel* programStatusBar;
    QLabel* PM3VersionBar;
    void uiInit();

    PM3Process* pm3;
    bool pm3state;
    QThread* pm3Thread;

    Mifare* mifare;
    Util* util;


    void signalInit();
    void MF_widgetReset();
    void setTableItem(QTableWidget *widget, int row, int column, const QString &text);
signals:
    void connectPM3(const QString path, const QString port);
    void killPM3();
    void setSerialListener(const QString &name, bool state);
};
#endif // MAINWINDOW_H
