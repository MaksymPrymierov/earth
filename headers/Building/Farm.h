#pragma once

#include "Building.h"

class Farm : public Building
{
public:
    Farm();
    ~Farm() = default;

    inline void setModFood(int64_t m) { modFood = m; }

    inline int64_t getModFood() const { return modFood; }
    inline int64_t getFullModFood() const { return modFood * getQuantity(); }
    std::string getInfo();

private:
    int64_t modFood;
};
