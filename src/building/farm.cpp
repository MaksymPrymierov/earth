#include "headers/building/farm.h"

Farm::Farm(Building *parent) : Building (parent){
  mod_food = 1;
  setPrice_Minerals(1);
  setMod_Energy(-1);
}

void Farm::setMod_Food(qint64 m){
  mod_food = m;
}

qint64 Farm::getMod_Food(){
  return mod_food;
}

qint64 Farm::getFullMod_Food(){
  return mod_food * getQuantity();
}
