#include "headers/QConWidgets/QGameScreen.h"
#include <QtCore/QCoreApplication>

QGameScreen::QGameScreen(QWidget *parent) :
    QWidget(parent)
{
    pall->setColor(backgroundRole(), Qt::gray);
    setPalette(*pall);

    installHeader();
    installInfoPanel();
    installFooter();

    addMenuPanel();
    addActionPanel();
    addSciencePanel();

    setLayout(generalLayout);
}

QGameScreen::~QGameScreen()
{
    delete world;
    delete pall;
    delete header;
    delete footer;
    delete generalLayout;
    delete textPanel;
}

void QGameScreen::addMenuPanel()
{
    QButtonsPanel *p = new QButtonsPanel();
    QButtonPanel panel = QButtonPanel::Menu;

    p->addButton(QButton::Save, 0, 0, "Save");
    p->addButton(QButton::Load, 0, 1, "Load");
    p->addButton(QButton::ExitToMenu, 0, 2, "Exit to Menu");
    p->addButton(QButton::Exit, 0, 3, "Exit");

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[panel] = p;
    header->addWidget(p);
    header->setCurrentWidget(p);

    QObject::connect(button(panel, QButton::ExitToMenu), &QPushButton::clicked,
                     [this] () { emit clickedMenu(); });
    QObject::connect(button(panel, QButton::Exit), &QPushButton::clicked,
                     [] () { QCoreApplication::quit(); });

}

void QGameScreen::addActionPanel()
{
    QButtonsPanel *p = new QButtonsPanel();
    QButtonPanel panel = QButtonPanel::Action;

    p->setTitle("Select an action");

    p->addButton(QButton::Building, 0, 0, "Building");
    p->addButton(QButton::Destroy, 0, 1, "Destroy");
    p->addButton(QButton::Science, 0, 2, "Science");
    p->addButton(QButton::Events, 0, 3, "Events");

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[panel] = p;
    footer->addWidget(p);
    footer->setCurrentWidget(p);

    QObject::connect(button(panel, QButton::Building), &QPushButton::clicked, this,
                     &QGameScreen::showBuildPanel);
    QObject::connect(button(panel, QButton::Destroy), &QPushButton::clicked, this,
                     &QGameScreen::showDestroyPanel);
    QObject::connect(button(panel, QButton::Science), &QPushButton::clicked, this,
                     &QGameScreen::showSciencePanel);
}

void QGameScreen::addBuildPanel()
{
    QButtonsPanel *p = new QButtonsPanel();
    QButtonPanel panel = QButtonPanel::Building;

    p->setTitle("Building");

    p->addButton(QButton::PowerStation, 0, 0, "Power station");
    p->addButton(QButton::Mine, 0, 1, "Mine");
    p->addButton(QButton::Farm, 0, 2, "Farm");
    p->addButton(QButton::Laboratory, 0, 3, "Laboratory");
    p->addButton(QButton::CleaningStation, 0, 4, "Cleaning Station");
    p->addButton(QButton::Stock, 0, 5, "Stock");
    p->addButton(QButton::Cancel, 0, 6, "Cancel");

    p->addInfo(QButton::PowerStation, 1, 0, world->getInfoEnergyStation().data());
    p->addInfo(QButton::Mine, 1, 1, world->getInfoMine().data());
    p->addInfo(QButton::Farm, 1, 2, world->getInfoFarm().data());
    p->addInfo(QButton::Laboratory, 1, 3, world->getInfoLab().data());
    p->addInfo(QButton::CleaningStation, 1, 4, world->getInfoCleaningStation().data());
    p->addInfo(QButton::Stock, 1, 5, world->getInfoStock().data());

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[panel] = p;
    footer->addWidget(p);

    QObject::connect(button(panel, QButton::PowerStation), &QPushButton::clicked,
                     [this] () { world->buildEnergyStation(); });
    QObject::connect(button(panel, QButton::Mine), &QPushButton::clicked,
                     [this] () { world->buildMine(); });
    QObject::connect(button(panel, QButton::Farm), &QPushButton::clicked,
                     [this] () { world->buildFarm(); });
    QObject::connect(button(panel, QButton::Laboratory), &QPushButton::clicked,
                     [this] () { world->buildLab(); });
    QObject::connect(button(panel, QButton::CleaningStation), &QPushButton::clicked,
                     [this] () { world->buildCleaningStation(); });
    QObject::connect(button(panel, QButton::Stock), &QPushButton::clicked,
                     [this] () { world->buildStock(); });
    QObject::connect(button(panel, QButton::Cancel), &QPushButton::clicked,
                     [this, p] () { this->showActionPanel(p); });

    QObject::connect(button(panel, QButton::PowerStation), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::PowerStation,
                                                     world->getInfoEnergyStation().data()); });
    QObject::connect(button(panel, QButton::Mine), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Mine,
                                                     world->getInfoMine().data()); });
    QObject::connect(button(panel, QButton::Farm), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Farm,
                                                     world->getInfoFarm().data()); });
    QObject::connect(button(panel, QButton::Laboratory), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Laboratory,
                                                     world->getInfoLab().data()); });
    QObject::connect(button(panel, QButton::CleaningStation), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::CleaningStation,
                                                     world->getInfoCleaningStation().data()); });
    QObject::connect(button(panel, QButton::Stock), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Stock,
                                                     world->getInfoStock().data()); });
}

void QGameScreen::addDestroyPanel()
{
    QButtonsPanel *p = new QButtonsPanel();
    QButtonPanel panel = QButtonPanel::Destroy;

    p->setTitle("Destroy");

    p->addButton(QButton::PowerStation, 0, 0, "Power station");
    p->addButton(QButton::Mine, 0, 1, "Mine");
    p->addButton(QButton::Farm, 0, 2, "Farm");
    p->addButton(QButton::Laboratory, 0, 3, "Laboratory");
    p->addButton(QButton::CleaningStation, 0, 4, "Cleaning Station");
    p->addButton(QButton::Stock, 0, 5, "Stock");
    p->addButton(QButton::Cancel, 0, 6, "Cancel");

    p->addInfo(QButton::PowerStation, 1, 0, world->getInfoEnergyStation().data());
    p->addInfo(QButton::Mine, 1, 1, world->getInfoMine().data());
    p->addInfo(QButton::Farm, 1, 2, world->getInfoFarm().data());
    p->addInfo(QButton::Laboratory, 1, 3, world->getInfoLab().data());
    p->addInfo(QButton::CleaningStation, 1, 4, world->getInfoCleaningStation().data());
    p->addInfo(QButton::Stock, 1, 5, world->getInfoStock().data());

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[panel] = p;
    footer->addWidget(p);

    QObject::connect(button(panel, QButton::PowerStation), &QPushButton::clicked,
                     [this] () { world->destroyEnergyStation(); });
    QObject::connect(button(panel, QButton::Mine), &QPushButton::clicked,
                     [this] () { world->destroyMine(); });
    QObject::connect(button(panel, QButton::Farm), &QPushButton::clicked,
                     [this] () { world->destroyFarm(); });
    QObject::connect(button(panel, QButton::Laboratory), &QPushButton::clicked,
                     [this] () { world->destroyLab(); });
    QObject::connect(button(panel, QButton::CleaningStation), &QPushButton::clicked,
                     [this] () { world->destroyCleaningStation(); });
    QObject::connect(button(panel, QButton::Stock), &QPushButton::clicked,
                     [this] () { world->destroyStock(); });
    QObject::connect(button(panel, QButton::Cancel), &QPushButton::clicked,
                     [this, p] () { this->showActionPanel(p); });

    QObject::connect(button(panel, QButton::PowerStation), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::PowerStation,
                                                     world->getInfoEnergyStation().data()); });
    QObject::connect(button(panel, QButton::Mine), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Mine,
                                                     world->getInfoMine().data()); });
    QObject::connect(button(panel, QButton::Farm), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Farm,
                                                     world->getInfoFarm().data()); });
    QObject::connect(button(panel, QButton::Laboratory), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Laboratory,
                                                     world->getInfoLab().data()); });
    QObject::connect(button(panel, QButton::CleaningStation), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::CleaningStation,
                                                     world->getInfoCleaningStation().data()); });
    QObject::connect(button(panel, QButton::Stock), &QPushButton::clicked,
                     [this, panel] () { setTextLabel(panel, QButton::Stock,
                                                     world->getInfoStock().data()); });

}

void QGameScreen::addSciencePanel()
{
    QButtonsPanel *p = new QButtonsPanel();

    QButtonPanel panel = QButtonPanel::Science;

    p->setTitle("Research");

    p->addButton(QButton::PowerStation, 0, 0, "Power station");
    p->addButton(QButton::Mine, 0, 1, "Mine");
    p->addButton(QButton::Farm, 0, 2, "Farm");
    p->addButton(QButton::Laboratory, 0, 3, "Laboratory");
    p->addButton(QButton::CleaningStation, 0, 4, "Cleaning Station");
    p->addButton(QButton::Stock, 0, 5, "Stock");
    p->addButton(QButton::Cancel, 0, 6, "Cancel");

    p->setAlignmentContent(Qt::AlignCenter);

    buttonsPanels[panel] = p;
    footer->addWidget(p);

    QObject::connect(button(panel, QButton::Cancel), &QPushButton::clicked,
                     [this, p] () { this->showActionPanel(p); });
}

void QGameScreen::installHeader()
{
    generalLayout->addWidget(header);
}

void QGameScreen::installFooter()
{
    generalLayout->addWidget(footer);
}

void QGameScreen::installInfoPanel()
{
    textPanel->addInfo(QInfo::Year, 0, 0, world->getInfoYear().data());
    textPanel->addInfo(QInfo::Population, 0, 1, world->getInfoPopulation().data());
    textPanel->addInfo(QInfo::Capacity, 0, 2, world->getInfoCapacity().data());
    textPanel->addInfo(QInfo::Energy, 1, 0, world->getInfoEnergy().data());
    textPanel->addInfo(QInfo::Minerals, 1, 1, world->getInfoMinerals().data());
    textPanel->addInfo(QInfo::Food, 1, 2, world->getInfoFood().data());
    textPanel->addInfo(QInfo::Pollution, 2, 0, world->getInfoPollution().data());
    textPanel->addInfo(QInfo::Solidarity, 2, 1, world->getInfoSolidarity().data());
    textPanel->addInfo(QInfo::Science, 2, 2, world->getInfoScience().data());
    textPanel->addInfo(QInfo::Risks, 3, 0, "Risks: ");
    textPanel->addInfo(QInfo::War, 3, 1, world->getInfoActionEvent(QWorldActionEvents::War).data());
    textPanel->addInfo(QInfo::Epidemic, 3, 2,
                       world->getInfoActionEvent(QWorldActionEvents::Epidemic).data());
    textPanel->addInfo(QInfo::Revolution, 3, 3,
                       world->getInfoActionEvent(QWorldActionEvents::Revolution).data());
    textPanel->addInfo(QInfo::ActOfTerrorism, 4, 0,
                       world->getInfoActionEvent(QWorldActionEvents::ActOfTerrorism).data());
    textPanel->addInfo(QInfo::AlienAttack, 4, 1,
                       world->getInfoActionEvent(QWorldActionEvents::AlienAttack).data());
    textPanel->addInfo(QInfo::GlobalCataclysm, 4, 2,
                       world->getInfoActionEvent(QWorldActionEvents::GlobalCataclysm).data());
    textPanel->addInfo(QInfo::GlobalAccident, 4, 3,
                       world->getInfoActionEvent(QWorldActionEvents::GlobalAccident).data());
    textPanel->addInfo(QInfo::PastEvent, 5, 0,
                       ("Past event " + world->getCurrentEvent()).data());


    textPanel->setMinimumSize(600, 400);

    generalLayout->addWidget(textPanel);
}

void QGameScreen::updateInfoPanel()
{
    textPanel->getLabel(QInfo::Year)->setText(world->getInfoYear().data());
    textPanel->getLabel(QInfo::Population)->setText(world->getInfoPopulation().data());
    textPanel->getLabel(QInfo::Capacity)->setText(world->getInfoCapacity().data());
    textPanel->getLabel(QInfo::Energy)->setText(world->getInfoEnergy().data());
    textPanel->getLabel(QInfo::Minerals)->setText(world->getInfoMinerals().data());
    textPanel->getLabel(QInfo::Food)->setText(world->getInfoFood().data());
    textPanel->getLabel(QInfo::Pollution)->setText(world->getInfoPollution().data());
    textPanel->getLabel(QInfo::Solidarity)->setText(world->getInfoSolidarity().data());
    textPanel->getLabel(QInfo::Science)->setText(world->getInfoScience().data());
    textPanel->getLabel(QInfo::War)->
            setText(world->getInfoActionEvent(QWorldActionEvents::War).data());
    textPanel->getLabel(QInfo::Epidemic)->
            setText(world->getInfoActionEvent(QWorldActionEvents::Epidemic).data());
    textPanel->getLabel(QInfo::Revolution)->
            setText(world->getInfoActionEvent(QWorldActionEvents::Revolution).data());
    textPanel->getLabel(QInfo::ActOfTerrorism)->
            setText(world->getInfoActionEvent(QWorldActionEvents::ActOfTerrorism).data());
    textPanel->getLabel(QInfo::AlienAttack)->
            setText(world->getInfoActionEvent(QWorldActionEvents::AlienAttack).data());
    textPanel->getLabel(QInfo::GlobalCataclysm)->
            setText(world->getInfoActionEvent(QWorldActionEvents::GlobalCataclysm).data());
    textPanel->getLabel(QInfo::GlobalAccident)->
            setText(world->getInfoActionEvent(QWorldActionEvents::GlobalAccident).data());
    textPanel->getLabel(QInfo::PastEvent)->
            setText(("Past event: " + world->getCurrentEvent()).data());
}

void QGameScreen::showBuildPanel()
{
    addBuildPanel();
    footer->setCurrentWidget(buttonsPanels[QButtonPanel::Building]);
}

void QGameScreen::showActionPanel(QButtonsPanel *panel)
{
    addActionPanel();
    if (panel != nullptr) {
        footer->removeWidget(panel);
        delete panel;
    }
    footer->setCurrentWidget(buttonsPanels[QButtonPanel::Action]);
}

void QGameScreen::showMenuPanel()
{
    header->setCurrentWidget(buttonsPanels[QButtonPanel::Menu]);
}

void QGameScreen::showDestroyPanel()
{
    addDestroyPanel();
    footer->setCurrentWidget(buttonsPanels[QButtonPanel::Destroy]);
}

void QGameScreen::showSciencePanel()
{
    addSciencePanel();
    footer->setCurrentWidget(buttonsPanels[QButtonPanel::Science]);
}

QPushButton* QGameScreen::button(QButtonPanel panel, QButton button)
{
    return buttonsPanels[panel]->getButton(button);
}

void QGameScreen::setTextLabel(QButtonPanel panel, QButton button, QString text)
{
    buttonsPanels[panel]->getLabel(button)->setText(text);
}

bool QGameScreen::event(QEvent *event)
{
    if (event->type() == world->WorldEvent) {
        updateInfoPanel();
        return true;
    }

    return QWidget::event(event);
}
