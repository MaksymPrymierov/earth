#include "headers/QConWidgets/QGameScreen.h"
#include <QtCore/QCoreApplication>

QGameScreen::QGameScreen(QWidget *parent) :
    QWidget(parent)
{
    pall->setColor(backgroundRole(), Qt::gray);
    setPalette(*pall);

    installHeader();
    installInfoPanel();
    installFooter();

    handlerMenuPanel();
    handlerActionPanel();
    handlerBuildPanel();
    handlerDestroyPanel();
    handlerSciencePanel();

    header->addWidget(mainMenuPanel);
    header->setCurrentWidget(mainMenuPanel);

    footer->addWidget(actionPanel);
    footer->addWidget(buildPanel);
    footer->addWidget(destroyPanel);
    footer->addWidget(sciencePanel);
    footer->setCurrentWidget(actionPanel);

    setLayout(generalLayout);
}

QGameScreen::~QGameScreen()
{
    delete pall;
    delete header;
    delete footer;
    delete generalLayout;
    delete infoPanel;
    delete mainMenuPanel;
    delete actionPanel;
    delete buildPanel;
    delete destroyPanel;
    delete sciencePanel;
    delete world;
}

void QGameScreen::handlerMenuPanel()
{
    QObject::connect(mainMenuPanel->getButton(QButton::ExitToMenu), &QPushButton::clicked,
                     [this] () { emit clickedMenu(); });
    QObject::connect(mainMenuPanel->getButton(QButton::Exit), &QPushButton::clicked,
                     [] () { QCoreApplication::quit(); });

}

void QGameScreen::handlerActionPanel()
{
    QObject::connect(actionPanel->getButton(QButton::Building), &QPushButton::clicked, this,
                     &QGameScreen::showBuildPanel);
    QObject::connect(actionPanel->getButton(QButton::Destroy), &QPushButton::clicked, this,
                     &QGameScreen::showDestroyPanel);
    QObject::connect(actionPanel->getButton(QButton::Science), &QPushButton::clicked, this,
                     &QGameScreen::showSciencePanel);
}

void QGameScreen::handlerBuildPanel()
{
    QObject::connect(buildPanel->getButton(QButton::PowerStation), &QPushButton::clicked,
                     [this] () { world->buildEnergyStation(); });
    QObject::connect(buildPanel->getButton(QButton::Mine), &QPushButton::clicked,
                     [this] () { world->buildMine(); });
    QObject::connect(buildPanel->getButton(QButton::Farm), &QPushButton::clicked,
                     [this] () { world->buildFarm(); });
    QObject::connect(buildPanel->getButton(QButton::Laboratory), &QPushButton::clicked,
                     [this] () { world->buildLab(); });
    QObject::connect(buildPanel->getButton(QButton::CleaningStation), &QPushButton::clicked,
                     [this] () { world->buildCleaningStation(); });
    QObject::connect(buildPanel->getButton(QButton::Stock), &QPushButton::clicked,
                     [this] () { world->buildStock(); });
    QObject::connect(buildPanel->getButton(QButton::Cancel), &QPushButton::clicked,
                     [this] () { this->showActionPanel(); });
}

void QGameScreen::handlerDestroyPanel()
{
    QObject::connect(destroyPanel->getButton(QButton::PowerStation), &QPushButton::clicked,
                     [this] () { world->destroyEnergyStation(); });
    QObject::connect(destroyPanel->getButton(QButton::Mine), &QPushButton::clicked,
                     [this] () { world->destroyMine(); });
    QObject::connect(destroyPanel->getButton(QButton::Farm), &QPushButton::clicked,
                     [this] () { world->destroyFarm(); });
    QObject::connect(destroyPanel->getButton(QButton::Laboratory), &QPushButton::clicked,
                     [this] () { world->destroyLab(); });
    QObject::connect(destroyPanel->getButton(QButton::CleaningStation), &QPushButton::clicked,
                     [this] () { world->destroyCleaningStation(); });
    QObject::connect(destroyPanel->getButton(QButton::Stock), &QPushButton::clicked,
                     [this] () { world->destroyStock(); });
    QObject::connect(destroyPanel->getButton(QButton::Cancel), &QPushButton::clicked,
                     [this] () { this->showActionPanel(); });
}

void QGameScreen::handlerSciencePanel()
{
    QObject::connect(sciencePanel->getButton(QButton::Cancel), &QPushButton::clicked,
                     [this] () { this->showActionPanel(); });
}

void QGameScreen::installHeader()
{
    generalLayout->addWidget(header);
}

void QGameScreen::installFooter()
{
    generalLayout->addWidget(footer);
}

void QGameScreen::installInfoPanel()
{
    generalLayout->addWidget(infoPanel);
}

void QGameScreen::updateInfoPanel()
{
    infoPanel->update();
}

void QGameScreen::showBuildPanel()
{
    footer->setCurrentWidget(buildPanel);
}

void QGameScreen::showActionPanel()
{
    footer->setCurrentWidget(actionPanel);
}

void QGameScreen::showMenuPanel()
{
    header->setCurrentWidget(mainMenuPanel);
}

void QGameScreen::showDestroyPanel()
{
    footer->setCurrentWidget(destroyPanel);
}

void QGameScreen::showSciencePanel()
{
    footer->setCurrentWidget(sciencePanel);
}

bool QGameScreen::event(QEvent *event)
{
    if (event->type() == world->WorldEvent) {
        updateInfoPanel();
        return true;
    }

    return QWidget::event(event);
}
