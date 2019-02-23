#include "headers/building/farm.h"

Farm::Farm(Building *parent) :
  Building (parent),
  mod_food(1) {
  price = 1;
  mod_energy = -1;
}

QString Farm::getInfo() {
  QString s;
  s.sprintf("Quantity: %lld\n"
            "Price: %lld\n"
            "Food: %lld\n"
            "Energy: %lld\n",
            quantity, price, mod_food, mod_energy);
  return s;
}
