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

  QObject::connect(buttonsPanels[ButtonPanel::Building]->getButton(Button::PowerStation), &QPushButton::clicked, world, &World::buildEnergyStation);
  QObject::connect(buttonsPanels[ButtonPanel::Building]->getButton(Button::Mine), &QPushButton::clicked, world, &World::buildMine);
  QObject::connect(buttonsPanels[ButtonPanel::Building]->getButton(Button::Farm), &QPushButton::clicked, world, &World::buildFarm);
  QObject::connect(buttonsPanels[ButtonPanel::Building]->getButton(Button::Laboratory), &QPushButton::clicked, world, &World::buildLab);
  QObject::connect(buttonsPanels[ButtonPanel::Building]->getButton(Button::CleaningStation), &QPushButton::clicked, world, &World::buildCleaningStation);
  QObject::connect(buttonsPanels[ButtonPanel::Building]->getButton(Button::Cancel), &QPushButton::clicked, this, &GameScreen::showActionPanel);
}

void GameScreen::installHeader() {
  generalLayout->addWidget(header);
}

void GameScreen::installFooter() {
  generalLayout->addWidget(footer);
}

void GameScreen::installInfoPanel() {
  textPanel->setText(world->get());
  textPanel->setAlignment(Qt::AlignCenter);
  textPanel->setMinimumSize(600, 400);

  generalLayout->addWidget(textPanel);

  QObject::connect(world, &World::print, textPanel, &QLabel::setText);
}
