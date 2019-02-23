#pragma once

#include "QBuilding.h"

class QCleaningStation : public QBuilding
{
    Q_OBJECT
public:
    explicit QCleaningStation(QBuilding *parent = nullptr);
    ~QCleaningStation() = default;

    inline void setModMinerals(qint64 m) { modMinerals = m; }
    inline void setModPollution(float m) { modPollution = m; }

    inline qint64 getModMinerals() { return modMinerals; }
    inline float getModPollution() { return modPollution; }

    inline qint64 getFullModMinerals() { return modMinerals * getQuantity(); }
    inline float getFullModPollution() { return modPollution * getQuantity(); }
    QString getInfo();

private:
    qint64 modMinerals;
    float modPollution;
};
