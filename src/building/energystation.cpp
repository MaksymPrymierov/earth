#include "headers/building/energystation.h"

EnergyStation::EnergyStation(Building *parent) :
  Building(parent),
  mod_pollution(float(0.01)) {
  mod_energy = 1;
  price = 1;
}

float EnergyStation::getFullMod_Pollution() {
  float b = quantity * mod_pollution;

  if(b > 100){
    b = 100;
  }

  return b;
}

QString EnergyStation::getInfo() {
  QString s;
  s.sprintf("Price: %lld\n"
            "Energy: %lld\n"
            "Pollution: %3.2f\n",
            price, mod_energy, double(mod_pollution));
  return s;
}
