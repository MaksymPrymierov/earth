#include "headers/building/cleaningstation.h"

QCleaningStation::QCleaningStation(QBuilding *parent) :
    QBuilding(parent), modMinerals(0), modPollution(float(-0.1))
{
    setPrice(10);
    setModEnergy(-4);
}

QString QCleaningStation::getInfo()
{
    return QString::asprintf("Quantity: %lld\n"
                             "Price: %lld\n"
                             "Pollution: %3.2f\n"
                             "Energy: %lld\n"
                             "Minerals: %lld",
                             getQuantity(), getPriceMinerals(), double(modPollution),
                             getModEnergy(), modMinerals);
}
