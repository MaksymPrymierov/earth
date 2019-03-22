#ifndef WORLDEVENT_H
#define WORLDEVENT_H
#include <vector>
#include <string>
#include <map>

enum class QWorldActionEvents : unsigned char
{
    NoEvents, War, Epidemic, Revolution, ActOfTerrorism, AlienAttack,
    GlobalCataclysm, GlobalAccident, PastEvent, PastEventInfo
};

class QWorldActionEvent
{
private:
    std::vector<QWorldActionEvents> events;
    QWorldActionEvents currentEvent;
    const std::vector<std::string> names = {"NoEvents", "War", "Epidemic", "Revolution",
                                           "Act Of Terrorism", "Alien Attack",
                                           "Global Cataclysm" };


public:
    QWorldActionEvent();
    ~QWorldActionEvent() = default;

    void changeEvent();
    QWorldActionEvents get() const;
    std::string getName() const;
    void set(QWorldActionEvents e);
    std::string getChance(QWorldActionEvents e);
};

#endif // WORLDEVENT_H
