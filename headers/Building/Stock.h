#pragma once

#include "Building.h"

class Stock : public Building
{
public:
    Stock();
    ~Stock() = default;

    inline int64_t getCapacity() const { return capacity; }
    inline int64_t getFullCapacity() const { return capacity * getQuantity(); }
    std::string getInfo();

private:
    int64_t capacity;
};
