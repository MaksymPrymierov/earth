#include "headers/conWidget/mainwindow.h"
#include <QtCore/QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
  QWidget(parent),
  x(600),
  y(200) {
  pall->setColor(backgroundRole(), Qt::cyan);
  setPalette(*pall);
  setWindowTitle("Con Civilization");
  setMinimumSize(x, y);
  setAutoFillBackground(true);
  layouts.append(new QVBoxLayout());
  layouts.last()->setContentsMargins(5, 5, 5, 5);
  layouts.last()->setSpacing(10);

  setLayout(layouts[0]);
}

void MainWindow::addTextInformation(QString text) {
  info->setFrameStyle(QFrame::Box | QFrame::Plain);
  info->setText(text);
  layouts.last()->addWidget(info);
}

void MainWindow::addTextLine(QString text) {
  QLabel *l = new QLabel(text);

  l->setText(text);
  l->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
  layouts.last()->addWidget(l);

  textLines.append(l);
}

void MainWindow::addButton(QString text) {
  QPushButton *b = new QPushButton(text);

  pall->setColor(b->backgroundRole(), Qt::lightGray);
  b->setPalette(*pall);
  b->setAutoFillBackground(true);
  b->setCursor(Qt::PointingHandCursor);
  layouts.last()->addWidget(b);

  buttons.append(b);
}

void MainWindow::addLayout(int parentId, QBoxLayout::Direction direction) {
  QBoxLayout *l = new QBoxLayout(direction);

  l->setContentsMargins(5, 5, 5, 5);
  l->setSpacing(10);

  layouts[parentId]->addLayout(l);
  layouts.append(l);
}

void MainWindow::addStackWidgets(){
  layouts.last()->addWidget(stackWidgets);
}

void MainWindow::addWidget(QWidget *w){
  stackWidgets->addWidget(w);
}

void MainWindow::removeWidget(QWidget *w){
  stackWidgets->removeWidget(w);
}

void MainWindow::setCurrentWidget(QWidget *w){
  stackWidgets->setCurrentWidget(w);
}

QPushButton* MainWindow::getButton(int id) {
  return buttons[id];
}

void MainWindow::setInformation(QString s) {
  info->setText(s);
}
