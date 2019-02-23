#ifndef ENERGYSTATION_H
#define ENERGYSTATION_H

#include "building.h"

class QEnergyStation : public QBuilding
{
    Q_OBJECT
public:
    explicit QEnergyStation(QBuilding *parent = nullptr);
    ~QEnergyStation() = default;

    inline void setModPollution(float m) { modPollution = m; }

    inline float getModPollution() { return modPollution; }
    float getFullModPollution();
    QString getInfo();

private:
    float modPollution;
};

#endif // ENERGYSTATION_H
