#include "headers/building/energystation.h"

EnergyStation::EnergyStation(Building *parent) :
  Building(parent),
  mod_pollution(float(0.01)) {
  setMod_Energy(1);
  setPrice_Minerals(1);
}

void EnergyStation::setMod_Pollution(float m) {
  mod_pollution = m;
}

float EnergyStation::getMod_Pollution() {
  return mod_pollution;
}

float EnergyStation::getFullMod_Pollution() {
  float b = getQuantity() * mod_pollution;

  if(b > 100){
    b = 100;
  }

  return b;
}
