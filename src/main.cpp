#include <QString>
#include <QtWidgets>
/* Layouts */
#define BUILDING_LAYOUT  1
#define MAIN_MENU_LAYOUT 2

#include "headers/conWidget/mainwindow.h"
#include "headers/world.h"

int main(int argc, char *argv[])
{

  QApplication a(argc, argv);

  MainWindow *window = new MainWindow();
  World *world = new World();

  window->addTextInformation(world->get());
 // window->addStackWidgets();

  window->addLayout(GENERAL_LAYOUT, QBoxLayout::LeftToRight);
  window->addTextLine("Построить -> ");
  window->addButton("Электростанция"); // id 0
  window->addButton("Шахта");          // id 1
  window->addButton("Ферма");          // id 2
  window->addButton("Лаборатория");    // id 3

  window->addLayout(GENERAL_LAYOUT, QBoxLayout::LeftToRight);
  window->addTextLine("Меню -> ");
  window->addButton("Следующий год"); // id 4
  window->addButton("Выход");          // id 5

  window->show();

  QObject::connect(window->getButton(0), &QPushButton::clicked, world, &World::buildEnergyStation);
  QObject::connect(window->getButton(1), &QPushButton::clicked, world, &World::buildMine);
  QObject::connect(window->getButton(2), &QPushButton::clicked, world, &World::buildFarm);
  QObject::connect(window->getButton(3), &QPushButton::clicked, world, &World::buildLab);
  QObject::connect(window->getButton(4), &QPushButton::clicked, world, &World::update);
  QObject::connect(window->getButton(5), &QPushButton::clicked, &a, &QApplication::quit);
  QObject::connect(world, &World::print, window, &MainWindow::setInformation);

  return a.exec();
}
