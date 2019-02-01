#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "building/energystation.h"
#include "building/mine.h"
#include "building/farm.h"

class World : public QObject {
  Q_OBJECT

private:
  qint64 year, population, energy, minerals, food, science;
  float  pollution, solidarity;

  EnergyStation *energyStations = new EnergyStation();
  Mine *mines = new Mine();
  Farm *farms = new Farm();

public:
  explicit World(QObject *parent = nullptr);
  ~World() = default;

  QString get();

private:
  qint64 getMod_Energy();
  qint64 getMod_Minerals();
  float getMod_Pollution();
  qint64 getMod_Food();

  void updateEnergyStations();
  void updateMines();
  void updateFarms();
  void preUpdate();
  void postUpdate();

signals:
  void print(QString);

public slots:
  void update();
  void buildEnergyStation();
  void buildMine();
  void buildFarm();
};

#endif // WORLD_H
