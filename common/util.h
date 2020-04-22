#ifndef UTIL_H
#define UTIL_H

#include <QObject>

class Util : public QObject
{
    Q_OBJECT
public:
    explicit Util(QObject *parent = nullptr);

signals:

private slots:
    void processOutput();
};

#endif // UTIL_H
