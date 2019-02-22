#ifndef BUILDING_H
#define BUILDING_H

#include <QObject>

class Building : public QObject {
  Q_OBJECT
protected:
  qint64 quantity, price, mod_energy;
public:
  explicit Building(QObject *parent = nullptr);
  ~Building() = default;

  inline void setQuantity(qint64 q) { quantity = q; }
  inline void setPrice(qint64 p) { price = p; }
  inline void setMod_Energy(qint64 m) { mod_energy = m; }

  inline qint64 getQuantity() { return quantity; }
  inline qint64 getPrice_Minerals() { return price; }
  inline qint64 getMod_Energy() { return mod_energy; }
  inline qint64 getFullPriece_Mineral() { return quantity * price; }
  inline qint64 getFullMod_Energy() { return quantity * mod_energy; }

public slots:
  inline void build() { ++quantity; }
  inline void destroy() { if(quantity != 0) --quantity; }
};


#endif // BUILDING_H
