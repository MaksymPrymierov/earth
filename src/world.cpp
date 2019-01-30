#include "headers/world.h"

 World::World(QObject *parent) : QObject(parent){
  year = 0;
  population = 300;
  energy = 0;
  minerals = 100;
  food = 1000;
  pollution = 0;
  solidarity = 60;
  science = 0;
}

QString World::get(){
  QString str;
  str.sprintf("Год: %lld, Люди: %lld тыс.\n\
               Енергия: %lld, Минералы: %lld, Еда: %lld\n\
               Загрязнение: %d %%, Сплоченность: %d %%\n\
               Наука: %lld\n\
               Енергостанции: %lld, Шахты: %lld",
               year, population, energy, minerals, food,\
               qRound(pollution), qRound(solidarity), science,\
               energyStations->getQuantity(), mines->getQuantity());
  return str;
}

void World::updateEnergy(){
  energy += energyStations->getFullMod_Energy() + \
      mines->getFullMod_Energy();
  if(energy < 0){
      energy = 0;
    }
}

void World::updateMinerals(){
  minerals += mines->getFullMod_Minerals();
  if(minerals < 0){
      minerals = 0;
    }
}

void World::updatePollution(){
  pollution += energyStations->getFullMod_Pollution() + \
      mines->getMod_Pollution();
  if(pollution < 0){
      pollution = 0;
    } else if(pollution > 100){
      pollution = 100;
    }
}

void World::update(){
  updateEnergy();
  updateMinerals();
  updatePollution();

  ++year;
  ++population;

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
