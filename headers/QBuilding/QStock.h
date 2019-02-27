#pragma once

#include "QBuilding.h"

class QStock : public QBuilding
{
public:
    QStock();
    ~QStock() = default;

    inline int64_t getCapacity() { return capacity; }
    inline int64_t getFullCapacity() { return capacity * getQuantity(); }
    std::string getInfo();

private:
    int64_t capacity;
};
