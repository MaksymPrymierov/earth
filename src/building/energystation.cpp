#include "headers/building/energystation.h"

QEnergyStation::QEnergyStation(QBuilding *parent) :
    QBuilding(parent), modPollution(float(0.01))
{
    setModEnergy(1);
    setPrice(1);
}

float QEnergyStation::getFullModPollution()
{
    float b = getQuantity() * modPollution;

    if (b > 100) {
        b = 100;
    }

    return b;
}

QString QEnergyStation::getInfo()
{
    return QString::asprintf("Quantity: %lld\n"
                             "Price: %lld\n"
                             "Energy: %lld\n"
                             "Pollution: %3.2f\n",
                             getQuantity(), getPriceMinerals(), getModEnergy(),
                             double(modPollution));
}
