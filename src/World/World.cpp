#include "headers/World/World.h"
#include <QCoreApplication>
#include <sstream>

QWorldEvent::QWorldEvent(Type type) :
    QEvent(type)
    { }

World::World(QObject *receiverEvent) :
    receiver(receiverEvent)
    {}

int64_t World::getModEnergy()
{
    return energyStations.getFullModEnergy() + mines.getFullModEnergy() + \
            farms.getFullModEnergy() + labs.getFullModEnergy() + \
            cleaningStation.getFullModEnergy();
}

int64_t World::getModMinerals()
{
    if (resources.energy >= mines.getFullModMinerals ()) {
        return mines.getFullModMinerals() + labs.getFullModMinerals() + \
                cleaningStation.getFullModMinerals();
    } else {
        return 0;
    }
}

float World::getModPollution()
{
    float m = energyStations.getFullModPollution() + mines.getModPollution();
    if (resources.energy > 0) {
        m += cleaningStation.getFullModPollution();
    }
    return m;
}

int64_t World::getModFood()
{
    if (resources.energy > 0) {
        return farms.getFullModFood() - qint64(resources.pollution * float(0.01));
    } else {
        return 0;
    }
}

int64_t World::getModScience()
{
    if (resources.energy > 0) {
        return labs.getFullModScience();
    } else {
        return 0;
    }
}

void World::preUpdate()
{
    if (resources.energy <= 0) {
        qDebug("Людю бо-бо");
    }
}

void World::updateEnergyStations()
{
    resources.energy += energyStations.getFullModEnergy();
    resources.pollution += energyStations.getFullModPollution();
}

void World::updateMines()
{
    if (resources.energy >= mines.getFullModEnergy()) {
        resources.energy += mines.getFullModEnergy();
        resources.pollution += mines.getFullModPollution();
        resources.minerals += mines.getFullModMinerals();
    }
}

void World::updateFarms()
{
    if (resources.energy >= farms.getFullModEnergy()) {
        resources.energy += farms.getFullModEnergy();
        resources.food += farms.getFullModFood();
    }
}

void World::updateLabs() {
    if ((resources.energy >= labs.getFullModEnergy()) && (resources.minerals >= labs.getFullModMinerals())) {
        resources.energy += labs.getFullModEnergy();
        resources.minerals += labs.getFullModMinerals();
        resources.science += labs.getFullModScience();
    }
}

void World::updateCleaningStation()
{
    if (resources.energy >= cleaningStation.getFullModEnergy()) {
        resources.energy += cleaningStation.getFullModEnergy();
        resources.minerals += cleaningStation.getFullModMinerals();
        resources.pollution += cleaningStation.getFullModPollution();
    }
}

void World::updateActionEvent()
{
    if (resources.year > 1 && (resources.year % 50 == 0)) {
        actionEvent.changeEvent();
    }
}

void World::postUpdate()
{
    checkEnergy();
    checkMinerals();
    checkFood();
    checkPollution();
    checkSolidarity();
    checkActionEvent();

    ++resources.year;
}

void World::update()
{
    preUpdate();

    updateEnergyStations();
    updateMines();
    updateFarms();
    updateLabs();
    updateCleaningStation();
    updateActionEvent();

    postUpdate();

    QCoreApplication::postEvent(receiver, new QWorldEvent(WorldEvent));
}

void World::buildEnergyStation()
{
    if(resources.minerals < energyStations.getPriceMinerals())
        return;

    resources.minerals -= energyStations.getPriceMinerals();
    energyStations.build();

    update();
}

void World::buildMine()
{
    if(resources.minerals < mines.getPriceMinerals())
        return;

    resources.minerals -= mines.getPriceMinerals();
    mines.build();

    update();
}

void World::buildFarm()
{
    if(resources.minerals < farms.getPriceMinerals())
        return;

    resources.minerals -= farms.getPriceMinerals();
    farms.build();

    update();
}

void World::buildLab()
{
    if(resources.minerals < labs.getPriceMinerals())
        return;

    resources.minerals -= labs.getPriceMinerals();
    labs.build();

    update();
}

void World::buildCleaningStation()
{
    if(resources.minerals < cleaningStation.getPriceMinerals())
        return;

    resources.minerals -= cleaningStation.getPriceMinerals();
    cleaningStation.build();

    update();
}

void World::buildStock() {
    if(resources.minerals < stock.getPriceMinerals())
        return;

    resources.minerals -= stock.getPriceMinerals();
    stock.build();

    update();
}

void World::checkEnergy()
{
    if (resources.energy <= 0) {
        resources.energy = 0;
        resources.solidarity -= float(0.01);
        actionEvent.set(WorldActionEvents::Revolution);
        actionEvent.set(WorldActionEvents::GlobalAccident);
    } else if (resources.energy >= stock.getFullCapacity()) {
        resources.energy = stock.getFullCapacity();
        resources.solidarity += float(0.01);
        actionEvent.set(WorldActionEvents::War);
    }
}

void World::checkMinerals()
{
    if (resources.minerals <= 0) {
        resources.minerals = 0;
        resources.solidarity -= float(0.01);
        actionEvent.set(WorldActionEvents::Revolution);
    } else if(resources.minerals >= stock.getFullCapacity()) {
        resources.minerals = stock.getFullCapacity();
        resources.solidarity += float(0.01);
        actionEvent.set(WorldActionEvents::War);
    }
}

void World::checkFood()
{
    if (resources.food <= 0) {
        resources.food = 0;
        resources.solidarity -= float(0.01);
        resources.population -=  resources.population * 0.01;
        actionEvent.set(WorldActionEvents::Revolution);
    } else if  (resources.food >= stock.getFullCapacity()) {
        resources.food = stock.getCapacity();
        resources.solidarity += float(0.02);
        resources.population += resources.population * 0.02;
        actionEvent.set(WorldActionEvents::ActOfTerrorism);
    } else {
        resources.food -=  resources.population * 0.01;
        resources.solidarity += float(0.01);
        resources.population +=  resources.population * 0.01;
    }
}

void World::checkPollution()
{
    if (resources.pollution <= 0) {
        resources.pollution = 0;
    } else if (resources.pollution >= 100) {
        resources.pollution = 100;
        resources.solidarity -= float(0.05);
        actionEvent.set(WorldActionEvents::GlobalCataclysm);
        actionEvent.set(WorldActionEvents::Epidemic);
    } else if (resources.pollution >= 50) {
        resources.solidarity -= float(0.01);
    }

}

void World::checkSolidarity()
{
    if (resources.solidarity <= 0) {
        resources.solidarity = 0;
        actionEvent.set(WorldActionEvents::War);
        actionEvent.set(WorldActionEvents::Revolution);
        actionEvent.set(WorldActionEvents::ActOfTerrorism);
    } else if (resources.solidarity >= 100) {
        resources.solidarity = 100;
    }
}

void World::checkActionEvent()
{
    switch (actionEvent.get()) {
    case WorldActionEvents::War :
         resources.population -= int(resources.population * 0.0058);
        break;
    case WorldActionEvents::Epidemic :
         resources.population -= int(resources.population * 0.013);
        break;
    case WorldActionEvents::Revolution :
         resources.population -= int(resources.population * 0.001);
        break;
    case WorldActionEvents::AlienAttack :
         resources.population -= int(resources.population * 0.5);
        break;
    case WorldActionEvents::ActOfTerrorism :
         resources.population -= int(resources.population * 0.001);
        break;
    case WorldActionEvents::GlobalAccident :
         resources.population -= int(resources.population * 0.001);
        break;
    case WorldActionEvents::GlobalCataclysm :
         resources.population -= int(resources.population * 0.4);
        break;
    default:
        break;
    }
}

void World::destroyLab()
{
    if (labs.getQuantity() == 0)
        return;

    labs.destroy();

    update();
}

void World::destroyFarm()
{
    if (farms.getQuantity() == 0)
        return;

    farms.destroy();

    update();
}

void World::destroyMine()
{
    if (mines.getQuantity() == 0)
        return;

    mines.destroy();

    update();
}

void World::destroyStock()
{
    if (stock.getQuantity() == 1)
        return;

    stock.destroy();

    update();
}

void World::destroyEnergyStation()
{
    if (energyStations.getQuantity() == 0)
        return;

    energyStations.destroy();

    update();
}

void World::destroyCleaningStation()
{
    if (cleaningStation.getQuantity() == 0)
        return;

    cleaningStation.destroy();

    update();
}
