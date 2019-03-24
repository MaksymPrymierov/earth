#pragma once

#include "Building.h"

class Laboratory : public Building
{
public:
    Laboratory();
    ~Laboratory() = default;

    inline void setModMinerals(int64_t m) { modScience = m; }
    inline void setModScience(int64_t m) { modMinerals = m; }

    inline int64_t getModMinerals() const { return modMinerals; }
    inline int64_t getModScience() const { return modScience; }
    inline int64_t getFullModMinerals() const { return modMinerals * getQuantity(); }
    inline int64_t getFullModScience() const { return modScience * getQuantity(); }
    std::string getInfo();

private:
    int64_t modMinerals;
    int64_t modScience;
};