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

float QWorldActionEvent::getChance(QWorldActionEvents e)
{
    int countEvent = 0;

    for (std::vector<QWorldActionEvents>::iterator i = events.begin(); i != events.end(); ++i) {
        if (*i == e)
            ++countEvent;
    }

    return countEvent * 100 / float(events.size());
}
