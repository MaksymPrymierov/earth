#include "headers/building/cleaningstation.h"

CleaningStation::CleaningStation(Building *parent) :
  Building (parent),
  mod_minerals(0),
  mod_pollution(float(-0.1)) {
  price = 10;
  mod_energy = -4;
}

QString CleaningStation::getInfo() {
  QString s;
  s.sprintf("Quantity: %lld\n"
            "Price: %lld\n"
            "Pollution: %3.2f\n"
            "Energy: %lld\n"
            "Minerals: %lld",
            quantity, price, double(mod_pollution), mod_energy, mod_minerals);
  return s;
}
