#include "headers/QBuilding/QCleaningStation.h"
#include <sstream>

QCleaningStation::QCleaningStation() :
    modMinerals(0), modPollution(float(-0.1))
{
    setPrice(10);
    setModEnergy(-4);
}

std::string QCleaningStation::getInfo()
{
    std::stringstream stream;
    stream << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nPollution" <<
              modPollution << "\nMinerals: " << modMinerals;
    return stream.str();
}
