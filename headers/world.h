#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "energystation.h"
#include "mine.h"

class World : public QObject
{
  Q_OBJECT

private:
  qint64 year, population, energy, minerals, food, science;
  float  pollution, solidarity;

  EnergyStation *energyStations = new EnergyStation();
  Mine *mines = new Mine();

public:
  explicit World(QObject *parent = nullptr);
  ~World() = default;

  QString get();

private:
  void updateEnergy();
  void updateMinerals();
  void updatePollution();

signals:
  void print(QString);

public slots:
  void update();
  void buildEnergyStation();
  void buildMine();
};

#endif // WORLD_H
