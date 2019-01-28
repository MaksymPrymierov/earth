#ifndef EARTH_H
#define EARTH_H

#include <QDataStream>
#include <QObject>

namespace Earth {

  enum Event{
  nullEvent = 1,
  war,
  epidemic,
  cataclysm,
  meteorFalling,
  goldenAge,
  stability,
  revolutionaryScientificDiscovery,
  promtingPowerToBreed
  };

  class Earth : public QObject {
  Q_OBJECT
  private:
    const double per = 1.2;
    struct Info{
    quint64 year;
    quint64 population;
    qint64 populationGrowth;
    double percentageOfPopulationGrowth;
    Event currentEvent;
    };

    struct Info info;
    void pEvent(Event e);

  public:
    explicit Earth(QObject *parent = nullptr);
    ~Earth() = default;
    QString get();

  signals:
    void print(QString);

  public slots:
    void update();
  };
};

#endif // EARTH_H
