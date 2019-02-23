#include "headers/conWidget/textpanel.h"

QTextPanel::QTextPanel(QWidget *parent) :
    QWidget(parent)
{
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);
}

QTextPanel::~QTextPanel()
{
    delete layout;
}

void QTextPanel::addInfo(QInfo type, int row, int column, QString info)
{
    QLabel *l = new QLabel(info);

    l->setMargin(2);
    l->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);

    layout->addWidget(l, row, column);
    labels[type] = l;
}
