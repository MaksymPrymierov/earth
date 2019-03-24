#include "headers/QConWidgets/QTextPanel/QGameInfoPanel.h"

QGameInfoPanel::QGameInfoPanel(World *source, QTextPanel *parent) :
    QTextPanel(parent), world(source)
{
    setMinimumSize(600, 400);

    installWorldStatsInfo();
    installActionEventInfo();
}

void QGameInfoPanel::installWorldStatsInfo()
{
    addInfo(QInfo::InfoYear, 0, 0, "Year");
    addInfo(QInfo::InfoPopulation, 0, 1, "Population");
    addInfo(QInfo::InfoEnergy, 0, 2, "Energy");
    addInfo(QInfo::InfoMinerals, 0, 3, "Minerals");
    addInfo(QInfo::InfoFood, 0, 4, "Food");
    addInfo(QInfo::InfoCapacity, 0, 5, "Capacity");
    addInfo(QInfo::InfoSolidarity, 0, 6, "Solidarity");
    addInfo(QInfo::InfoPollution, 0, 7, "Pollution");
    addInfo(QInfo::InfoScience, 0, 8, "Science");

    addInfo(QInfo::Year, 1, 0, QString::asprintf("%ld", world->getYear()));
    addInfo(QInfo::Population, 1, 1, QString::asprintf("%ld", world->getPopulation()));
    addInfo(QInfo::Energy, 1, 2, QString::asprintf("%ld [%ld]", world->getEnergy(),
                                                              world->getModEnergy()));
    addInfo(QInfo::Minerals, 1, 3, QString::asprintf("%ld [%ld]", world->getMinerals(),
                                                                world->getModMinerals()));
    addInfo(QInfo::Food, 1, 4, QString::asprintf("%ld [%ld]", world->getFood(),
                                                            world->getModFood()));
    addInfo(QInfo::Capacity, 1, 5, QString::asprintf("%ld", world->getCapacity()));
    addInfo(QInfo::Solidarity, 1, 6, QString::asprintf("%3.2f %%",
                                                                  double(world->getSolidarity())));
    addInfo(QInfo::Pollution, 1, 7,
                       QString::asprintf("%3.2f %% [%3.2f %%]", double(world->getPolltion()),
                                         double(world->getModPollution())));
    addInfo(QInfo::Science, 1, 8, QString::asprintf("%ld [%ld]", world->getScience(),
                                                               world->getModScience()));
}

void QGameInfoPanel::installActionEventInfo()
{
    addInfo(QInfo::War, 2, 0, world->getInfoActionEvent(WorldActionEvents::War).data());
    addInfo(QInfo::Epidemic, 2, 1,
                       world->getInfoActionEvent(WorldActionEvents::Epidemic).data());
    addInfo(QInfo::Revolution, 2, 2,
                       world->getInfoActionEvent(WorldActionEvents::Revolution).data());
    addInfo(QInfo::ActOfTerrorism, 2, 3,
                       world->getInfoActionEvent(WorldActionEvents::ActOfTerrorism).data());
    addInfo(QInfo::AlienAttack, 2, 4,
                       world->getInfoActionEvent(WorldActionEvents::AlienAttack).data());
    addInfo(QInfo::GlobalCataclysm, 2, 5,
                       world->getInfoActionEvent(WorldActionEvents::GlobalCataclysm).data());
    addInfo(QInfo::GlobalAccident, 2, 6,
                       world->getInfoActionEvent(WorldActionEvents::GlobalAccident).data());
    addInfo(QInfo::PastEvent, 2, 7,
                       ("Past event " + world->getCurrentEvent()).data());
}

void QGameInfoPanel::updateWorldStatsInfo()
{
    updateInfo(QInfo::Year, QString::asprintf("%ld", world->getYear()));
    updateInfo(QInfo::Population, QString::asprintf("%ld", world->getPopulation()));
    updateInfo(QInfo::Energy, QString::asprintf("%ld [%ld]", world->getEnergy(),
                                                           world->getModEnergy()));
    updateInfo(QInfo::Minerals, QString::asprintf("%ld [%ld]", world->getMinerals(),
                                                             world->getModMinerals()));
    updateInfo(QInfo::Food, QString::asprintf("%ld [%ld]", world->getFood(),
                                                         world->getModFood()));
    updateInfo(QInfo::Capacity, QString::asprintf("%ld", world->getCapacity()));
    updateInfo(QInfo::Solidarity, QString::asprintf("%3.2f %%",
                                                               double(world->getSolidarity())));
    updateInfo(QInfo::Pollution,
                          QString::asprintf("%3.2f %% [%3.2f %%]", double(world->getPolltion()),
                                            double(world->getModPollution())));
    updateInfo(QInfo::Science, QString::asprintf("%ld [%ld]", world->getScience(),
                                                            world->getModScience()));
}

void QGameInfoPanel::updateActionEventInfo()
{
    updateInfo(QInfo::War, world->getInfoActionEvent(WorldActionEvents::War).data());
    updateInfo(QInfo::Epidemic,
                          world->getInfoActionEvent(WorldActionEvents::Epidemic).data());
    updateInfo(QInfo::Revolution,
                          world->getInfoActionEvent(WorldActionEvents::Revolution).data());
    updateInfo(QInfo::ActOfTerrorism,
                          world->getInfoActionEvent(WorldActionEvents::ActOfTerrorism).data());
    updateInfo(QInfo::AlienAttack,
                          world->getInfoActionEvent(WorldActionEvents::AlienAttack).data());
    updateInfo(QInfo::GlobalCataclysm,
                          world->getInfoActionEvent(WorldActionEvents::GlobalCataclysm).data());
    updateInfo(QInfo::GlobalAccident,
                          world->getInfoActionEvent(WorldActionEvents::GlobalAccident).data());
    updateInfo(QInfo::PastEvent,
                          ("Past event " + world->getCurrentEvent()).data());
}

void QGameInfoPanel::update()
{
    updateWorldStatsInfo();
    updateActionEventInfo();
}
