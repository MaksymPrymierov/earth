#include "headers/world.h"
#include <QtCore/QCoreApplication>


 World::World(QObject *parent) : QObject(parent){
  year = 0;
  population = 300;
  energy = 1000;
  minerals = 1000;
  food = 1000;
  pollution = 0;
  solidarity = 60;
  science = 0;
}

QString World::get(){
  QString str;
  str.sprintf("Год: %lld, Люди: %lld тыс.\n\
               Енергия: %lld (%lld), Минералы: %lld (%lld), Еда: %lld (%lld)\n\
               Загрязнение: %d %% (%d %%), Сплоченность: %d %%\n\
               Наука: %lld\n\
               Енергостанции: %lld, Шахты: %lld, Фермы: %lld",
               year, population, energy, getMod_Energy(), minerals, getMod_Minerals(), food, getMod_Food(),\
               qRound(pollution), qRound(solidarity), qRound(getMod_Pollution()), science,\
               energyStations->getQuantity(), mines->getQuantity(), farms->getQuantity());
  return str;
}

qint64 World::getMod_Energy(){
  return energyStations->getFullMod_Energy() + mines->getFullMod_Energy() + \
      farms->getFullMod_Energy();
}

qint64 World::getMod_Minerals(){
  return mines->getFullMod_Minerals();
}

float World::getMod_Pollution(){
  return energyStations->getFullMod_Pollution() + mines->getMod_Pollution();
}

qint64 World::getMod_Food(){
  return farms->getFullMod_Food() - qint64(population * 0.01);
}

void World::preUpdate(){
  if(population == 0){
      QCoreApplication::quit();
    }
}

void World::updateEnergy(){
  energy += getMod_Energy();
  if(energy < 0){
      energy = 0;
    }
}

void World::updateMinerals(){
  minerals += getMod_Minerals();
  if(minerals < 0){
      minerals = 0;
    }
}

void World::updatePollution(){
  pollution += getMod_Pollution();
  if(pollution < 0){
      pollution = 0;
    } else if(pollution > 100){
      pollution = 100;
    }
}

void World::updateFood(){
  food += getMod_Food();
  if(food < 0){
      food = 0;
    }
}

void World::update(){
  preUpdate();
  updateEnergy();
  updateMinerals();
  updatePollution();
  updateFood();

  ++year;
  if(food > 0){
      ++population;
    } else {
      --population;
    }

  emit print(get());
}

void World::buildEnergyStation(){
  if(minerals < energyStations->getPrice_Minerals()){
      return;
    }
  minerals -= energyStations->getPrice_Minerals();
  energyStations->build();
  update();
}

void World::buildMine(){
  if(minerals < mines->getPrice_Minerals()){
      return;
    }
  minerals -= mines->getPrice_Minerals();
  mines->build();
  update();
}

void World::buildFarm(){
  if(minerals < farms->getPrice_Minerals()){
      return;
    }
  minerals -= farms->getPrice_Minerals();
  farms->build();
  update();
}
