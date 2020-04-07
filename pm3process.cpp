#include "pm3process.h"

PM3Process::PM3Process(QObject* parent): QProcess(parent)
{
    setProcessChannelMode(PM3Process::MergedChannels);
}

QStringList PM3Process::findPort()
{
    QSerialPort serial;
    QStringList retList;
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            retList<<info.portName();
            serial.close();
        }
    }
    return retList;
}

bool PM3Process::start(const QString path, const QString port)
{
    // using "-f" option to make the client output flushed after every print.
    QProcess::start(path, QStringList()<<port<<"-f",QProcess::Unbuffered|QProcess::ReadWrite);
    return waitForStarted();
}
