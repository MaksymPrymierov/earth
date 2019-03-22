#ifndef WORLDEVENT_H
#define WORLDEVENT_H
#include <vector>
#include <string>

enum class QWorldActionEvents : unsigned char
{
    NoEvents, War, Epidemic, Revolution, ActOfTerrorism, AlienAttack,
    GlobalCataclysm, GlobalAccident
};

class QWorldActionEvent
{
private:
    std::vector<QWorldActionEvents> events;
    QWorldActionEvents currentEvent;

public:
    QWorldActionEvent();
    ~QWorldActionEvent() = default;

    void changeEvent();
    QWorldActionEvents get() const;
    void set(QWorldActionEvents e);
    std::string getChance(QWorldActionEvents e);
};

#endif // WORLDEVENT_H
