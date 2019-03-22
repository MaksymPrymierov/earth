#include "headers/Building/EnergyStation.h"
#include <sstream>


QEnergyStation::QEnergyStation() :
    modPollution(float(0.01))
{
    setModEnergy(1);
    setPrice(1);
}

std::string QEnergyStation::getInfo()
{
    std::stringstream stream;
    stream << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nEnergy: " <<
              getModEnergy() << "\nPollution: " << modPollution;
    return stream.str();
}
