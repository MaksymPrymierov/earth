#include "headers/building/farm.h"

Farm::Farm(Building *parent) :
  Building (parent),
  mod_food(1) {
  setPrice_Minerals(1);
  setMod_Energy(-1);
}

void Farm::setMod_Food(qint64 m) {
  mod_food = m;
}

qint64 Farm::getMod_Food() {
  return mod_food;
}

qint64 Farm::getFullMod_Food() {
  return mod_food * getQuantity();
}

QString Farm::getInfo() {
  QString s;
  s.sprintf("Price: -%lld\n"
            "Food: +%lld\n"
            "Energy: -%lld\n",
            this->getPrice_Minerals(), mod_food, this->getMod_Energy());
  return s;
}
