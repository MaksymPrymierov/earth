#include "headers/building/mine.h"

Mine::Mine(Building *parent) :
  Building (parent),
  mod_pollution(float(0.01)),
  mod_minerals(1) {
  price = 1;
  mod_energy = -1;
}

float Mine::getFullMod_Pollution() {
  float b = mod_pollution * getQuantity();

  if(b > 100){
    b = 100;
  }

  return b;
}

QString Mine::getInfo() {
  QString s;
  s.sprintf("Price: %lld\n"
            "Minerals: %lld\n"
            "Energy: %lld\n"
            "Pollution: -%3.2f",
            price, mod_minerals, mod_energy, double(mod_pollution));
  return s;
}
