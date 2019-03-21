#include "headers/QConWidgets/QGameMainWindow.h"
#include <QtCore/QCoreApplication>

QGameMainWindow::QGameMainWindow(QConResources *res, QWidget *parent) :
    QWidget(parent), x(1366), y(768), resources(res)
{
    setWindowFlag(Qt::Window);
    setWindowState(Qt::WindowFullScreen);
    setAutoFillBackground(true);

    setWindowTitle("Decisive Year");
    setFixedSize(x, y);

    mainMenu->resize(x, y);
    stackWidgets->setParent(this);
    stackWidgets->addWidget(mainMenu);
    stackWidgets->addWidget(gameScreen);

    installMainMenu();

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
    stackWidgets->setCurrentWidget(gameScreen);
    pall->setColor(backgroundRole(), Qt::lightGray);
    setPalette(*pall);
}

void QGameMainWindow::installMainMenu()
{
    stackWidgets->setCurrentWidget(mainMenu);
    pall->setBrush(backgroundRole(), *(resources->getMainMenuTheme()));
    setPalette(*pall);
}
