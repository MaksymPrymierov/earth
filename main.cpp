#include <QString>
#include <QtWidgets>

#include "world.h"

int main(int argc, char *argv[])
{

  QApplication a(argc, argv);
  QMainWindow *w = new QMainWindow;
  QLabel *l = new QLabel;
  QPushButton *y = new QPushButton("Next year");
  QPushButton *b = new QPushButton("Build");

  World *e = new World;

  l->setParent(w);
  y->setParent(w);
  b->setParent(w);

  l->setMaximumSize(600, 100);
  y->setMaximumSize(60, 20);
  b->setMaximumSize(60, 20);

  w->setFixedSize(600, 100);

  l->move(1, 1);
  y->move(540, 80);
  b->move(480, 80);

  l->setText(e->get());

  w->show();
  l->show();
  y->show();
  b->show();

  QObject::connect(y, SIGNAL(clicked()), e, SLOT(update()));
  QObject::connect(b, SIGNAL(clicked()), e, SLOT(build()));
  QObject::connect(e, SIGNAL(print(QString)), l, SLOT(setText(QString)));

  return a.exec();
}
