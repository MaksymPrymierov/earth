#include "headers/Building/Stock.h"
#include <sstream>

QStock::QStock() :
    capacity(100)
{
    setQuantity(1);
    setPrice(50);
    setModEnergy(0);
}

std::string QStock::getInfo()
{
    std::stringstream s;
    s << "Quantity: " << getQuantity() << "\nPrice: " << getPriceMinerals() << "\nEnergy: " <<
         getModEnergy() << "\nCapacity: " << capacity;
    return s.str();
}
