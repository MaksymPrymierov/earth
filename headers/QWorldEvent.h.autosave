#ifndef WORLDEVENT_H
#define WORLDEVENT_H
#include <vector>

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
    inline QWorldActionEvents get() const;
    inline void set(QWorldActionEvents e);
};

#endif // WORLDEVENT_H
