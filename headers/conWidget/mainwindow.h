#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "../world.h"

class MainWindow : public QWidget
{
  Q_OBJECT
private:
  int x, y;
  QLabel *info = new QLabel(this);
  QLabel *command = new QLabel(this);
  QPalette *pall = new QPalette();
  QList<QPushButton*> *buildButtons = new QList<QPushButton*>();
  QVBoxLayout *vBoxLayout = new QVBoxLayout();
  QHBoxLayout *hBoxLayout = new QHBoxLayout();

  World *world = new World();

public: 
  explicit MainWindow(QWidget *parent = nullptr);
  void addBuildButton(QString text);
  void connectObjects();
  void addLayaout();

private:
  void addTextInformation();
  void addTextCommand();

signals:

public slots:
};

#endif // MAINWINDOW_H
