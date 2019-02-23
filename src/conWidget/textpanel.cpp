#include "headers/conWidget/textpanel.h"

TextPanel::TextPanel(QWidget *parent) :
  QWidget(parent) {
  layout->setAlignment(Qt::AlignCenter);
  setLayout(layout);
}

TextPanel::~TextPanel() {
  delete layout;
}

void TextPanel::addInfo(Info type, int row, int column, QString info) {
  QLabel *l = new QLabel(info);
  l->setMargin(2);
  l->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
  layout->addWidget(l, row, column);
  labels[type] = l;
}
