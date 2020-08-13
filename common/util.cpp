#include "util.h"

Util::Util(QObject *parent) : QObject(parent)
{
    isRequiringOutput = false;
    requiredOutput = new QString();
    timeStamp = QTime::currentTime();
    this->clientType = CLIENTTYPE_OFFICIAL;
    qRegisterMetaType<Util::ClientType>("Util::ClientType");
}

void Util::processOutput(const QString& output)
{
//    qDebug() << "Util::processOutput:" << output;
    if(isRequiringOutput)
    {
        requiredOutput->append(output);
        timeStamp = QTime::currentTime();
    }
    emit refreshOutput(output);
}

void Util::execCMD(const QString& cmd)
{
    qDebug() << cmd;
    if(isRunning)
        emit write(cmd + "\r\n");
}

QString Util::execCMDWithOutput(const QString& cmd, ReturnTrigger trigger)
{
    bool isResultFound = false;
    QRegularExpression re;
    re.setPatternOptions(QRegularExpression::DotMatchesEverythingOption);

    if(!isRunning)
        return "";
    QTime currTime = QTime::currentTime();
    QTime targetTime = QTime::currentTime().addMSecs(trigger.waitTime);
    isRequiringOutput = true;
    requiredOutput->clear();
    execCMD(cmd);
    while(QTime::currentTime() < targetTime)
    {
        QApplication::processEvents();
        for(QString otpt : trigger.expectedOutputs)
        {
            re.setPattern(otpt);
            isResultFound = re.match(*requiredOutput).hasMatch();
            if(requiredOutput->contains(otpt))
                break;
        }
        if(isResultFound)
        {
            delay(200);
            break;
        }
        if(timeStamp > currTime)
        {
            currTime = timeStamp;
            targetTime = timeStamp.addMSecs(trigger.waitTime);
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

void Util::setRunningState(bool st)
{
    this->isRunning = st;
}
