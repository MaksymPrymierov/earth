#include "headers/conWidget/buttonspanel.h"

ButtonsPanel::ButtonsPanel(QGroupBox *parent) :
  QGroupBox(parent) {
  layout = new QGridLayout();
  layout->setAlignment(Qt::AlignCenter);
  setLayout(layout);
  setMinimumHeight(50);
}

void ButtonsPanel::addButton(Button button, int row, int column, QString text) {
  QPushButton *b = new QPushButton(text);
  layout->addWidget(b, row, column);
  buttons[button] = b;
}

void ButtonsPanel::addInfo(Button button, int row, int column, QString info) {
  QLabel *l = new QLabel(info);
  layout->addWidget(l, row, column);
  labels[button] = l;
}

QPushButton* ButtonsPanel::getButton(Button button) {
  return buttons[button];
}

void ButtonsPanel::setAlignmentContent(QFlags<Qt::AlignmentFlag> aling) {
  setAlignment(int(aling));
  layout->setAlignment(aling);
}