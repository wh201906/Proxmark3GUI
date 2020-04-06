#include "pm3process.h"

PM3Process::PM3Process(QObject* parent): QProcess(parent)
{

}

bool PM3Process::init(const QString path, const QString port)
{
    bool success=true;
    this->start(path, QStringList(port));
    qDebug()<<waitForStarted();
    qDebug()<<waitForReadyRead(3000);
        return true;
}
