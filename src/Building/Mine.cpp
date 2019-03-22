#include "headers/Building/Mine.h"
#include <sstream>

QMine::QMine() :
    modPollution(float(0.01)), modMinerals(1)
{
    setPrice(1);
    setModEnergy(-1);
}

std::string QMine::getInfo()
{
    std::stringstream s;
    s << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nMinerals: " <<
         modMinerals << "\nPollution: " << modPollution;
    return s.str();
}
