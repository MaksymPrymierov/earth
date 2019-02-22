#include "headers/conWidget/mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
  QWidget(parent) {
  generalLayout->setContentsMargins(5, 5, 5, 5);
  generalLayout->setSpacing(5);
  generalLayout->setAlignment(Qt::AlignHCenter);
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
  menu->addButton(Button::NewGame, 0, 0, "New Game");
  menu->addButton(Button::Exit, 1, 0, "Exit");
  menu->getButton(Button::NewGame)->setMinimumWidth(150);
  menu->getButton(Button::Exit)->setMinimumWidth(150);
  menu->setAlignmentContent(Qt::AlignCenter);
  menu->setFixedSize(375, 500);
  brush->setTextureImage(QImage("resources/images/mainmenu.png"));
  pall->setBrush(menu->backgroundRole(), *brush);
  menu->setPalette(*pall);
  menu->setAutoFillBackground(true);
  generalLayout->addWidget(menu);
}
