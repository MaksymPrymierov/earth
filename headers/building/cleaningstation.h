#ifndef CLEANINGSTATION_H
#define CLEANINGSTATION_H

#include "building.h"

class CleaningStation : public Building {
  Q_OBJECT
private:
  qint64 mod_minerals;
  float mod_pollution;
public:
  explicit CleaningStation(Building *parent = nullptr);
  ~CleaningStation() = default;

  inline void setMod_Minerals(qint64 m) { mod_minerals = m; }
  inline void setMod_Pollution(float m) { mod_pollution = m; }

  inline qint64 getMod_Minerals() { return mod_minerals; }
  inline float getMod_Pollution() { return mod_pollution; }

  inline qint64 getFullMod_Minerals() { return mod_minerals * quantity; }
  inline float getFullMod_Pollution() { return mod_pollution * quantity; }

  QString getInfo();
};

#endif // CLEANINGSTATION_H
