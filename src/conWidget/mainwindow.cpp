#include "headers/conWidget/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QWidget(parent),
  x(600),
  y(200) {
  pall->setColor(backgroundRole(), Qt::cyan);
  setPalette(*pall);
  setWindowTitle("Con Civilization");
  setMinimumSize(x, y);
  setAutoFillBackground(true);
  addLayaout();
  addTextInformation();
  addTextCommand();
  addBuildButton("Электростанция");
  addBuildButton("Шахта");
  addBuildButton("Ферма");
  connectObjects();
  vBoxLayout->addLayout(hBoxLayout);
  setLayout(vBoxLayout);
}

void MainWindow::addTextInformation(){
  info->setFrameStyle(QFrame::Box | QFrame::Plain);
  info->setText(world->get());
  vBoxLayout->addWidget(info);
}

void MainWindow::addTextCommand(){
  command->setText("Построить ->");
  command->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
  hBoxLayout->addWidget(command);
}

void MainWindow::addBuildButton(QString text){
  QPushButton *b = new QPushButton(text, this);

  pall->setColor(b->backgroundRole(), Qt::lightGray);
  b->setPalette(*pall);
  b->setAutoFillBackground(true);
  b->setCursor(Qt::PointingHandCursor);
  hBoxLayout->addWidget(b);

  buildButtons->append(b);
}

void MainWindow::addLayaout(){
  vBoxLayout->setContentsMargins(5, 5, 5, 5);
  vBoxLayout->setSpacing(15);
  hBoxLayout->setContentsMargins(5, 5, 5, 5);
  hBoxLayout->setSpacing(15);
}

void MainWindow::connectObjects(){
  QObject::connect(buildButtons->at(0), SIGNAL(clicked()), world, SLOT(buildEnergyStation()));
  QObject::connect(buildButtons->at(1), SIGNAL(clicked()), world, SLOT(buildMine()));
  QObject::connect(buildButtons->at(2), SIGNAL(clicked()), world, SLOT(buildFarm()));
  QObject::connect(world, SIGNAL(print(QString)), info, SLOT(setText(QString)));
}
