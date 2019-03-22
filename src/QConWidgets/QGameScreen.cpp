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
    delete world;
    delete pall;
    delete header;
    delete footer;
    delete generalLayout;
    delete textPanel;
    delete mainMenuPanel;
    delete actionPanel;
    delete buildPanel;
    delete destroyPanel;
    delete sciencePanel;
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
    textPanel->addInfo(QInfo::Year, 0, 0, world->getInfoYear().data());
    textPanel->addInfo(QInfo::Population, 0, 1, world->getInfoPopulation().data());
    textPanel->addInfo(QInfo::Capacity, 0, 2, world->getInfoCapacity().data());
    textPanel->addInfo(QInfo::Energy, 1, 0, world->getInfoEnergy().data());
    textPanel->addInfo(QInfo::Minerals, 1, 1, world->getInfoMinerals().data());
    textPanel->addInfo(QInfo::Food, 1, 2, world->getInfoFood().data());
    textPanel->addInfo(QInfo::Pollution, 2, 0, world->getInfoPollution().data());
    textPanel->addInfo(QInfo::Solidarity, 2, 1, world->getInfoSolidarity().data());
    textPanel->addInfo(QInfo::Science, 2, 2, world->getInfoScience().data());
    textPanel->addInfo(QInfo::Risks, 3, 0, "Risks: ");
    textPanel->addInfo(QInfo::War, 3, 1, world->getInfoActionEvent(WorldActionEvents::War).data());
    textPanel->addInfo(QInfo::Epidemic, 3, 2,
                       world->getInfoActionEvent(WorldActionEvents::Epidemic).data());
    textPanel->addInfo(QInfo::Revolution, 3, 3,
                       world->getInfoActionEvent(WorldActionEvents::Revolution).data());
    textPanel->addInfo(QInfo::ActOfTerrorism, 4, 0,
                       world->getInfoActionEvent(WorldActionEvents::ActOfTerrorism).data());
    textPanel->addInfo(QInfo::AlienAttack, 4, 1,
                       world->getInfoActionEvent(WorldActionEvents::AlienAttack).data());
    textPanel->addInfo(QInfo::GlobalCataclysm, 4, 2,
                       world->getInfoActionEvent(WorldActionEvents::GlobalCataclysm).data());
    textPanel->addInfo(QInfo::GlobalAccident, 4, 3,
                       world->getInfoActionEvent(WorldActionEvents::GlobalAccident).data());
    textPanel->addInfo(QInfo::PastEvent, 5, 0,
                       ("Past event " + world->getCurrentEvent()).data());


    textPanel->setMinimumSize(600, 400);

    generalLayout->addWidget(textPanel);
}

void QGameScreen::updateInfoPanel()
{
    textPanel->getLabel(QInfo::Year)->setText(world->getInfoYear().data());
    textPanel->getLabel(QInfo::Population)->setText(world->getInfoPopulation().data());
    textPanel->getLabel(QInfo::Capacity)->setText(world->getInfoCapacity().data());
    textPanel->getLabel(QInfo::Energy)->setText(world->getInfoEnergy().data());
    textPanel->getLabel(QInfo::Minerals)->setText(world->getInfoMinerals().data());
    textPanel->getLabel(QInfo::Food)->setText(world->getInfoFood().data());
    textPanel->getLabel(QInfo::Pollution)->setText(world->getInfoPollution().data());
    textPanel->getLabel(QInfo::Solidarity)->setText(world->getInfoSolidarity().data());
    textPanel->getLabel(QInfo::Science)->setText(world->getInfoScience().data());
    textPanel->getLabel(QInfo::War)->
            setText(world->getInfoActionEvent(WorldActionEvents::War).data());
    textPanel->getLabel(QInfo::Epidemic)->
            setText(world->getInfoActionEvent(WorldActionEvents::Epidemic).data());
    textPanel->getLabel(QInfo::Revolution)->
            setText(world->getInfoActionEvent(WorldActionEvents::Revolution).data());
    textPanel->getLabel(QInfo::ActOfTerrorism)->
            setText(world->getInfoActionEvent(WorldActionEvents::ActOfTerrorism).data());
    textPanel->getLabel(QInfo::AlienAttack)->
            setText(world->getInfoActionEvent(WorldActionEvents::AlienAttack).data());
    textPanel->getLabel(QInfo::GlobalCataclysm)->
            setText(world->getInfoActionEvent(WorldActionEvents::GlobalCataclysm).data());
    textPanel->getLabel(QInfo::GlobalAccident)->
            setText(world->getInfoActionEvent(WorldActionEvents::GlobalAccident).data());
    textPanel->getLabel(QInfo::PastEvent)->
            setText(("Past event: " + world->getCurrentEvent()).data());
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
