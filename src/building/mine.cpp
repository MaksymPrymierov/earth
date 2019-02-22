#include "headers/building/mine.h"

Mine::Mine(Building *parent) :
  Building (parent),
  mod_pollution(float(0.01)),
  mod_minerals(1) {
  setPrice_Minerals(1);
  setMod_Energy(-1);
}

void Mine::setMod_Pollution(float m) {
  mod_pollution = m;
}

void Mine::setMod_Minerals(qint64 m) {
  mod_minerals = m;
}

float Mine::getMod_Pollution() {
  return mod_pollution;
}

qint64 Mine::getMod_Minerals() {
  return mod_minerals;
}

float Mine::getFullMod_Pollution() {
  float b = mod_pollution * getQuantity();

  if(b > 100){
    b = 100;
  }

  return b;
}

qint64 Mine::getFullMod_Minerals() {
  return mod_minerals * getQuantity();
}

QString Mine::getInfo() {
  QString s;
  s.sprintf("Price: -%lld\n"
            "Minerals: +%lld\n"
            "Energy: -%lld\n"
            "Pollution: -%3.2f",
            this->getPrice_Minerals(), mod_minerals, this->getMod_Energy(), double(this->getMod_Pollution()));
  return s;
}
