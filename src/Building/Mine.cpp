#include "headers/Building/Mine.h"
#include <sstream>

Mine::Mine() :
    modPollution(float(0.01)), modMinerals(1)
{
    setPrice(1);
    setModEnergy(-1);
}

std::string Mine::getInfo()
{
    std::stringstream s;
    s << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nMinerals: " <<
         modMinerals << "\nPollution: " << modPollution;
    return s.str();
}
