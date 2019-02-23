#include "headers/conWidget/mainwindow.h"
#include <QtCore/QCoreApplication>

QGameMainWindow::QGameMainWindow(QWidget *parent) :
    QWidget(parent), x(1024), y(768)
{
    setWindowFlag(Qt::Window);

    pall->setColor(backgroundRole(), Qt::gray);
    setPalette(*pall);
    setAutoFillBackground(true);

    setWindowTitle("Con Civilization");
    setFixedSize(x, y);

    mainMenu->resize(x, y);
    stackWidgets->setParent(this);
    stackWidgets->addWidget(mainMenu);

    layout->addWidget(stackWidgets);
    setLayout(layout);

    QObject::connect(mainMenu, &QMainMenu::clickedExit, [] () { QCoreApplication::quit(); });
    QObject::connect(mainMenu, &QMainMenu::clickedNewGame, this,
                     &QGameMainWindow::installGameScreen);
    QObject::connect(gameScreen, &QGameScreen::clickedMenu, this,
                     &QGameMainWindow::installMainMenu);
}

void QGameMainWindow::installGameScreen()
{
    stackWidgets->addWidget(gameScreen);
    stackWidgets->setCurrentWidget(gameScreen);
}

void QGameMainWindow::installMainMenu()
{
    stackWidgets->setCurrentWidget(mainMenu);
}
