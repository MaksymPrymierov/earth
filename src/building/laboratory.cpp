#include "headers/building/laboratory.h"

Laboratory::Laboratory(Building *parent) :
  Building (parent),
  mod_minerals(-2),
  mod_science(1) {
  price = 2;
  mod_energy = -2;
}

QString Laboratory::getInfo() {
  QString s;
  s.sprintf("Quantity: %lld\n"
            "Price: %lld\n"
            "Science: %lld\n"
            "Energy: %lld\n"
            "Minerals: %lld",
            quantity, price, mod_science, mod_energy, mod_minerals);
  return s;
}
