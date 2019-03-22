#pragma once

#include "Building.h"

class EnergyStation : public Building
{
public:
    EnergyStation();
    ~EnergyStation() = default;

    inline void setModPollution(float m) { modPollution = m; }

    inline float getModPollution() const { return modPollution; }
    inline float getFullModPollution() const { return modPollution * getQuantity(); }
    std::string getInfo();

private:
    float modPollution;
};
