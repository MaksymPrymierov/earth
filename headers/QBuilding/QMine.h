#pragma once

#include "QBuilding.h"

class QMine : public QBuilding
{
    Q_OBJECT
public:
    explicit QMine(QBuilding *parent = nullptr);
    ~QMine() = default;

    inline void setModPollution(float m) { modPollution = m; }
    inline void setModMinerals(qint64 m) { modMinerals = m; }

    inline float getModPollution() { return modPollution; }
    inline qint64 getModMinerals() { return modMinerals; }
    float getFullModPollution();
    inline qint64 getFullModMinerals() { return modMinerals * getQuantity(); }
    QString getInfo();

private:
    float modPollution;
    qint64 modMinerals;
};
