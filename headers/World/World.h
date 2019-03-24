#pragma once

#include <string>
#include <cstdint>
#include <QEvent>
#include <QObject>
#include "headers/Building/EnergyStation.h"
#include "headers/Building/Mine.h"
#include "headers/Building/Farm.h"
#include "headers/Building/Laboratory.h"
#include "headers/Building/CleaningStation.h"
#include "headers/Building/Stock.h"

#include "WorldEvent.h"
#include "WorldStats.h"

class QWorldEvent : public QEvent
{
public:
    explicit QWorldEvent(Type type);
};

class World
{
public:
    const QEvent::Type WorldEvent = QEvent::Type(QEvent::User + 200);

    explicit World(QObject *receiverEvent);
    ~World() = default;

    inline std::string getInfoEnergyStation() { return energyStations.getInfo(); }
    inline std::string getInfoMine() { return mines.getInfo(); }
    inline std::string getInfoFarm() { return farms.getInfo(); }
    inline std::string getInfoLab() { return labs.getInfo(); }
    inline std::string getInfoCleaningStation() { return cleaningStation.getInfo(); }
    inline std::string getInfoStock() { return stock.getInfo(); }
    inline std::string getInfoActionEvent(WorldActionEvents e) { return actionEvent.getChance(e); }
    inline std::string getCurrentEvent() const { return actionEvent.getName(); }

    inline int64_t getYear() const { return resources.year; }
    inline int64_t getPopulation() const { return resources.population; }
    inline int64_t getEnergy() const { return resources.energy; }
    inline int64_t getMinerals() const { return resources.minerals; }
    inline int64_t getFood() const { return resources.food; }
    inline int64_t getScience() const { return resources.science; }
    inline float getPolltion() const { return resources.pollution; }
    inline float getSolidarity() const { return resources.solidarity; }
    inline int64_t getCapacity() const { return stock.getFullCapacity(); }

    void update();
    void buildEnergyStation();
    void buildMine();
    void buildFarm();
    void buildLab();
    void buildCleaningStation();
    void buildStock();

    void destroyEnergyStation();
    void destroyMine();
    void destroyFarm();
    void destroyLab();
    void destroyCleaningStation();
    void destroyStock();

    int64_t getModEnergy();
    int64_t getModMinerals();
    float getModPollution();
    int64_t getModFood();
    int64_t getModScience();

protected:
    void updateEnergyStations();
    void updateMines();
    void updateFarms();
    void updateLabs();
    void updateCleaningStation();
    void updateActionEvent();

    void preUpdate();
    void postUpdate();

    void checkEnergy();
    void checkMinerals();
    void checkFood();
    void checkPollution();
    void checkSolidarity();
    void checkActionEvent();

private:
    EnergyStation energyStations;
    Mine mines;
    Farm farms;
    Laboratory labs;
    CleaningStation cleaningStation;
    Stock stock;

    WorldActionEvent actionEvent;
    WorldStats resources;

    QObject *receiver;
};
