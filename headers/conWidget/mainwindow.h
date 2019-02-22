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

  GameScreen *gameScreen = new GameScreen();
  MainMenu *mainMenu = new MainMenu();

  QStackedWidget *stackWidgets = new QStackedWidget();
  QVBoxLayout *layout = new QVBoxLayout();


public: 
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() = default;

public slots:
  void installMainMenu();
  void installGameScreen();

};

#endif // MAINWINDOW_H
