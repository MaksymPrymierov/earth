#pragma once

#include "QBuilding.h"

class QMine : public QBuilding
{
public:
    QMine();
    ~QMine() = default;

    inline void setModPollution(float m) { modPollution = m; }
    inline void setModMinerals(int64_t m) { modMinerals = m; }

    inline float getModPollution() { return modPollution; }
    inline int64_t getModMinerals() { return modMinerals; }
    inline float getFullModPollution() { return modPollution * getQuantity(); }
    inline int64_t getFullModMinerals() { return modMinerals * getQuantity(); }
    std::string getInfo();

private:
    float modPollution;
    int64_t modMinerals;
};
