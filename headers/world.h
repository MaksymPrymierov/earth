#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "building/energystation.h"
#include "building/mine.h"
#include "building/farm.h"
#include "building/laboratory.h"
#include "building/cleaningstation.h"

class World : public QObject {
  Q_OBJECT

private:
  qint64 year, population, energy, minerals, food, science;
  float  pollution, solidarity;

  EnergyStation *energyStations = new EnergyStation();
  Mine *mines = new Mine();
  Farm *farms = new Farm();
  Laboratory *labs = new Laboratory();
  CleaningStation *cleaningStation = new CleaningStation();

public:
  explicit World(QObject *parent = nullptr);
  ~World();

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

private:
  qint64 getMod_Energy();
  qint64 getMod_Minerals();
  float getMod_Pollution();
  qint64 getMod_Food();
  qint64 getMod_Science();

  void updateEnergyStations();
  void updateMines();
  void updateFarms();
  void updateLabs();
  void updateCleaningStation();
  void preUpdate();
  void postUpdate();

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
};

#endif // WORLD_H
