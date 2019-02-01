#include <QString>
#include <QtWidgets>

#include "headers/conWidget/mainwindow.h"

int main(int argc, char *argv[])
{

  QApplication a(argc, argv);

  MainWindow *window = new MainWindow();

  window->connectObjects();

  window->show();

  return a.exec();
}
