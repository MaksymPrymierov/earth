#ifndef BUILDING_H
#define BUILDING_H

#include <QObject>

class Building : public QObject {
Q_OBJECT
private:
  quint64 quantity;
  quint64 p_minarals;
  qint64  m_energy;
public:
  explicit Building(QObject *parent = nullptr);
  ~Building() = default;

  void setQuantity(quint64 q);
  void setP_Minarals(quint64 p);
  void setM_Energy(qint64 m);

  quint64 getQuantity();
  quint64 getP_Minarals();
  qint64  getM_Energy();

public slots:
  void build();
  void destroy();
};


#endif // BUILDING_H
