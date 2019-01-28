#include "world.h"

World::World(QObject *parent) : QObject(parent){
  year = 0;
  population = 300;
  energy = 0;
  minarals = 1000;
  food = 1000;
  pollution = 0;
  solidarity = 60;
  science = 0;
}

QString World::get(){
  QString str;
  str.sprintf("Год: %llu, Люди: %llu тыс.\n\
               Енергия: %llu, Минералы: %llu, Еда: %llu\n\
               Загрязнение: %u %%, Сплоченность: %u %%\n\
               Наука: %llu\n\
               Здания: %llu",
               year, population, energy, minarals, food,\
               pollution, solidarity, science, b.getQuantity());
  return str;
}

void World::update(){
  ++year;
  ++population;

  emit print(get());
}

void World::build(){
  b.build();
  update();
}
