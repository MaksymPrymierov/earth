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

  inline void setMod_Food(qint64 m) { mod_food = m; }

  inline qint64 getMod_Food() { return mod_food; }
  inline qint64 getFullMod_Food() { return mod_food * quantity; }
  QString getInfo();
};

#endif // FARM_H
