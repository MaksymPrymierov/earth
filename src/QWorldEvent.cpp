#include "headers/QWorldEvent.h"
#include <cstdlib>

QWorldActionEvent::QWorldActionEvent() :
    currentEvent(QWorldActionEvents::NoEvents)
{
    events.push_back(QWorldActionEvents::NoEvents);
}

void QWorldActionEvent::changeEvent()
{
    currentEvent = events[size_t(rand() % int(events.size() + 1))];
    events.clear();
    events.push_back(QWorldActionEvents::NoEvents);
}

QWorldActionEvents QWorldActionEvent::get() const
{
    return currentEvent;
}

void QWorldActionEvent::set(QWorldActionEvents e)
{
    events.push_back(e);
}
