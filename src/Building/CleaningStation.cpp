#include "headers/Building/CleaningStation.h"
#include <sstream>

CleaningStation::CleaningStation() :
    modMinerals(0), modPollution(float(-0.1))
{
    setPrice(10);
    setModEnergy(-4);
}

std::string CleaningStation::getInfo()
{
    std::stringstream stream;
    stream << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nPollution" <<
              modPollution << "\nMinerals: " << modMinerals;
    return stream.str();
}
