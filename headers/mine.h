#ifndef MINE_H
#define MINE_H

#include "building.h"

class Mine : public Building {
Q_OBJECT
private:
  float mod_pollution;
  qint64 mod_minerals;
public:
  explicit Mine(Building *parent = nullptr);
  ~Mine() = default;

  void setMod_Pollution(float m);
  void setMod_Minerals(qint64 m);

  float getMod_Pollution();
  qint64 getMod_Minerals();
  float getFullMod_Pollution();
  qint64 getFullMod_Minerals();
};

#endif // MINE_H
