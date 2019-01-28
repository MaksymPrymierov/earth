#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "building.h"


class World : public QObject
{
  Q_OBJECT

private:
  quint64 year;
  quint64 population;
  quint64 energy;
  quint64 minarals;
  quint64 food;
  quint8  pollution;
  quint8  solidarity;
  quint64 science;

  Building b;

public:
  explicit World(QObject *parent = nullptr);
  ~World() = default;

  QString get();

signals:
  void print(QString);

public slots:
  void update();
  void build();
};

#endif // WORLD_H
