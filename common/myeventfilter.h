#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QObject>
#include <QKeyEvent>

class MyEventFilter : public QObject
{
    Q_OBJECT

public:
    explicit MyEventFilter(QEvent::Type filter);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void eventHappened(QObject* obj_addr, QEvent& event);
private:
    QEvent::Type targetEventType;
};

#endif // MYEVENTFILTER_H
