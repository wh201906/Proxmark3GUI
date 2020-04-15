#include "pm3process.h"

PM3Process::PM3Process(QObject* parent): QProcess(parent)
{
    setProcessChannelMode(PM3Process::MergedChannels);
    isRequiringOutput=false;
    requiredOutput=new QString();
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

void PM3Process::setRequiringOutput(bool st)
{
    isRequiringOutput=st;
    if(isRequiringOutput)
        requiredOutput->clear();
}
QByteArray PM3Process::readLine(qint64 maxlen)
{
    QByteArray buff;
    buff=QProcess::readLine(maxlen);
    if(isRequiringOutput)
        requiredOutput->append(buff);
    return buff;
}
QString PM3Process::getRequiredOutput()
{
    return *requiredOutput;
}

bool PM3Process::waitForReadyRead(int msecs)
{
    return QProcess::waitForReadyRead(msecs);
}

