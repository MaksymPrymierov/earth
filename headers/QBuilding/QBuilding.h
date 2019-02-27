#pragma once

#include <string>
#include <cstdint>

class QBuilding
{
public:
    QBuilding();
    ~QBuilding() = default;

    inline void setQuantity(int64_t q) { quantity = q; }
    inline void setPrice(int64_t p) { price = p; }
    inline void setModEnergy(int64_t m) { modEnergy = m; }

    inline int64_t getQuantity() { return quantity; }
    inline int64_t getPriceMinerals() { return price; }
    inline int64_t getModEnergy() { return modEnergy; }
    inline int64_t getFullPrieceMineral() { return quantity * price; }
    inline int64_t getFullModEnergy() { return quantity * modEnergy; }

    inline void build() { ++quantity; }
    inline void destroy() { if (quantity != 0) --quantity; }

private:
    int64_t quantity;
    int64_t price;
    int64_t modEnergy;
};
