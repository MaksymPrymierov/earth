#include "headers/conWidget/mainwindow.h"
#include <QtCore/QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
  QWidget(parent),
  x(1024),
  y(768) {
  setWindowFlag(Qt::Window);
  pall->setColor(backgroundRole(), Qt::gray);
  setPalette(*pall);
  setWindowTitle("Con Civilization");
  setMinimumSize(x, y);
  setAutoFillBackground(true);
  mainMenu->resize(x, y);
  stackWidgets->setParent(this);
  stackWidgets->addWidget(mainMenu);

  layout->addWidget(stackWidgets);
  setLayout(layout);

  QObject::connect(mainMenu, &MainMenu::clickedExit, [] () { QCoreApplication::quit(); });
  QObject::connect(mainMenu, &MainMenu::clickedNewGame, this, &MainWindow::installGameScreen);
  QObject::connect(gameScreen, &GameScreen::clickedMenu, this, &MainWindow::installMainMenu);
}

void MainWindow::installGameScreen() {
  stackWidgets->addWidget(gameScreen);
  stackWidgets->setCurrentWidget(gameScreen);
}

void MainWindow::installMainMenu() {
  stackWidgets->setCurrentWidget(mainMenu);
}
