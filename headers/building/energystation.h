#ifndef ENERGYSTATION_H
#define ENERGYSTATION_H

#include "building.h"

class EnergyStation : public Building {
  Q_OBJECT
private:
  float mod_pollution;
public:
  explicit EnergyStation(Building *parent = nullptr);
  ~EnergyStation() = default;

  void setMod_Pollution(float m);

  float getMod_Pollution();
  float getFullMod_Pollution();
};

#endif // ENERGYSTATION_H
