#pragma once

#include <QObject>
#include "QBuilding/QEnergyStation.h"
#include "QBuilding/QMine.h"
#include "QBuilding/QFarm.h"
#include "QBuilding/QLaboratory.h"
#include "QBuilding/QCleaningStation.h"

class QWorld : public QObject
{
    Q_OBJECT
public:
    explicit QWorld(QObject *parent = nullptr);
    ~QWorld();

    inline QString getInfoEnergyStation() { return energyStations->getInfo(); }
    inline QString getInfoMine() { return mines->getInfo(); }
    inline QString getInfoFarm() { return farms->getInfo(); }
    inline QString getInfoLab() { return labs->getInfo(); }
    inline QString getInfoCleaningStation() { return cleaningStation->getInfo(); }

    QString getInfoYear();
    QString getInfoPopulation();
    QString getInfoEnergy();
    QString getInfoMinerals();
    QString getInfoFood();
    QString getInfoScience();
    QString getInfoPollution();
    QString getInfoSolidarity();

signals:
    void yearUpdate(QString);
    void populationUpdate(QString);
    void energyUpdate(QString);
    void mineralsUpdate(QString);
    void foodUpdate(QString);
    void scienceUpdate(QString);
    void pullutionUpdate(QString);
    void solidarityUpdate(QString);

public slots:
    void update();
    void buildEnergyStation();
    void buildMine();
    void buildFarm();
    void buildLab();
    void buildCleaningStation();

protected:
    qint64 getModEnergy();
    qint64 getModMinerals();
    float getModPollution();
    qint64 getModFood();
    qint64 getModScience();

    void updateEnergyStations();
    void updateMines();
    void updateFarms();
    void updateLabs();
    void updateCleaningStation();
    void preUpdate();
    void postUpdate();

    void checkEnergy();
    void checkMinerals();
    void checkFood();
    void checkPollution();
    void checkSolidarity();

private:
    qint64 year;
    qint64 population;
    qint64 energy;
    qint64 minerals;
    qint64 food;
    qint64 science;
    float  pollution;
    float solidarity;

    QEnergyStation *energyStations = new QEnergyStation();
    QMine *mines = new QMine();
    QFarm *farms = new QFarm();
    QLaboratory *labs = new QLaboratory();
    QCleaningStation *cleaningStation = new QCleaningStation();
};
