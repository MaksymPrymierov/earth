#pragma once

#include <string>
#include <cstdint>
#include <QEvent>
#include <QObject>
#include "Building/EnergyStation.h"
#include "Building/Mine.h"
#include "Building/Farm.h"
#include "Building/Laboratory.h"
#include "Building/CleaningStation.h"
#include "Building/Stock.h"
#include "WorldEvent.h"

class QWorldEvent : public QEvent
{
public:
    explicit QWorldEvent(Type type);
};

class QWorld
{
public:
    const QEvent::Type WorldEvent = QEvent::Type(QEvent::User + 200);

    explicit QWorld(QObject *receiverEvent);
    ~QWorld() = default;

    inline std::string getInfoEnergyStation() { return energyStations.getInfo(); }
    inline std::string getInfoMine() { return mines.getInfo(); }
    inline std::string getInfoFarm() { return farms.getInfo(); }
    inline std::string getInfoLab() { return labs.getInfo(); }
    inline std::string getInfoCleaningStation() { return cleaningStation.getInfo(); }
    inline std::string getInfoStock() { return stock.getInfo(); }
    inline std::string getInfoActionEvent(WorldActionEvents e) { return actionEvent.getChance(e); }
    inline std::string getCurrentEvent() const { return actionEvent.getName(); }

    std::string getInfoYear();
    std::string getInfoPopulation();
    std::string getInfoEnergy();
    std::string getInfoMinerals();
    std::string getInfoFood();
    std::string getInfoScience();
    std::string getInfoPollution();
    std::string getInfoSolidarity();
    std::string getInfoCapacity();

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

protected:
    int64_t getModEnergy();
    int64_t getModMinerals();
    float getModPollution();
    int64_t getModFood();
    int64_t getModScience();

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
    int64_t year;
    int64_t population;
    int64_t energy;
    int64_t minerals;
    int64_t food;
    int64_t science;
    float  pollution;
    float solidarity;

    EnergyStation energyStations;
    Mine mines;
    Farm farms;
    Laboratory labs;
    CleaningStation cleaningStation;
    Stock stock;
    WorldActionEvent actionEvent;

    QObject *receiver;
};
