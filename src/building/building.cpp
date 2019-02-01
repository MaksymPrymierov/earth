#include "headers/building/building.h"

Building::Building(QObject *parent) :
  QObject(parent),
  quantity(0) {   }

void Building::setQuantity(qint64 q) {
  quantity = q;
}

void Building::setPrice_Minerals(qint64 p) {
  price_minerals = p;
}

void Building::setMod_Energy(qint64 m) {
  mod_energy = m;
}

qint64 Building::getQuantity() {
  return quantity;
}

qint64 Building::getPrice_Minerals() {
  return price_minerals;
}

qint64 Building::getMod_Energy() {
  return mod_energy;
}

qint64 Building::getFullPriece_Mineral() {
  return quantity * price_minerals;
}

qint64 Building::getFullMod_Energy() {
  return quantity * mod_energy;
}

void Building::build() {
  ++quantity;
}

void Building::destroy() {
  if(quantity != 0){
    --quantity;
  }
}
