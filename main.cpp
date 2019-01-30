#include <QString>
#include <QtWidgets>

#include "world.h"

int main(int argc, char *argv[])
{

  int x = 600, y = 100;
  QApplication a(argc, argv);
  QMainWindow *w = new QMainWindow;
  QLabel *l = new QLabel;
  QList<QPushButton*> buttons;
  buttons.append(new QPushButton("Next Year"));
  buttons.append(new QPushButton("Build ES"));
  buttons.append(new QPushButton("Build Min"));

  QList<QPushButton*>::iterator itButtons = buttons.begin();

  World *e = new World;

  l->setParent(w);
  for(int i = 0; itButtons != buttons.end(); ++itButtons, ++i){
      buttons[i]->setParent(w);
      buttons[i]->setMaximumSize(60, 20);
      buttons[i]->move(600 - (65 * (i + 1)), 75);
      buttons[i]->show();
    }
  itButtons = buttons.begin();

  w->setFixedSize(x, y);

  l->setMaximumSize(x, y);
  l->move(1, 1);
  l->setText(e->get());

  w->show();
  l->show();

  QObject::connect(buttons[0], SIGNAL(clicked()), e, SLOT(update()));
  QObject::connect(buttons[1], SIGNAL(clicked()), e, SLOT(buildEnergyStation()));
  QObject::connect(buttons[2], SIGNAL(clicked()), e, SLOT(buildMine()));
  QObject::connect(e, SIGNAL(print(QString)), l, SLOT(setText(QString)));

  return a.exec();
}
