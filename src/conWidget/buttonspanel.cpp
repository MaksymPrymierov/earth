#include "headers/conWidget/buttonspanel.h"

ButtonsPanel::ButtonsPanel(QBoxLayout::Direction direction, QGroupBox *parent) :
  QGroupBox(parent) {
  layout = new QBoxLayout(direction);
  layout->setAlignment(Qt::AlignLeft | Qt::AlignHCenter);
  setLayout(layout);
  setMinimumHeight(50);
}

void ButtonsPanel::addButton(Button button, QString text) {
  QPushButton *b = new QPushButton(text);
  layout->addWidget(b);
  buttons[button] = b;
}

QPushButton* ButtonsPanel::getButton(Button button) {
  return buttons[button];
}

void ButtonsPanel::setAlignmentContent(Qt::AlignmentFlag aling) {
  setAlignment(aling);
  layout->setAlignment(aling);
}
