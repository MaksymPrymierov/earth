#ifndef BUILDING_H
#define BUILDING_H

#include <QObject>

class Building : public QObject {
  Q_OBJECT
private:
  qint64 quantity, price_minerals, mod_energy;
public:
  explicit Building(QObject *parent = nullptr);
  ~Building() = default;

  void setQuantity(qint64 q);
  void setPrice_Minerals(qint64 p);
  void setMod_Energy(qint64 m);

  qint64 getQuantity();
  qint64 getPrice_Minerals();
  qint64 getMod_Energy();
  qint64 getFullPriece_Mineral();
  qint64 getFullMod_Energy();

public slots:
  void build();
  void destroy();
};


#endif // BUILDING_H
