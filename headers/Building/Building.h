#pragma once

#include <string>
#include <cstdint>

class Building
{
public:
    Building();
    ~Building() = default;

    inline void setQuantity(int64_t q) { quantity = q; }
    inline void setPrice(int64_t p) { price = p; }
    inline void setModEnergy(int64_t m) { modEnergy = m; }

    inline int64_t getQuantity() const { return quantity; }
    inline int64_t getPriceMinerals() const { return price; }
    inline int64_t getModEnergy() const { return modEnergy; }
    inline int64_t getFullPrieceMineral() const { return quantity * price; }
    inline int64_t getFullModEnergy() const { return quantity * modEnergy; }

    inline void build() { ++quantity; }
    inline void destroy() { if (quantity != 0) --quantity; }

private:
    int64_t quantity;
    int64_t price;
    int64_t modEnergy;
};
