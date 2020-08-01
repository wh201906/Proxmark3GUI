#ifndef UTIL_H
#define UTIL_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QApplication>
#include <QTime>
#include <QTimer>

class Util : public QObject
{
    Q_OBJECT
public:
    enum ClientType
    {
        OFFICIAL,
        ICEMAN,
    };
    explicit Util(Util::ClientType clientType, QObject *parent = nullptr);

    void execCMD(QString cmd);
    QString execCMDWithOutput(QString cmd, unsigned long timeout = 2000);
    void delay(unsigned int msec);
    ClientType getClientType();
public slots:
    void processOutput(QString output);

private:
    bool isRequiringOutput;
    QString* requiredOutput;
    QTime timeStamp;
signals:
    void refreshOutput(const QString& output);
    void write(QString data);
    ClientType clientType;
};

#endif // UTIL_H
