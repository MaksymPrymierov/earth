#pragma once

#include "Building.h"

class QCleaningStation : public QBuilding
{
public:
    QCleaningStation();
    ~QCleaningStation() = default;

    inline void setModMineral(int64_t m) { modMinerals = m; }
    inline void setModPollution(float m) { modPollution = m; }

    inline int64_t getModMinerals() { return modMinerals; }
    inline float getModPollution() { return modPollution; }

    inline int64_t getFullModMinerals() { return modMinerals * getQuantity(); }
    inline float getFullModPollution() { return modPollution * getQuantity(); }
    std::string getInfo();

private:
    int64_t modMinerals;
    float modPollution;
};
