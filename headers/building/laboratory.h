#ifndef LABORATORY_H
#define LABORATORY_H

#include "building.h"

class Laboratory : public Building {
  Q_OBJECT
private:
  qint64 mod_minerals, mod_science;
public:
  explicit Laboratory(Building *parent = nullptr);
  ~Laboratory() = default;

  inline void setMod_Minerals(qint64 m) { mod_science = m; }
  inline void setMod_Science(qint64 m) { mod_minerals = m; }

  inline qint64 getMod_Minerals() { return mod_science; }
  inline qint64 getMod_Science() { return mod_minerals; }
  inline qint64 getFullMod_Minerals() { return mod_science * quantity; }
  inline qint64 getFullMod_Science() { return mod_minerals * quantity; }

  QString getInfo();
};

#endif // LABORATORY_H
