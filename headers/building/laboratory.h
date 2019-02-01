#ifndef LABORATORY_H
#define LABORATORY_H

#include "building.h"

class Laboratory : public Building {
  Q_OBJECT
private:
  qint64 mod_minerals;
  qint64 mod_science;
public:
  explicit Laboratory(Building *parent = nullptr);
  ~Laboratory() = default;

  qint64 getMod_Minerals();
  qint64 getMod_Science();
  qint64 getFullMod_Minerals();
  qint64 getFullMod_Science();

  void setMod_Minerals(qint64 m);
  void setMod_Science(qint64 m);
};

#endif // LABORATORY_H
