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

 World::~World() {
   delete energyStations;
   delete mines;
   delete farms;
   delete labs;
   delete cleaningStation;
 }

QString World::get() {
  QString str;
  str.sprintf("Year: %lld, Population: %lldk\n"
              "Energy: %lld (%lld), Minerals: %lld (%lld), Food: %lld (%lld)\n"
              "Pollution: %3.2f %% (%3.2f %%), Solidarity: %3.2f %%\n"
              "Science: %lld (%lld)\n"
              "Energy Stations: %lld, Mines: %lld, Farms: %lld\n"
              "Cleaning Stations: %lld,\n"
              "Laboratories: %lld",
               year, population, energy, getMod_Energy(), minerals, getMod_Minerals(), food, getMod_Food(),\
               double(pollution), double(getMod_Pollution()), double(solidarity), science, getMod_Science(),\
               energyStations->getQuantity(), mines->getQuantity(), farms->getQuantity(),\
               cleaningStation->getQuantity(),\
               labs->getQuantity());
  return str;
}

qint64 World::getMod_Energy() {
  return energyStations->getFullMod_Energy() + mines->getFullMod_Energy() + \
         farms->getFullMod_Energy() + labs->getFullMod_Energy() + \
         cleaningStation->getFullMod_Energy();
}

qint64 World::getMod_Minerals() {
  if(energy > 0) {
    return mines->getFullMod_Minerals() + labs->getFullMod_Minerals() + \
           cleaningStation->getFullMod_Minerals();
  } else {
    return 0;
  }
}

float World::getMod_Pollution() {
  float m = energyStations->getFullMod_Pollution() + mines->getMod_Pollution();
  if(energy > 0) {
    m += cleaningStation->getFullMod_Pollution();
  }
  return m;
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

void World::updateCleaningStation() {
  if(energy > 0) {
    energy += cleaningStation->getFullMod_Energy();
    minerals += cleaningStation->getFullMod_Minerals();
    pollution += cleaningStation->getFullMod_Pollution();
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
  updateCleaningStation();

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

void World::buildCleaningStation() {
  if(minerals < cleaningStation->getPrice_Minerals()) {
    return;
  }
  minerals -= cleaningStation->getPrice_Minerals();
  cleaningStation->build();
  update();
}
