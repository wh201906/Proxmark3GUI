#include "myeventfilter.h"

MyEventFilter::MyEventFilter(QEvent::Type filter)
{
    targetEventType = filter;
}

bool MyEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == targetEventType)
        emit eventHappened(obj, *event);
    return QObject::eventFilter(obj, event);
}
