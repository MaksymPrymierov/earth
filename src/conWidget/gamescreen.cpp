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

void GameScreen::addMenuPanel() {
  ButtonsPanel *p = new ButtonsPanel(QBoxLayout::Direction::LeftToRight);
  p->addButton(Button::Save, "Save");
  p->addButton(Button::Load, "Load");
  p->addButton(Button::ExitToMenu, "Exit to Menu");
  p->addButton(Button::Exit, "Exit");

  buttonsPanels[ButtonPanel::Menu] = p;
  header->addWidget(p);
  header->setCurrentWidget(p);

  QObject::connect(buttonsPanels[ButtonPanel::Menu]->getButton(Button::ExitToMenu), &QPushButton::clicked, [this] () { emit clickedMenu(); });
  QObject::connect(buttonsPanels[ButtonPanel::Menu]->getButton(Button::Exit), &QPushButton::clicked, [] () { QCoreApplication::quit(); });
}

void GameScreen::addActionPanel() {
  ButtonsPanel *p = new ButtonsPanel(QBoxLayout::Direction::LeftToRight);\
  p->setTitle("Select an action");
  p->addButton(Button::Building, "Building");
  p->addButton(Button::Destroy, "Destroy");
  p->addButton(Button::Science, "Science");
  p->addButton(Button::Events, "Events");

  buttonsPanels[ButtonPanel::Action] = p;
  footer->addWidget(p);
  footer->setCurrentWidget(p);

  QObject::connect(buttonsPanels[ButtonPanel::Action]->getButton(Button::Building), &QPushButton::clicked, this, &GameScreen::showBuildPanel);
}

void GameScreen::addBuildPanel() {
  ButtonsPanel *p = new ButtonsPanel(QBoxLayout::Direction::LeftToRight);
  p->setTitle("Building");
  p->addButton(Button::PowerStation, "Power station");
  p->addButton(Button::Mine, "Mine");
  p->addButton(Button::Farm, "Farm");
  p->addButton(Button::Laboratory, "Laboratory");
  p->addButton(Button::Cancel, "Cancel");

  buttonsPanels[ButtonPanel::Building] = p;
  footer->addWidget(p);

  QObject::connect(buttonsPanels[ButtonPanel::Building]->getButton(Button::Cancel), &QPushButton::clicked, this, &GameScreen::showActionPanel);
}

void GameScreen::installHeader() {
  generalLayout->addWidget(header);
}

void GameScreen::installFooter() {
  generalLayout->addWidget(footer);
}

void GameScreen::installInfoPanel() {
  infoPanel->setMinimumSize(600, 400);
  generalLayout->addWidget(infoPanel);
}

void GameScreen::showMenuPanel() {
  header->setCurrentWidget(buttonsPanels[ButtonPanel::Menu]);
}

void GameScreen::showActionPanel() {
  footer->setCurrentWidget(buttonsPanels[ButtonPanel::Action]);
}

void GameScreen::showBuildPanel() {
  footer->setCurrentWidget(buttonsPanels[ButtonPanel::Building]);
}
