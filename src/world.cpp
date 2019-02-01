#include "headers/world.h"
#include <QtCore/QCoreApplication>
#include <QtWidgets>


 World::World(QObject *parent) :
  QObject(parent),
  year(0),
  population(300),
  energy(100),
  minerals(100),
  food(100),
  science(0),
  pollution(0),
  solidarity(60) {   }

QString World::get() {
  QString str;
  str.sprintf("Год: %lld, Люди: %lld тыс.\n"
              "Енергия: %lld (%lld), Минералы: %lld (%lld), Еда: %lld (%lld)\n"
              "Загрязнение: %d %% (%d %%), Сплоченность: %d %%\n"
              "Наука: %lld (%lld)\n"
              "Электростанции: %lld, Шахты: %lld, Фермы: %lld\n"
              "Лаборатории: %lld",
               year, population, energy, getMod_Energy(), minerals, getMod_Minerals(), food, getMod_Food(),\
               qRound(pollution), qRound(getMod_Pollution()), qRound(solidarity), science, getMod_Science(),\
               energyStations->getQuantity(), mines->getQuantity(), farms->getQuantity(),\
               labs->getQuantity());
  return str;
}

qint64 World::getMod_Energy() {
  return energyStations->getFullMod_Energy() + mines->getFullMod_Energy() + \
         farms->getFullMod_Energy() + labs->getFullMod_Energy();
}

qint64 World::getMod_Minerals() {
  if(energy > 0) {
    return mines->getFullMod_Minerals() + labs->getFullMod_Minerals();
  } else {
    return 0;
  }
}

float World::getMod_Pollution() {
  return energyStations->getFullMod_Pollution() + mines->getMod_Pollution();
}

qint64 World::getMod_Food() {
  if(energy > 0) {
    return farms->getFullMod_Food() - qint64(population * 0.01);
  } else {
    return 0;
  }
}

qint64 World::getMod_Science() {
  if(energy > 0) {
    return labs->getFullMod_Science();
  } else {
    return 0;
  }
}

void World::preUpdate() {
  if(population == 0) {
    QCoreApplication::quit();
  }
}

void World::updateEnergyStations() {
  energy += energyStations->getFullMod_Energy();
  pollution += energyStations->getFullMod_Pollution();
}

void World::updateMines() {
  if(energy > 0) {
    energy += mines->getFullMod_Energy();
    pollution += mines->getFullMod_Pollution();
    minerals += mines->getFullMod_Minerals();
  }
}

void World::updateFarms() {
  if(energy > 0) {
    energy += farms->getFullMod_Energy();
    food += farms->getFullMod_Food();
  }
}

void World::updateLabs() {
  if(energy > 0 && minerals > 0) {
    energy += labs->getFullMod_Energy();
    minerals += labs->getFullMod_Minerals();
    science += labs->getFullMod_Science();
  }
}

void World::postUpdate() {
  if(food > 0) {
    food -= population * 0.01;
    ++population;
  } else{
    --population;
  }

  ++year;
}

void World::update(){
  preUpdate();

  updateEnergyStations();
  updateMines();
  updateFarms();
  updateLabs();

  postUpdate();

  emit print(get());
}

void World::buildEnergyStation() {
  if(minerals < energyStations->getPrice_Minerals()) {
    return;
  }
  minerals -= energyStations->getPrice_Minerals();
  energyStations->build();
  update();
}

void World::buildMine() {
  if(minerals < mines->getPrice_Minerals()) {
    return;
  }
  minerals -= mines->getPrice_Minerals();
  mines->build();
  update();
}

void World::buildFarm() {
  if(minerals < farms->getPrice_Minerals()) {
    return;
  }
  minerals -= farms->getPrice_Minerals();
  farms->build();
  update();
}

void World::buildLab() {
  if(minerals < labs->getPrice_Minerals())  {
    return;
  }
  minerals -= labs->getPrice_Minerals();
  labs->build();
  update();
}
