#include "headers/QBuilding/QLaboratory.h"

QLaboratory::QLaboratory(QBuilding *parent) :
    QBuilding(parent), modMinerals(-2), modScience(1)
{
    setPrice(2);
    setModEnergy(-2);
}

QString QLaboratory::getInfo()
{
    return QString::asprintf("Quantity: %lld\n"
                             "Price: %lld\n"
                             "Science: %lld\n"
                             "Energy: %lld\n"
                             "Minerals: %lld",
                             getQuantity(), getPriceMinerals(), modScience, getModEnergy(),
                             modMinerals);
}
