#include "headers/building/laboratory.h"

Laboratory::Laboratory(Building *parent) :
  Building (parent),
  mod_minerals(-2),
  mod_science(1) {
  setMod_Energy(-2);
  setPrice_Minerals(2);
}

qint64 Laboratory::getMod_Science() {
  return mod_science;
}

qint64 Laboratory::getMod_Minerals() {
  return mod_minerals;
}

qint64 Laboratory::getFullMod_Science() {
  return getQuantity() * mod_science;
}

qint64 Laboratory::getFullMod_Minerals() {
  return getQuantity() * mod_minerals;
}

QString Laboratory::getInfo() {
  QString s;
  s.sprintf("Price: -%lld\n"
            "Science: +%lld\n"
            "Energy: -%lld\n",
            this->getPrice_Minerals(), mod_science, this->getMod_Energy());
  return s;
}

void Laboratory::setMod_Science(qint64 m){
  mod_science = m;
}

void Laboratory::setMod_Minerals(qint64 m){
  mod_minerals = m;
}
