#include "headers/conWidget/mainmenu.h"

QMainMenu::QMainMenu(QWidget *parent) :
    QWidget(parent)
{
    generalLayout->setContentsMargins(5, 5, 5, 5);
    generalLayout->setSpacing(5);
    generalLayout->setAlignment(Qt::AlignHCenter);
    setLayout(generalLayout);

    setTitle("Con Civilization");

    installMenu();

    QObject::connect(menu->getButton(QButton::NewGame), &QPushButton::clicked,
                     [this] () { emit clickedNewGame(); });
    QObject::connect(menu->getButton(QButton::Exit), &QPushButton::clicked,
                     [this] () { emit clickedExit(); });
}

QMainMenu::~QMainMenu()
{
    delete pall;
    delete title;
    delete generalLayout;
    delete menu;
}

void QMainMenu::setTitle(QString text)
{
    title->setText(text);
    title->setAlignment(Qt::AlignCenter);

    generalLayout->addWidget(title);
}

void QMainMenu::installMenu()
{
    menu->addButton(QButton::NewGame, 0, 0, "New Game");
    menu->addButton(QButton::Exit, 1, 0, "Exit");

    menu->getButton(QButton::NewGame)->setMinimumWidth(150);
    menu->getButton(QButton::Exit)->setMinimumWidth(150);

    menu->setAlignmentContent(Qt::AlignCenter);
    menu->setFixedSize(375, 500);

    pall->setBrush(menu->backgroundRole(), QBrush(QPixmap(":/images/mainmenu.png")));
    menu->setPalette(*pall);
    menu->setAutoFillBackground(true);

    generalLayout->addWidget(menu);
}
