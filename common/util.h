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
        ReturnTrigger(QStringList outputs)
        {
            waitTime = 10000;
            expectedOutputs = outputs;
        }
        ReturnTrigger(unsigned long time, QStringList outputs)
        {
            waitTime = time;
            expectedOutputs = outputs;
        }
    };

    Q_ENUM(Util::ClientType)

    explicit Util(QObject *parent = nullptr);

    void execCMD(QString cmd);
    QString execCMDWithOutput(QString cmd, ReturnTrigger trigger = 10000);
    void delay(unsigned int msec);
    ClientType getClientType();
public slots:
    void processOutput(QString output);
    void setClientType(Util::ClientType clientType);
    void setRunningState(bool st);

private:
    bool isRequiringOutput;
    bool isRunning;
    QString* requiredOutput;
    QTime timeStamp;
    ClientType clientType;
signals:
    void refreshOutput(const QString& output);
    void write(QString data);
};

#endif // UTIL_H
