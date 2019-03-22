#include "headers/Building/EnergyStation.h"
#include <sstream>


EnergyStation::EnergyStation() :
    modPollution(float(0.01))
{
    setModEnergy(1);
    setPrice(1);
}

std::string EnergyStation::getInfo()
{
    std::stringstream stream;
    stream << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nEnergy: " <<
              getModEnergy() << "\nPollution: " << modPollution;
    return stream.str();
}
