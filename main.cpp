#include <QString>
#include <QtWidgets>

#include "earth.h"

int main(int argc, char *argv[])
{

  QApplication a(argc, argv);
  Earth::Earth *e = new Earth::Earth();
  QLabel *l = new QLabel;
  QPushButton *cmd = new QPushButton("Next year");

  l->setText(e->get());

  l->show();
  cmd->show();

  QObject::connect(cmd, SIGNAL(clicked()), e, SLOT(update()));
  QObject::connect(e, SIGNAL(print(QString)), l, SLOT(setText(QString)));

  return a.exec();
}
