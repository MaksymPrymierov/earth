#include "headers/building/farm.h"

QFarm::QFarm(QBuilding *parent) :
    QBuilding(parent), modFood(1)
{
    setPrice(1);
    setModEnergy(-1);
}

QString QFarm::getInfo()
{
    return QString::asprintf("Quantity: %lld\n"
                             "Price: %lld\n"
                             "Food: %lld\n"
                             "Energy: %lld\n",
                             getQuantity(), getPriceMinerals(), modFood, getModEnergy());
}
