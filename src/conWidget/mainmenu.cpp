#include "headers/conWidget/mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
  QWidget(parent) {
  generalLayout->setContentsMargins(5, 5, 5, 5);
  generalLayout->setSpacing(5);
  generalLayout->setAlignment(Qt::AlignHCenter);
  pall->setColor(backgroundRole(), *background);
  setPalette(*pall);
  setTitle("Con Civilization");
  installMenu();
  setLayout(generalLayout);

  QObject::connect(menu->getButton(Button::NewGame), &QPushButton::clicked, [this] () { emit clickedNewGame(); });
  QObject::connect(menu->getButton(Button::Exit), &QPushButton::clicked, [this] () { emit clickedExit(); });
}

void MainMenu::setTitle(QString text) {
  title->setText(text);
  title->setAlignment(Qt::AlignCenter);

  generalLayout->addWidget(title);
}

void MainMenu::installMenu() {
  menu->setTitle("Main Menu");
  menu->addButton(Button::NewGame, "New Game");
  menu->addButton(Button::Exit, "Exit");
  menu->getButton(Button::NewGame)->setMinimumWidth(150);
  menu->getButton(Button::Exit)->setMinimumWidth(150);
  menu->setAlignmentContent(Qt::AlignCenter);
  menu->setMinimumWidth(350);
  generalLayout->addWidget(menu);
}
