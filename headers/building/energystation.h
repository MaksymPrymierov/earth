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

  inline void setMod_Pollution(float m) { mod_pollution = m; }

  inline float getMod_Pollution() { return mod_pollution; }
  float getFullMod_Pollution();

  QString getInfo();
};

#endif // ENERGYSTATION_H
