#pragma once

#include "Building.h"

class Mine : public Building
{
public:
    Mine();
    ~Mine() = default;

    inline void setModPollution(float m) { modPollution = m; }
    inline void setModMinerals(int64_t m) { modMinerals = m; }

    inline float getModPollution() const { return modPollution; }
    inline int64_t getModMinerals() const { return modMinerals; }
    inline float getFullModPollution() const { return modPollution * getQuantity(); }
    inline int64_t getFullModMinerals() const { return modMinerals * getQuantity(); }
    std::string getInfo();

private:
    float modPollution;
    int64_t modMinerals;
};
