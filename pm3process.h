#ifndef PM3PROCESS_H
#define PM3PROCESS_H

#include <QProcess>
#include <QString>
#include <QDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

class PM3Process : public QProcess
{
    Q_OBJECT
public:
    explicit PM3Process(QObject* parent=nullptr);
    bool start(const QString path, const QString port);
    QStringList findPort();
};

#endif // PM3PROCESS_H
