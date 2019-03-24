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
    delete textPanel;
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
    textPanel->addInfo(QInfo::InfoYear, 0, 0, "Year");
    textPanel->addInfo(QInfo::InfoPopulation, 0, 1, "Population");
    textPanel->addInfo(QInfo::InfoEnergy, 0, 2, "Energy");
    textPanel->addInfo(QInfo::InfoMinerals, 0, 3, "Minerals");
    textPanel->addInfo(QInfo::InfoFood, 0, 4, "Food");
    textPanel->addInfo(QInfo::InfoCapacity, 0, 5, "Capacity");
    textPanel->addInfo(QInfo::InfoSolidarity, 0, 6, "Solidarity");
    textPanel->addInfo(QInfo::InfoPollution, 0, 7, "Pollution");
    textPanel->addInfo(QInfo::InfoScience, 0, 8, "Science");

    textPanel->addInfo(QInfo::Year, 1, 0, QString::asprintf("%ld", world->getYear()));
    textPanel->addInfo(QInfo::Population, 1, 1, QString::asprintf("%ld", world->getPopulation()));
    textPanel->addInfo(QInfo::Energy, 1, 2, QString::asprintf("%ld [%ld]", world->getEnergy(),
                                                              world->getModEnergy()));
    textPanel->addInfo(QInfo::Minerals, 1, 3, QString::asprintf("%ld [%ld]", world->getMinerals(),
                                                                world->getModMinerals()));
    textPanel->addInfo(QInfo::Food, 1, 4, QString::asprintf("%ld [%ld]", world->getFood(),
                                                            world->getModFood()));
    textPanel->addInfo(QInfo::Capacity, 1, 5, QString::asprintf("%ld", world->getCapacity()));
    textPanel->addInfo(QInfo::Solidarity, 1, 6, QString::asprintf("%3.2f %%",
                                                                  double(world->getSolidarity())));
    textPanel->addInfo(QInfo::Pollution, 1, 7,
                       QString::asprintf("%3.2f %% [%3.2f %%]", double(world->getPolltion()),
                                         double(world->getModPollution())));
    textPanel->addInfo(QInfo::Science, 1, 8, QString::asprintf("%ld [%ld]", world->getScience(),
                                                               world->getModScience()));

    textPanel->addInfo(QInfo::War, 2, 0, world->getInfoActionEvent(WorldActionEvents::War).data());
    textPanel->addInfo(QInfo::Epidemic, 2, 1,
                       world->getInfoActionEvent(WorldActionEvents::Epidemic).data());
    textPanel->addInfo(QInfo::Revolution, 2, 2,
                       world->getInfoActionEvent(WorldActionEvents::Revolution).data());
    textPanel->addInfo(QInfo::ActOfTerrorism, 2, 3,
                       world->getInfoActionEvent(WorldActionEvents::ActOfTerrorism).data());
    textPanel->addInfo(QInfo::AlienAttack, 2, 4,
                       world->getInfoActionEvent(WorldActionEvents::AlienAttack).data());
    textPanel->addInfo(QInfo::GlobalCataclysm, 2, 5,
                       world->getInfoActionEvent(WorldActionEvents::GlobalCataclysm).data());
    textPanel->addInfo(QInfo::GlobalAccident, 2, 6,
                       world->getInfoActionEvent(WorldActionEvents::GlobalAccident).data());
    textPanel->addInfo(QInfo::PastEvent, 2, 7,
                       ("Past event " + world->getCurrentEvent()).data());

    textPanel->setMinimumSize(600, 400);

    generalLayout->addWidget(textPanel);
}

void QGameScreen::updateInfoPanel()
{
    textPanel->updateInfo(QInfo::Year, QString::asprintf("%ld", world->getYear()));
    textPanel->updateInfo(QInfo::Population, QString::asprintf("%ld", world->getPopulation()));
    textPanel->updateInfo(QInfo::Energy, QString::asprintf("%ld [%ld]", world->getEnergy(),
                                                           world->getModEnergy()));
    textPanel->updateInfo(QInfo::Minerals, QString::asprintf("%ld [%ld]", world->getMinerals(),
                                                             world->getModMinerals()));
    textPanel->updateInfo(QInfo::Food, QString::asprintf("%ld [%ld]", world->getFood(),
                                                         world->getModFood()));
    textPanel->updateInfo(QInfo::Capacity, QString::asprintf("%ld", world->getCapacity()));
    textPanel->updateInfo(QInfo::Solidarity, QString::asprintf("%3.2f %%",
                                                               double(world->getSolidarity())));
    textPanel->updateInfo(QInfo::Pollution,
                          QString::asprintf("%3.2f %% [%3.2f %%]", double(world->getPolltion()),
                                            double(world->getModPollution())));
    textPanel->updateInfo(QInfo::Science, QString::asprintf("%ld [%ld]", world->getScience(),
                                                            world->getModScience()));

    textPanel->updateInfo(QInfo::War, world->getInfoActionEvent(WorldActionEvents::War).data());
    textPanel->updateInfo(QInfo::Epidemic,
                          world->getInfoActionEvent(WorldActionEvents::Epidemic).data());
    textPanel->updateInfo(QInfo::Revolution,
                          world->getInfoActionEvent(WorldActionEvents::Revolution).data());
    textPanel->updateInfo(QInfo::ActOfTerrorism,
                          world->getInfoActionEvent(WorldActionEvents::ActOfTerrorism).data());
    textPanel->updateInfo(QInfo::AlienAttack,
                          world->getInfoActionEvent(WorldActionEvents::AlienAttack).data());
    textPanel->updateInfo(QInfo::GlobalCataclysm,
                          world->getInfoActionEvent(WorldActionEvents::GlobalCataclysm).data());
    textPanel->updateInfo(QInfo::GlobalAccident,
                          world->getInfoActionEvent(WorldActionEvents::GlobalAccident).data());
    textPanel->updateInfo(QInfo::PastEvent,
                          ("Past event " + world->getCurrentEvent()).data());
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
