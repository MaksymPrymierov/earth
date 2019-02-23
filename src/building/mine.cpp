#include "headers/building/mine.h"

QMine::QMine(QBuilding *parent) :
    QBuilding(parent), modPollution(float(0.01)), modMinerals(1)
{
    setPrice(1);
    setModEnergy(-1);
}

float QMine::getFullModPollution()
{
    float b = modPollution * getQuantity();

    if (b > 100) {
        b = 100;
    }

    return b;
}

QString QMine::getInfo()
{
    return QString::asprintf("Quantity: %lld\n"
                             "Price: %lld\n"
                             "Minerals: %lld\n"
                             "Energy: %lld\n"
                             "Pollution: %3.2f",
                             getQuantity(), getPriceMinerals(), modMinerals, getModEnergy(),
                             double(modPollution));
}
