#include "headers/Building/Farm.h"
#include <sstream>

Farm::Farm() :
    modFood(1)
{
    setPrice(1);
    setModEnergy(-1);
}

std::string Farm::getInfo()
{
    std::stringstream stream;
    stream << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nFood: " <<
              modFood << "\nEnergy: " << getModEnergy();
    return stream.str();
}
