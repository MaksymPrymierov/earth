#include "headers/QWorldEvent.h"
#include <cstdlib>
#include <sstream>

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

std::string QWorldActionEvent::getChance(QWorldActionEvents e)
{
    std::stringstream name;

    switch (e) {
    case QWorldActionEvents::War :
        name << "War ";
        break;
    case QWorldActionEvents::Epidemic :
        name << "Epidemic ";
        break;
    case QWorldActionEvents::Revolution :
        name << "Revolution ";
        break;
    case QWorldActionEvents::AlienAttack :
        name << "Alien Attack ";
        break;
    case QWorldActionEvents::ActOfTerrorism :
        name << "Act Of Terrorism ";
        break;
    case QWorldActionEvents::GlobalAccident :
        name << "Global Accident ";
        break;
    case QWorldActionEvents::GlobalCataclysm :
        name << "Global Cataclysm ";
        break;
    default:
        name << "NULL";
    }

    int countEvent = 0;

    for (std::vector<QWorldActionEvents>::iterator i = events.begin(); i != events.end(); ++i) {
        if (*i == e)
            ++countEvent;
    }

    name << countEvent * 100 / float(events.size()) << " %";
    return name.str();
}
