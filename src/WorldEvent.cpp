#include "headers/WorldEvent.h"
#include <cstdlib>

WorldEvent::WorldEvent() :
    currentEvent(WorldEvents::NoEvents)
{
    events.push_back(WorldEvents::NoEvents);
}

void WorldEvent::changeEvent()
{
    currentEvent = events[size_t(rand() % int(events.size() + 1))];
    events.clear();
    events.push_back(WorldEvents::NoEvents);
}

WorldEvents WorldEvent::get() const
{
    return currentEvent;
}

void WorldEvent::set(WorldEvents e)
{
    events.push_back(e);
}
