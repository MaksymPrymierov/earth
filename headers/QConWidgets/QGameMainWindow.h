#pragma once

#include <QtWidgets>
#include "QMainMenu.h"
#include "QGameScreen.h"
#include "../QConResources.h"

class QGameMainWindow : public QWidget
{
    Q_OBJECT
public: 
    explicit QGameMainWindow(QConResources *res, QWidget *parent = nullptr);
    ~QGameMainWindow() = default;

public slots:
    void installMainMenu();
    void installGameScreen();

private:
    int x;
    int y;
    QPalette *pall = new QPalette();

    QGameScreen *gameScreen = new QGameScreen();
    QMainMenu *mainMenu = new QMainMenu();

    QStackedWidget *stackWidgets = new QStackedWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    QConResources *resources;
};
