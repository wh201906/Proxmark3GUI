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
    qDebug() << "executing: " << cmd;
    if(isRunning)
        emit write(cmd + "\r\n");
}

QString Util::execCMDWithOutput(const QString& cmd, ReturnTrigger trigger)
{
    // if the trigger is empty, this function will wait trigger.waitTime then return all outputs during the wait time.
    // otherwise, this function will return empty string if no trigger is detected, or return outputs if any trigger is detected.
    // the waitTime will be refreshed if the client have new outputs
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
        if(!isRunning)
            break;
        QApplication::processEvents();
        for(QString otpt : trigger.expectedOutputs)
        {
            re.setPattern(otpt);
            isResultFound = re.match(*requiredOutput).hasMatch();
            if(isResultFound)
            {
                qDebug() << "output Matched: " << *requiredOutput;
                break;
            }
        }
        if(isResultFound)
        {
            delay(200);
            break;
        }
        if(timeStamp > currTime) //has new output
        {
            currTime = timeStamp;
            targetTime = timeStamp.addMSecs(trigger.waitTime);
        }
    }
    isRequiringOutput = false;
    return (isResultFound || trigger.expectedOutputs.isEmpty() ? *requiredOutput : "");
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
