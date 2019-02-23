#ifndef FARM_H
#define FARM_H

#include "building.h"

class QFarm : public QBuilding
{
    Q_OBJECT
public:
    explicit QFarm(QBuilding *parent = nullptr);
    ~QFarm() = default;

    inline void setModFood(qint64 m) { modFood = m; }

    inline qint64 getModFood() { return modFood; }
    inline qint64 getFullModFood() { return modFood * getQuantity(); }
    QString getInfo();

private:
    qint64 modFood;
};

#endif // FARM_H
