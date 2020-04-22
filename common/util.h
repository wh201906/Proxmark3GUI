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
    explicit Util(QObject *parent = nullptr);

    void execCMD(QString cmd);
    QString execCMDWithOutput(QString cmd, unsigned long timeout=2000);
    void delay(unsigned int msec);
public slots:
    void processOutput(QString output);

private:
    bool isRequiringOutput;
    QString* requiredOutput;
    QTime timeStamp;
signals:
    void refreshOutput(const QString& output);
    void write(QString data);
};

#endif // UTIL_H
