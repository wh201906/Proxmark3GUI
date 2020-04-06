#ifndef PM3PROCESS_H
#define PM3PROCESS_H

#include <QProcess>
#include <QString>
#include <QDebug>

class PM3Process : public QProcess
{
    Q_OBJECT
public:
    explicit PM3Process(QObject* parent=nullptr);
    bool init(const QString path, const QString port);
};

#endif // PM3PROCESS_H
