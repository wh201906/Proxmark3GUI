#ifndef PM3PROCESS_H
#define PM3PROCESS_H

#include <QProcess>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

class PM3Process : public QProcess
{
    Q_OBJECT
public:
    explicit PM3Process(QThread* thread, QObject* parent=nullptr);
    bool waitForReadyRead(int msecs = 2000);

    void testThread();

public slots:
    void connectPM3(const QString path, const QString port);
    void setSerialListener(const QString &name, bool state);
    qint64 write(QString data);
private slots:
    void onTimeout();
    void onReadyRead();
private:
    bool isRequiringOutput;
    QString* requiredOutput; // It only works in this class now
    void setRequiringOutput(bool st);// It only works in this class now
    QTimer* serialListener;
    QSerialPortInfo* portInfo;
signals:
    void PM3StatedChanged(bool st, QString info="");
    void newOutput(QString output);
};

#endif // PM3PROCESS_H
