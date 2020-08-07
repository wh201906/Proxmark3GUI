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
#include <QFileDialog>
#include <QFontDialog>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QMimeData>
#include <QAction>
#include <QDesktopServices>
#include <QGroupBox>
#include <QSizePolicy>
#include <QSettings>

#include "common/pm3process.h"
#include "module/mifare.h"
#include "common/util.h"
#include "ui/mf_trailerdecoderdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUI();
    bool eventFilter(QObject *watched, QEvent *event);
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

    void on_MF_Sniff_sniffButton_clicked();

    void on_MF_Sniff_listButton_clicked();

    void on_MF_RW_readSelectedButton_clicked();

    void on_MF_RW_readBlockButton_clicked();

    void on_MF_RW_writeBlockButton_clicked();

    void on_MF_Attack_infoButton_clicked();

    void on_MF_RW_writeSelectedButton_clicked();


    void on_MF_RW_dumpButton_clicked();

    void on_MF_RW_restoreButton_clicked();

    void on_MF_UID_readAllButton_clicked();

    void on_MF_UID_readBlockButton_clicked();

    void on_MF_UID_writeAllButton_clicked();

    void on_MF_UID_writeBlockButton_clicked();

    void on_MF_File_loadButton_clicked();

    void on_MF_File_saveButton_clicked();

    void on_MF_data2KeyButton_clicked();

    void on_MF_key2DataButton_clicked();

    void on_MF_dataWidget_itemChanged(QTableWidgetItem *item);

    void on_MF_File_clearButton_clicked();

    void on_MF_keyWidget_itemChanged(QTableWidgetItem *item);

    void on_MF_fontButton_clicked();

    void on_MF_UID_wipeButton_clicked();

    void on_MF_UID_aboutUIDButton_clicked();

    void on_MF_UID_setParaButton_clicked();

    void on_MF_UID_lockButton_clicked();

    void on_MF_Sim_loadDataButton_clicked();

    void on_MF_Sim_writeAllButton_clicked();

    void on_MF_Sim_clearButton_clicked();

    void on_MF_Sim_simButton_clicked();

    void on_MF_Sniff_loadButton_clicked();

    void on_MF_Sniff_saveButton_clicked();

    void on_GroupBox_clicked(bool checked);

    void on_MF_selectAllBox_stateChanged(int arg1);

    void on_MF_fillKeysButton_clicked();

    void on_MF_Sniff_snoopButton_clicked();

    void on_testButton_clicked();

    void on_MF_trailerDecoderButton_clicked();

private:
    Ui::MainWindow* ui;
    QButtonGroup* typeBtnGroup;
    QLabel* connectStatusBar;
    QLabel* programStatusBar;
    QLabel* PM3VersionBar;
    QAction* myInfo;
    QSettings* settings;

    void uiInit();

    PM3Process* pm3;
    bool pm3state;
    QThread* pm3Thread;

    Mifare* mifare;
    Util* util;

    MF_trailerDecoderDialog* decDialog;


    void signalInit();
    void MF_widgetReset();
    void setTableItem(QTableWidget *widget, int row, int column, const QString &text);
    void setState(bool st);
    void saveClientPath(const QString &path);
signals:
    void connectPM3(const QString path, const QString port);
    void killPM3();
    void setSerialListener(const QString &name, bool state);
};
#endif // MAINWINDOW_H
