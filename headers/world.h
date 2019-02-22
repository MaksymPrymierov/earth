#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "building/energystation.h"
#include "building/mine.h"
#include "building/farm.h"
#include "building/laboratory.h"

class World : public QObject {
  Q_OBJECT

private:
  qint64 year, population, energy, minerals, food, science;
  float  pollution, solidarity;

  EnergyStation *energyStations = new EnergyStation();
  Mine *mines = new Mine();
  Farm *farms = new Farm();
  Laboratory *labs = new Laboratory();

public:
  explicit World(QObject *parent = nullptr);
  ~World();

  inline QString getInfoEnergyStation() { return energyStations->getInfo(); }
  inline QString getInfoMine() { return mines->getInfo(); }
  inline QString getInfoFarm() { return farms->getInfo(); }
  inline QString getInfoLab() { return labs->getInfo(); }
  QString get();

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
  void preUpdate();
  void postUpdate();

signals:
  void print(QString);

public slots:
  void update();
  void buildEnergyStation();
  void buildMine();
  void buildFarm();
  void buildLab();
};

#endif // WORLD_H
