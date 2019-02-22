#include "headers/building/building.h"

Building::Building(QObject *parent) :
  QObject(parent),
  quantity(0),
  price(0),
  mod_energy(0) {   }
