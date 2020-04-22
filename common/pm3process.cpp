#include "pm3process.h"

PM3Process::PM3Process(QThread* thread, QObject* parent): QProcess(parent)
{
    moveToThread(thread);
    setProcessChannelMode(PM3Process::MergedChannels);
    isRequiringOutput=false;
    requiredOutput=new QString();
    serialListener=new QTimer(); // if using new QTimer(this), the debug output will show "Cannot create children for a parent that is in a different thread."
    serialListener->moveToThread(this->thread());// I've tried many ways to creat a QTimer instance, but all of the instances are in the main thread(UI thread), so I have to move it manually
    serialListener->setInterval(1000);
    serialListener->setTimerType(Qt::VeryCoarseTimer);
    connect(serialListener,&QTimer::timeout,this,&PM3Process::onTimeout);
    connect(this,&PM3Process::readyRead,this,&PM3Process::onReadyRead);
}

void PM3Process::connectPM3(const QString path, const QString port)
{
    setRequiringOutput(true);

    // using "-f" option to make the client output flushed after every print.
    start(path, QStringList()<<port<<"-f",QProcess::Unbuffered|QProcess::ReadWrite);
    if(waitForStarted(10000))
    {
        while(waitForReadyRead(1000))
            ;
        setRequiringOutput(false);
        QString result = *requiredOutput;
        if(result.indexOf("os: ")!=-1)// make sure the PM3 is connected
        {
            result = result.mid(result.indexOf("os: "));
            result = result.left(result.indexOf("\r\n"));
            result = result.mid(3, result.lastIndexOf(" ") - 3);
            emit PM3StatedChanged(true,result);
            setSerialListener(port,true);
        }
        else
            kill();
    }
}

void PM3Process::setRequiringOutput(bool st)
{
    isRequiringOutput=st;
    if(isRequiringOutput)
        requiredOutput->clear();
}

bool PM3Process::waitForReadyRead(int msecs)
{
    return QProcess::waitForReadyRead(msecs);
}

void PM3Process::setSerialListener(const QString& name,bool state)
{
    if(state)
    {
        portInfo=new QSerialPortInfo(name);
        serialListener->start();
        qDebug()<<serialListener->thread();
    }
    else
    {
        serialListener->stop();
        delete portInfo;
    }
}

void PM3Process::onTimeout() //when the proxmark3 client is unexpectedly terminated or the PM3 hardware is removed, the isBusy() will return false(only tested on Windows);
{
    qDebug()<<portInfo->isBusy();
    if(!portInfo->isBusy())
    {
        kill();
        emit PM3StatedChanged(false);
        setSerialListener("",false);
    }
}

void PM3Process::testThread()
{
    qDebug()<<"PM3:"<<QThread::currentThread();
}


qint64 PM3Process::write(QString data)
{
    return QProcess::write(data.toLatin1());
}

void PM3Process::onReadyRead()
{
    QString out = readAll();
    if(isRequiringOutput)
        requiredOutput->append(out);
    if(out != "")
    {
        qDebug()<<"PM3Process::onReadyRead:" << out;
        emit newOutput(out);

    }
}
