#pragma once

#include "Building.h"

class CleaningStation : public Building
{
public:
    CleaningStation();
    ~CleaningStation() = default;

    inline void setModMineral(int64_t m) { modMinerals = m; }
    inline void setModPollution(float m) { modPollution = m; }

    inline int64_t getModMinerals() const { return modMinerals; }
    inline float getModPollution() const { return modPollution; }

    inline int64_t getFullModMinerals() const { return modMinerals * getQuantity(); }
    inline float getFullModPollution() const { return modPollution * getQuantity(); }
    std::string getInfo();

private:
    int64_t modMinerals;
    float modPollution;
};
