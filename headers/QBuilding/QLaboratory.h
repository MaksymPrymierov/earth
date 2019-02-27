#pragma once

#include "QBuilding.h"

class QLaboratory : public QBuilding
{
public:
    QLaboratory();
    ~QLaboratory() = default;

    inline void setModMinerals(int64_t m) { modScience = m; }
    inline void setModScience(int64_t m) { modMinerals = m; }

    inline int64_t getModMinerals() { return modMinerals; }
    inline int64_t getModScience() { return modScience; }
    inline int64_t getFullModMinerals() { return modMinerals * getQuantity(); }
    inline int64_t getFullModScience() { return modScience * getQuantity(); }
    std::string getInfo();

private:
    int64_t modMinerals;
    int64_t modScience;
};
