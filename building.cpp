#include "building.h"

Building::Building(QObject *parent) : QObject(parent){
  quantity = 0;
  p_minarals = 0;
  m_energy = 0;
}

void Building::setQuantity(quint64 q){
  quantity = q;
}

void Building::setP_Minarals(quint64 p){
  p_minarals = p;
}

void Building::setM_Energy(qint64 m){
  m_energy = m;
}

quint64 Building::getQuantity(){
  return quantity;
}

quint64 Building::getP_Minarals(){
  return p_minarals;
}

qint64  Building::getM_Energy(){
  return m_energy;
}

void Building::build(){
  ++quantity;
}

void Building::destroy(){
  --quantity;
}
