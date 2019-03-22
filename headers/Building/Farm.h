#pragma once

#include "Building.h"

class QFarm : public QBuilding
{
public:
    QFarm();
    ~QFarm() = default;

    inline void setModFood(int64_t m) { modFood = m; }

    inline int64_t getModFood() { return modFood; }
    inline int64_t getFullModFood() { return modFood * getQuantity(); }
    std::string getInfo();

private:
    int64_t modFood;
};
