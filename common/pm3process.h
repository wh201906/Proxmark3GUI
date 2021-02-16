#ifndef PM3PROCESS_H
#define PM3PROCESS_H

#include <QProcess>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QProcessEnvironment>
#include <QDir>

#include "util.h"

class PM3Process : public QProcess
{
    Q_OBJECT
public:
    explicit PM3Process(QThread* thread, QObject* parent = nullptr);
    bool waitForReadyRead(int msecs = 2000);

    void testThread();

public slots:
    void connectPM3(const QString& path, const QString& port, const QStringList args);
    void setSerialListener(const QString& name, bool state);
    qint64 write(QString data);
    void reconnectPM3();
    void setProcEnv(const QStringList* env);
    void setWorkingDir(const QString& dir);
private slots:
    void onTimeout();
    void onReadyRead();
private:
    bool isRequiringOutput;
    QString* requiredOutput; // It only works in this class now
    void setRequiringOutput(bool st);// It only works in this class now
    QTimer* serialListener;
    QSerialPortInfo* portInfo;
    QString currPath;
    QString currPort;
    QStringList currArgs;

signals:
    void PM3StatedChanged(bool st, const QString& info = "");
    void newOutput(const QString& output);
    void changeClientType(Util::ClientType);
};

#endif // PM3PROCESS_H
