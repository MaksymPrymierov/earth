#include "earth.h"
#include <cstdlib>

Earth::Earth::Earth(QObject *parent) : QObject(parent){
  info = {2019, 7678174656, 0, per, nullEvent};
}

void Earth::Earth::pEvent(Event e){
  info.currentEvent = e;
  double populationChanges;

  switch (int(e)) {
    case 2:
      populationChanges = -(rand() % 5 + 1);
      break;
    case 3:
      populationChanges = -(rand() % 15 + 1);
      break;
    case 4:
      populationChanges = -(rand() % 50 + 1);
      break;
    case 5:
      populationChanges = -(rand() % 80 + 1);
      break;
    case 6:
      populationChanges = rand() % 5 + 1;
      break;
    case 7:
      populationChanges = rand() % 15 + 1;
      break;
    case 8:
      populationChanges = rand() % 50 + 1;
      break;
    case 9:
      populationChanges = rand() % 80 + 1;
      break;
    default:
      populationChanges = 0;
    }

  info.percentageOfPopulationGrowth = per + populationChanges;
}


void Earth::Earth::update(){
  ++info.year;
  info.population += quint64(info.populationGrowth);
  info.populationGrowth = qint64(info.population * info.percentageOfPopulationGrowth / 100);

  pEvent(Event(rand() % 9 + 1));

  emit print(get());
}

QString Earth::Earth::get(){
  QString s;
  s.sprintf("Событие: \nГод: %llu, Население планеты: %llu\nПрирост населения в следущем году: %lld, Процент прироста в этом году: %lf", info.year, info.population, info.populationGrowth, info.percentageOfPopulationGrowth);
  return s;
}
