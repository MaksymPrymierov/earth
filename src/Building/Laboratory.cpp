#include "headers/Building/Laboratory.h"
#include <sstream>

Laboratory::Laboratory() :
    modMinerals(-2), modScience(1)
{
    setPrice(2);
    setModEnergy(-2);
}

std::string Laboratory::getInfo()
{
    std::stringstream stream;
    stream << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() <<
              "\nScience: " << modScience << "\nEnergy: " << getModEnergy() << "\nMinerals: " <<
              modMinerals;
    return stream.str();
}
