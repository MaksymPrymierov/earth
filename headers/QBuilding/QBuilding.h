#pragma once

#include <QObject>

class QBuilding : public QObject
{
    Q_OBJECT
public:
    explicit QBuilding(QObject *parent = nullptr);
    ~QBuilding() = default;

    inline void setQuantity(qint64 q) { quantity = q; }
    inline void setPrice(qint64 p) { price = p; }
    inline void setModEnergy(qint64 m) { modEnergy = m; }

    inline qint64 getQuantity() { return quantity; }
    inline qint64 getPriceMinerals() { return price; }
    inline qint64 getModEnergy() { return modEnergy; }
    inline qint64 getFullPrieceMineral() { return quantity * price; }
    inline qint64 getFullModEnergy() { return quantity * modEnergy; }

public slots:
    inline void build() { ++quantity; }
    inline void destroy() { if (quantity != 0) --quantity; }

private:
    qint64 quantity;
    qint64 price;
    qint64 modEnergy;
};
