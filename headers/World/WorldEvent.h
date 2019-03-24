#pragma once

#include <vector>
#include <string>

enum class WorldActionEvents : unsigned char
{
    NoEvents, War, Epidemic, Revolution, ActOfTerrorism, AlienAttack,
    GlobalCataclysm, GlobalAccident, PastEvent, PastEventInfo
};

class WorldActionEvent
{
private:
    std::vector<WorldActionEvents> events;
    WorldActionEvents currentEvent;
    const std::vector<std::string> names = {"NoEvents", "War", "Epidemic", "Revolution",
                                           "Act Of Terrorism", "Alien Attack",
                                           "Global Cataclysm" };

public:
    WorldActionEvent();
    ~WorldActionEvent() = default;

    void changeEvent();
    WorldActionEvents get() const;
    std::string getName() const;
    void set(WorldActionEvents e);
    std::string getChance(WorldActionEvents e);
};
