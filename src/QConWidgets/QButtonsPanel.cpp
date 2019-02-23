#include "headers/QConWidgets/QButtonsPanel.h"

QButtonsPanel::QButtonsPanel(QGroupBox *parent) :
    QGroupBox(parent)
{
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);

    setMinimumHeight(50);
}

QButtonsPanel::~QButtonsPanel()
{
    delete layout;
}

void QButtonsPanel::addButton(QButton button, int row, int column, QString text)
{
    QPushButton *b = new QPushButton(text);
    layout->addWidget(b, row, column);
    buttons[button] = b;
}

void QButtonsPanel::addInfo(QButton button, int row, int column, QString info)
{
    QLabel *l = new QLabel(info);
    l->setMargin(2);
    l->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);

    layout->addWidget(l, row, column);
    labels[button] = l;
}

void QButtonsPanel::setAlignmentContent(QFlags<Qt::AlignmentFlag> aling)
{
    setAlignment(int(aling));

    layout->setAlignment(aling);
}
