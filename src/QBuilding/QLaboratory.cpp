#include "headers/QBuilding/QLaboratory.h"
#include <sstream>

QLaboratory::QLaboratory() :
    modMinerals(-2), modScience(1)
{
    setPrice(2);
    setModEnergy(-2);
}

std::string QLaboratory::getInfo()
{
    std::stringstream stream;
    stream << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() <<
              "\nScience: " << modScience << "\nEnergy: " << getModEnergy() << "\nMinerals: " <<
              modMinerals;
    return stream.str();
}
