#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "mainmenu.h"
#include "gamescreen.h"

class MainWindow : public QWidget
{
  Q_OBJECT
private:
  int x, y;
  QPalette *pall = new QPalette();
  QStackedWidget *stackWidgets = new QStackedWidget();
  MainMenu *mainMenu = new MainMenu();
  GameScreen *gameScreen = new GameScreen();
  QVBoxLayout *layout = new QVBoxLayout();

public: 
  explicit MainWindow(QWidget *parent = nullptr);
public slots:
  void installMainMenu();
  void installGameScreen();
};

#endif // MAINWINDOW_H
