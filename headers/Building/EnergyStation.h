#pragma once

#include "Building.h"

class QEnergyStation : public QBuilding
{
public:
    QEnergyStation();
    ~QEnergyStation() = default;

    inline void setModPollution(float m) { modPollution = m; }

    inline float getModPollution() { return modPollution; }
    inline float getFullModPollution() { return modPollution * getQuantity(); }
    std::string getInfo();

private:
    float modPollution;
};
