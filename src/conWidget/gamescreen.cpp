#include "headers/conWidget/gamescreen.h"
#include <QtCore/QCoreApplication>

GameScreen::GameScreen(QWidget *parent) :
  QWidget(parent) {
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

GameScreen::~GameScreen() {
  delete world;
  delete pall;
  delete header;
  delete footer;
  delete generalLayout;
  delete textPanel;
}

void GameScreen::addMenuPanel() {
  ButtonsPanel *p = new ButtonsPanel();

  p->addButton(Button::Save, 0, 0, "Save");
  p->addButton(Button::Load, 0, 1, "Load");
  p->addButton(Button::ExitToMenu, 0, 2, "Exit to Menu");
  p->addButton(Button::Exit, 0, 3, "Exit");

  p->setAlignmentContent(Qt::AlignCenter);

  buttonsPanels[ButtonPanel::Menu] = p;
  header->addWidget(p);
  header->setCurrentWidget(p);

  QObject::connect(buttonsPanels[ButtonPanel::Menu]->getButton(Button::ExitToMenu), &QPushButton::clicked, [this] () { emit clickedMenu(); });
  QObject::connect(buttonsPanels[ButtonPanel::Menu]->getButton(Button::Exit), &QPushButton::clicked, [] () { QCoreApplication::quit(); });
}

void GameScreen::addActionPanel() {
  ButtonsPanel *p = new ButtonsPanel();

  p->setTitle("Select an action");

  p->addButton(Button::Building, 0, 0, "Building");
  p->addButton(Button::Destroy, 0, 1, "Destroy");
  p->addButton(Button::Science, 0, 2, "Science");
  p->addButton(Button::Events, 0, 3, "Events");

  p->setAlignmentContent(Qt::AlignCenter);

  buttonsPanels[ButtonPanel::Action] = p;
  footer->addWidget(p);
  footer->setCurrentWidget(p);

  QObject::connect(buttonsPanels[ButtonPanel::Action]->getButton(Button::Building), &QPushButton::clicked, this, &GameScreen::showBuildPanel);
}

void GameScreen::addBuildPanel() {
  ButtonsPanel *p = new ButtonsPanel();

  p->setTitle("Building");

  p->addButton(Button::PowerStation, 0, 0, "Power station");
  p->addButton(Button::Mine, 0, 1, "Mine");
  p->addButton(Button::Farm, 0, 2, "Farm");
  p->addButton(Button::Laboratory, 0, 3, "Laboratory");
  p->addButton(Button::CleaningStation, 0, 4, "Cleaning Station");
  p->addButton(Button::Cancel, 0, 5, "Cancel");

  p->addInfo(Button::PowerStation, 1, 0, world->getInfoEnergyStation());
  p->addInfo(Button::Mine, 1, 1, world->getInfoMine());
  p->addInfo(Button::Farm, 1, 2, world->getInfoFarm());
  p->addInfo(Button::Laboratory, 1, 3, world->getInfoLab());
  p->addInfo(Button::CleaningStation, 1, 4, world->getInfoCleaningStation());

  p->setAlignmentContent(Qt::AlignCenter);

  buttonsPanels[ButtonPanel::Building] = p;
  footer->addWidget(p);

#define button(x) buttonsPanels[ButtonPanel::Building]->getButton(x)
#define label(x)  buttonsPanels[ButtonPanel::Building]->getLabel(x)

  QObject::connect(button(Button::PowerStation), &QPushButton::clicked, world, &World::buildEnergyStation);
  QObject::connect(button(Button::Mine), &QPushButton::clicked, world, &World::buildMine);
  QObject::connect(button(Button::Farm), &QPushButton::clicked, world, &World::buildFarm);
  QObject::connect(button(Button::Laboratory), &QPushButton::clicked, world, &World::buildLab);
  QObject::connect(button(Button::CleaningStation), &QPushButton::clicked, world, &World::buildCleaningStation);
  QObject::connect(button(Button::Cancel), &QPushButton::clicked, this, &GameScreen::showActionPanel);

  QObject::connect(button(Button::PowerStation), &QPushButton::clicked, [this] () { label(Button::PowerStation)->setText(world->getInfoEnergyStation()); });
  QObject::connect(button(Button::Mine), &QPushButton::clicked, [this] () { label(Button::Mine)->setText(world->getInfoMine()); });
  QObject::connect(button(Button::Farm), &QPushButton::clicked, [this] () { label(Button::Farm)->setText(world->getInfoFarm()); });
  QObject::connect(button(Button::Laboratory), &QPushButton::clicked, [this] () { label(Button::Laboratory)->setText(world->getInfoLab()); });
  QObject::connect(button(Button::CleaningStation), &QPushButton::clicked, [this] () { label(Button::CleaningStation)->setText(world->getInfoCleaningStation()); });

#undef button
#undef label
}

void GameScreen::installHeader() {
  generalLayout->addWidget(header);
}

void GameScreen::installFooter() {
  generalLayout->addWidget(footer);
}

void GameScreen::installInfoPanel() {
  textPanel->addInfo(Info::Year, 0, 0, world->getInfoYear());
  textPanel->addInfo(Info::Population, 0, 1, world->getInfoPopulation());
  textPanel->addInfo(Info::Energy, 1, 0, world->getInfoEnergy());
  textPanel->addInfo(Info::Minerals, 1, 1, world->getInfoMinerals());
  textPanel->addInfo(Info::Food, 1, 2, world->getInfoFood());
  textPanel->addInfo(Info::Pollution, 2, 0, world->getInfoPollution());
  textPanel->addInfo(Info::Solidarity, 2, 1, world->getInfoSolidarity());
  textPanel->addInfo(Info::Science, 2, 2, world->getInfoScience());

  textPanel->setMinimumSize(600, 400);

  generalLayout->addWidget(textPanel);

  QObject::connect(world, &World::yearUpdate, textPanel->getLabel(Info::Year), &QLabel::setText);
  QObject::connect(world, &World::populationUpdate, textPanel->getLabel(Info::Population), &QLabel::setText);
  QObject::connect(world, &World::energyUpdate, textPanel->getLabel(Info::Energy), &QLabel::setText);
  QObject::connect(world, &World::mineralsUpdate, textPanel->getLabel(Info::Minerals), &QLabel::setText);
  QObject::connect(world, &World::foodUpdate, textPanel->getLabel(Info::Food), &QLabel::setText);
  QObject::connect(world, &World::pullutionUpdate, textPanel->getLabel(Info::Pollution), &QLabel::setText);
  QObject::connect(world, &World::solidarityUpdate, textPanel->getLabel(Info::Solidarity), &QLabel::setText);
  QObject::connect(world, &World::scienceUpdate, textPanel->getLabel(Info::Science), &QLabel::setText);
}
