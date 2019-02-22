#include "headers/building/cleaningstation.h"

CleaningStation::CleaningStation(Building *parent) :
  Building (parent),
  mod_minerals(0),
  mod_pollution(float(-0.1)) {
  price = 5;
  mod_energy = -2;
}

QString CleaningStation::getInfo() {
  QString s;
  s.sprintf("Price: %lld\n"
            "Pollution: %3.2f\n"
            "Energy: %lld\n"
            "Minerals: %lld",
            price, double(mod_pollution), mod_energy, mod_minerals);
  return s;
}
