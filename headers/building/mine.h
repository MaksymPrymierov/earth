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

  inline void setMod_Pollution(float m) { mod_pollution = m; }
  inline void setMod_Minerals(qint64 m) { mod_minerals = m; }

  inline float getMod_Pollution() { return mod_pollution; }
  inline qint64 getMod_Minerals() { return mod_minerals; }

  float getFullMod_Pollution();
  inline qint64 getFullMod_Minerals() { return mod_minerals * quantity; }

  QString getInfo();
};

#endif // MINE_H
