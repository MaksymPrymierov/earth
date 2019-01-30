#ifndef FARM_H
#define FARM_H

#include "building.h"

class Farm : public Building {
  Q_OBJECT
private:
  qint64 mod_food;
public:
  explicit Farm(Building *parent = nullptr);
  ~Farm() = default;

  void setMod_Food(qint64 m);

  qint64 getMod_Food();
  qint64 getFullMod_Food();
};

#endif // FARM_H
