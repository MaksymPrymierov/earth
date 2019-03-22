#include "headers/WorldEvent.h"
#include <cstdlib>
#include <sstream>

WorldActionEvent::WorldActionEvent() :
    currentEvent(WorldActionEvents::NoEvents)
{
    events.push_back(WorldActionEvents::NoEvents);
}

void WorldActionEvent::changeEvent()
{
    currentEvent = events[size_t(rand() % int(events.size() + 1))];
    events.clear();
    events.push_back(WorldActionEvents::NoEvents);
}

WorldActionEvents WorldActionEvent::get() const
{
    return currentEvent;
}

std::string WorldActionEvent::getName() const
{
    return names[size_t(get())];
}

void WorldActionEvent::set(WorldActionEvents e)
{
    events.push_back(e);
}

std::string WorldActionEvent::getChance(WorldActionEvents e)
{
    std::stringstream name;

    switch (e) {
    case WorldActionEvents::War :
        name << "War ";
        break;
    case WorldActionEvents::Epidemic :
        name << "Epidemic ";
        break;
    case WorldActionEvents::Revolution :
        name << "Revolution ";
        break;
    case WorldActionEvents::AlienAttack :
        name << "Alien Attack ";
        break;
    case WorldActionEvents::ActOfTerrorism :
        name << "Act Of Terrorism ";
        break;
    case WorldActionEvents::GlobalAccident :
        name << "Global Accident ";
        break;
    case WorldActionEvents::GlobalCataclysm :
        name << "Global Cataclysm ";
        break;
    default:
        name << "NULL";
    }

    int countEvent = 0;

    for (std::vector<WorldActionEvents>::iterator i = events.begin(); i != events.end(); ++i) {
        if (*i == e)
            ++countEvent;
    }

    name << countEvent * 100 / float(events.size()) << " %";
    return name.str();
}
