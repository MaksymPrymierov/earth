#ifndef WORLDEVENT_H
#define WORLDEVENT_H
#include <vector>

enum class WorldEvents : unsigned char
{
    NoEvents, War, Epidemic, Revolution, ActOfTerrorism, AlienAttack,
    GlobalCataclysm, GlobalAccident
};

class WorldEvent
{
private:
    std::vector<WorldEvents> events;
    WorldEvents currentEvent;

public:
    WorldEvent();
    ~WorldEvent() = default;

    void changeEvent();
    inline WorldEvents get() const;
    inline void set(WorldEvents e);
};

#endif // WORLDEVENT_H
