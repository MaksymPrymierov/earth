#include <QString>
#include <QtWidgets>

#include "headers/world.h"

int main(int argc, char *argv[])
{

  QApplication a(argc, argv);
  const int x = 600, y = 200;

  QWidget *w = new QWidget(nullptr, Qt::Window | Qt::WindowMaximizeButtonHint);
  QPalette *pall = new QPalette();
  QLabel *info = new QLabel();
  QLabel *command = new QLabel();
  World *e = new World;

  QList<QPushButton*> buttons;
//  buttons.append(new QPushButton("Следующий год"));
  buttons.append(new QPushButton("Электростанция"));
  buttons.append(new QPushButton("Шахта"));
  buttons.append(new QPushButton("Ферма"));

  QList<QPushButton*>::iterator itButtons = buttons.begin();

  info->setParent(w);
  command->setParent(w);
  for(int i = 0; itButtons != buttons.end(); ++itButtons, ++i){
      buttons[i]->setParent(w);
      pall->setColor(buttons[i]->backgroundRole(), Qt::blue);
      buttons[i]->setPalette(*pall);
      buttons[i]->setCursor(Qt::PointingHandCursor);
      buttons[i]->setMaximumSize(110, 20);
      buttons[i]->setMinimumSize(110, 20);
      buttons[i]->move(x - (115 * (i + 1)), y - 25);
    }
  itButtons = buttons.begin();

  pall->setColor(w->backgroundRole(), Qt::cyan);
  w->setPalette(*pall);
  w->setWindowTitle("Сon Civilization");
  w->setFixedSize(x, y);
  w->setAutoFillBackground(true);

  info->setMaximumSize(x, y);
  info->move(20, 20);
  info->setText(e->get());
  info->setFrameStyle(QFrame::Box | QFrame::Plain);

  command->setMaximumSize(80, 40);
  command->move(5, y - 25);
  command->setText("Построить -> ");
  command->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);

  w->show();

 // QObject::connect(buttons[0], SIGNAL(clicked()), e, SLOT(update()));
  QObject::connect(buttons[0], SIGNAL(clicked()), e, SLOT(buildEnergyStation()));
  QObject::connect(buttons[1], SIGNAL(clicked()), e, SLOT(buildMine()));
  QObject::connect(buttons[2], SIGNAL(clicked()), e, SLOT(buildFarm()));
  QObject::connect(e, SIGNAL(print(QString)), info, SLOT(setText(QString)));

  return a.exec();
}
