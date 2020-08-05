#include "util.h"

Util::Util(QObject *parent) : QObject(parent)
{
    isRequiringOutput = false;
    requiredOutput = new QString();
    timeStamp = QTime::currentTime();
    this->clientType = CLIENTTYPE_OFFICIAL;
    qRegisterMetaType<Util::ClientType>("Util::ClientType");
}

void Util::processOutput(QString output)
{
//    qDebug() << "Util::processOutput:" << output;
    if(isRequiringOutput)
    {
        requiredOutput->append(output);
        timeStamp = QTime::currentTime();
    }
    emit refreshOutput(output);
}

void Util::execCMD(QString cmd)
{
    qDebug() << cmd;
    emit write(cmd + "\r\n");
}

QString Util::execCMDWithOutput(QString cmd, unsigned long timeout)
{
    QTime currTime = QTime::currentTime();
    QTime targetTime = QTime::currentTime().addMSecs(timeout);
    isRequiringOutput = true;
    requiredOutput->clear();
    execCMD(cmd);
    while(QTime::currentTime() < targetTime)
    {
        QApplication::processEvents();
        if(timeStamp > currTime)
        {
            currTime = timeStamp;
            targetTime = timeStamp.addMSecs(timeout);
        }
    }
    isRequiringOutput = false;
    return *requiredOutput;
}

void Util::delay(unsigned int msec)
{
    QTime timer = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < timer)
        QApplication::processEvents(QEventLoop::AllEvents, 100);
}
Util::ClientType Util::getClientType()
{
    return this->clientType;
}

void Util::setClientType(Util::ClientType clientType)
{
    this->clientType = clientType;
}
