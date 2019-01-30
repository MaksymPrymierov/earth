#include <QString>
#include <QtWidgets>

#include "headers/world.h"

int main(int argc, char *argv[])
{

  QApplication a(argc, argv);
  const int x = 600, y = 200;

  QWidget *w = new QWidget(nullptr, Qt::Window);
  QPalette *pall = new QPalette();
  QLabel *info = new QLabel();
  QLabel *command = new QLabel();
  World *e = new World;

  QList<QPushButton*> buildButton;
  buildButton.append(new QPushButton("Электростанция"));
  buildButton.append(new QPushButton("Шахта"));
  buildButton.append(new QPushButton("Ферма"));
  buildButton.append(new QPushButton("Выход"));

  QList<QPushButton*>::iterator itButtons = buildButton.begin();

  info->setParent(w);
  command->setParent(w);

  for(int i = 0; itButtons != buildButton.end(); ++itButtons, ++i){
      buildButton[i]->setParent(w);
      pall->setColor(buildButton[i]->backgroundRole(), Qt::cyan);
      buildButton[i]->setPalette(*pall);
      buildButton[i]->setAutoFillBackground(true);
      buildButton[i]->setCursor(Qt::PointingHandCursor);
      buildButton[i]->setMaximumSize(110, 20);
      buildButton[i]->setMinimumSize(110, 20);
      buildButton[i]->move(x - (115 * (i + 1)), y - 25);
    }
  itButtons = buildButton.begin();

  pall->setColor(w->backgroundRole(), Qt::lightGray);
  w->setPalette(*pall);
  w->setWindowTitle("Сon Civilization");
  w->setFixedSize(x, y);
  w->setAutoFillBackground(true);

  info->setMaximumSize(x, y);
  info->move(20, 20);
  info->setText(e->get());
  info->setFrameStyle(QFrame::Box | QFrame::Plain);

  command->setMaximumSize(500, 40);
  command->move(5, y - 25);
  command->setText("Построить -> ");
  command->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);

  w->show();

  QObject::connect(buildButton[0], SIGNAL(clicked()), e, SLOT(buildEnergyStation()));
  QObject::connect(buildButton[1], SIGNAL(clicked()), e, SLOT(buildMine()));
  QObject::connect(buildButton[2], SIGNAL(clicked()), e, SLOT(buildFarm()));
  QObject::connect(buildButton[3], SIGNAL(clicked()), &a, SLOT(quit()));
  QObject::connect(e, SIGNAL(print(QString)), info, SLOT(setText(QString)));

  return a.exec();
}
