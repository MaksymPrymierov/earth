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

    addMenuPanel();
    addActionPanel();
    addBuildPanel();

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
}

void QGameScreen::addMenuPanel()
{
    QButtonsPanel *p = new QButtonsPanel();

    p->addButton(QButton::Save, 0, 0, "Save");
    p->addButton(QButton::Load, 0, 1, "Load");
    p->addButton(QButton::ExitToMenu, 0, 2, "Exit to Menu");
    p->addButton(QButton::Exit, 0, 3, "Exit");

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[QButtonPanel::Menu] = p;
    header->addWidget(p);
    header->setCurrentWidget(p);

#define button(x) buttonsPanels[QButtonPanel::Menu]->getButton(x)

    QObject::connect(button(QButton::ExitToMenu), &QPushButton::clicked,
                     [this] () { emit clickedMenu(); });
    QObject::connect(button(QButton::Exit), &QPushButton::clicked,
                     [] () { QCoreApplication::quit(); });

#undef button
}

void QGameScreen::addActionPanel()
{
    QButtonsPanel *p = new QButtonsPanel();

    p->setTitle("Select an action");

    p->addButton(QButton::Building, 0, 0, "Building");
    p->addButton(QButton::Destroy, 0, 1, "Destroy");
    p->addButton(QButton::Science, 0, 2, "Science");
    p->addButton(QButton::Events, 0, 3, "Events");

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[QButtonPanel::Action] = p;
    footer->addWidget(p);
    footer->setCurrentWidget(p);

#define button(x) buttonsPanels[QButtonPanel::Action]->getButton(x)

    QObject::connect(button(QButton::Building), &QPushButton::clicked, this,
                     &QGameScreen::showBuildPanel);

#undef button
}

void QGameScreen::addBuildPanel()
{
    QButtonsPanel *p = new QButtonsPanel();

    p->setTitle("Building");

    p->addButton(QButton::PowerStation, 0, 0, "Power station");
    p->addButton(QButton::Mine, 0, 1, "Mine");
    p->addButton(QButton::Farm, 0, 2, "Farm");
    p->addButton(QButton::Laboratory, 0, 3, "Laboratory");
    p->addButton(QButton::CleaningStation, 0, 4, "Cleaning Station");
    p->addButton(QButton::Cancel, 0, 5, "Cancel");

    p->addInfo(QButton::PowerStation, 1, 0, world->getInfoEnergyStation());
    p->addInfo(QButton::Mine, 1, 1, world->getInfoMine());
    p->addInfo(QButton::Farm, 1, 2, world->getInfoFarm());
    p->addInfo(QButton::Laboratory, 1, 3, world->getInfoLab());
    p->addInfo(QButton::CleaningStation, 1, 4, world->getInfoCleaningStation());

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[QButtonPanel::Building] = p;
    footer->addWidget(p);

#define button(x) buttonsPanels[QButtonPanel::Building]->getButton(x)
#define label(x, y)  buttonsPanels[QButtonPanel::Building]->getLabel(x)->setText(y)

    QObject::connect(button(QButton::PowerStation), &QPushButton::clicked, world,
                     &QWorld::buildEnergyStation);
    QObject::connect(button(QButton::Mine), &QPushButton::clicked, world, &QWorld::buildMine);
    QObject::connect(button(QButton::Farm), &QPushButton::clicked, world, &QWorld::buildFarm);
    QObject::connect(button(QButton::Laboratory), &QPushButton::clicked, world, &QWorld::buildLab);
    QObject::connect(button(QButton::CleaningStation), &QPushButton::clicked, world,
                     &QWorld::buildCleaningStation);
    QObject::connect(button(QButton::Cancel), &QPushButton::clicked, this,
                     &QGameScreen::showActionPanel);

    QObject::connect(button(QButton::PowerStation), &QPushButton::clicked,
                     [this] () { label(QButton::PowerStation, world->getInfoEnergyStation()); });
    QObject::connect(button(QButton::Mine), &QPushButton::clicked,
                     [this] () { label(QButton::Mine, world->getInfoMine()); });
    QObject::connect(button(QButton::Farm), &QPushButton::clicked,
                     [this] () { label(QButton::Farm, world->getInfoFarm()); });
    QObject::connect(button(QButton::Laboratory), &QPushButton::clicked,
                     [this] () { label(QButton::Laboratory, world->getInfoLab()); });
    QObject::connect(button(QButton::CleaningStation), &QPushButton::clicked,
                     [this] () { label(QButton::CleaningStation,
                                       world->getInfoCleaningStation()); });

#undef button
#undef label
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
    textPanel->addInfo(QInfo::Year, 0, 0, world->getInfoYear());
    textPanel->addInfo(QInfo::Population, 0, 1, world->getInfoPopulation());
    textPanel->addInfo(QInfo::Energy, 1, 0, world->getInfoEnergy());
    textPanel->addInfo(QInfo::Minerals, 1, 1, world->getInfoMinerals());
    textPanel->addInfo(QInfo::Food, 1, 2, world->getInfoFood());
    textPanel->addInfo(QInfo::Pollution, 2, 0, world->getInfoPollution());
    textPanel->addInfo(QInfo::Solidarity, 2, 1, world->getInfoSolidarity());
    textPanel->addInfo(QInfo::Science, 2, 2, world->getInfoScience());

    textPanel->setMinimumSize(600, 400);

    generalLayout->addWidget(textPanel);

    QObject::connect(world, &QWorld::yearUpdate, textPanel->getLabel(QInfo::Year),
                     &QLabel::setText);
    QObject::connect(world, &QWorld::populationUpdate, textPanel->getLabel(QInfo::Population),
                     &QLabel::setText);
    QObject::connect(world, &QWorld::energyUpdate, textPanel->getLabel(QInfo::Energy),
                     &QLabel::setText);
    QObject::connect(world, &QWorld::mineralsUpdate, textPanel->getLabel(QInfo::Minerals),
                     &QLabel::setText);
    QObject::connect(world, &QWorld::foodUpdate, textPanel->getLabel(QInfo::Food),
                     &QLabel::setText);
    QObject::connect(world, &QWorld::pullutionUpdate, textPanel->getLabel(QInfo::Pollution),
                     &QLabel::setText);
    QObject::connect(world, &QWorld::solidarityUpdate, textPanel->getLabel(QInfo::Solidarity),
                     &QLabel::setText);
    QObject::connect(world, &QWorld::scienceUpdate, textPanel->getLabel(QInfo::Science),
                     &QLabel::setText);
}
