#ifndef UTIL_H
#define UTIL_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QApplication>
#include <QTime>
#include <QTimer>
#include <QMetaType>
#include <QRegularExpression>
#include <QSettings>
#include <QMainWindow>
#include <QInputDialog>
#include <QDockWidget>

#include "ui_mainwindow.h"

class Util : public QObject
{
    Q_OBJECT
public:
    enum ClientType
    {
        CLIENTTYPE_OFFICIAL,
        CLIENTTYPE_ICEMAN,
    };

    struct ReturnTrigger
    {
        unsigned long waitTime;
        QStringList expectedOutputs;
        ReturnTrigger(unsigned long time)
        {
            waitTime = time;
            expectedOutputs = QStringList();
        }
        ReturnTrigger(const QStringList& outputs)
        {
            waitTime = 10000;
            expectedOutputs = outputs;
        }
        ReturnTrigger(unsigned long time, const QStringList& outputs)
        {
            waitTime = time;
            expectedOutputs = outputs;
        }
    };

    Q_ENUM(Util::ClientType)

    explicit Util(QObject *parent = nullptr);

    void execCMD(const QString& cmd);
    QString execCMDWithOutput(const QString& cmd, ReturnTrigger trigger = 10000);
    void delay(unsigned int msec);
    static ClientType getClientType();
    static int rawTabIndex;
    static QDockWidget* rawDockPtr;
    static bool chooseLanguage(QSettings *guiSettings, QMainWindow *window);
public slots:
    void processOutput(const QString& output);
    static void setClientType(Util::ClientType clientType);
    void setRunningState(bool st);
    static void gotoRawTab();
    static void setUI(Ui::MainWindow *ui);
    static void setRawTab(QDockWidget* dockPtr, int tabIndex);
private:
    bool isRequiringOutput;
    bool isRunning;
    QString* requiredOutput;
    QTime timeStamp;
    static ClientType clientType;
    static Ui::MainWindow *ui;
signals:
    void refreshOutput(const QString& output);
    void write(QString data); // connected to PM3Process::write(QString data);
};

#endif // UTIL_H
