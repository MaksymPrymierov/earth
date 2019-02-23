#include "headers/conWidget/buttonspanel.h"

ButtonsPanel::ButtonsPanel(QGroupBox *parent) :
  QGroupBox(parent) {
  layout->setAlignment(Qt::AlignCenter);
  setLayout(layout);
  setMinimumHeight(50);
}

ButtonsPanel::~ButtonsPanel() {
  delete layout;
}

void ButtonsPanel::addButton(Button button, int row, int column, QString text) {
  QPushButton *b = new QPushButton(text);
  layout->addWidget(b, row, column);
  buttons[button] = b;
}

void ButtonsPanel::addInfo(Button button, int row, int column, QString info) {
  QLabel *l = new QLabel(info);
  l->setMargin(2);
  l->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
  layout->addWidget(l, row, column);
  labels[button] = l;
}

void ButtonsPanel::setAlignmentContent(QFlags<Qt::AlignmentFlag> aling) {
  setAlignment(int(aling));
  layout->setAlignment(aling);
}
