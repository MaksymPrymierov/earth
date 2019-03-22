#include "headers/QConWidgets/QButtonsPanel/QButtonsPanel.h"

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
    for (QMap<QButton, QPushButton*>::iterator i = buttons.begin(); i != buttons.end(); ++i) {
        delete *i;
    }
}

void QButtonsPanel::addButton(QButton button, int row, int column, QString text)
{
    QPushButton *b = new QPushButton(text);
    layout->addWidget(b, row, column);
    buttons[button] = b;
}

void QButtonsPanel::setAlignmentContent(QFlags<Qt::AlignmentFlag> aling)
{
    setAlignment(int(aling));

    layout->setAlignment(aling);
}
