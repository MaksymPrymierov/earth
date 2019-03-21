#include "headers/QConWidgets/QMainMenu.h"

QMainMenu::QMainMenu(QWidget *parent) :
    QWidget(parent)
{
    generalLayout->setContentsMargins(5, 5, 5, 5);
    generalLayout->setSpacing(10);
    generalLayout->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    setLayout(generalLayout);

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
    menu->addButton(QButton::Continue, 1, 0, "Continue");
    menu->addButton(QButton::Load, 2, 0, "Load");
    menu->addButton(QButton::Settings, 3, 0, "Settings");
    menu->addButton(QButton::Exit, 4, 0, "Exit");

    menu->getButton(QButton::NewGame)->setMinimumWidth(150);

    menu->setAlignmentContent(Qt::AlignCenter);
    menu->setFixedSize(375, 500);

    generalLayout->addWidget(menu);
}
