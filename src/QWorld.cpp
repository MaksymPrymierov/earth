#include "headers/QWorld.h"
#include <QCoreApplication>
#include <sstream>

QWorldEvent::QWorldEvent(Type type) :
    QEvent(type)
    { }

QWorld::QWorld(QObject *receiverEvent) :
    year(0), population(100), energy(10), minerals(10), food(10), science(0),
    pollution(0), solidarity(40), receiver(receiverEvent)
    { }

QWorld::~QWorld()
{
    delete energyStations;
    delete mines;
    delete farms;
    delete labs;
    delete cleaningStation;
    delete stock;
}

std::string QWorld::getInfoYear()
{
    std::stringstream s;
    s << "Year\n " << year;
    return s.str();
}

std::string QWorld::getInfoPopulation()
{
    std::stringstream s;
    s << "Population\n " << population;
    return s.str();
}

std::string QWorld::getInfoEnergy()
{
    std::stringstream s;
    s << "Energy\n " << energy << " [" << getModEnergy() << "]";
    return s.str();
};

std::string QWorld::getInfoMinerals()
{
    std::stringstream s;
    s << "Minerals\n " << minerals << " [" << getModMinerals() << "]";
    return s.str();
}

std::string QWorld::getInfoFood()
{
    std::stringstream s;
    s << "Food\n " << food << " [" << getModFood() << "]";
    return s.str();
}

std::string QWorld::getInfoScience()
{
    std::stringstream s;
    s << "Science\n " << science << " [" << getModScience() << "]";
    return s.str();
}

std::string QWorld::getInfoPollution()
{
    std::stringstream s;
    s << "Polltion\n " << pollution << " [" << getModPollution() << "]";
    return s.str();
}

std::string QWorld::getInfoSolidarity()
{
    std::stringstream s;
    s << "Solidarity\n " << solidarity;
    return s.str();
}

std::string QWorld::getInfoCapacity()
{
    std::stringstream s;
    s << "Capacity of Stocks\n " << stock->getFullCapacity();
    return s.str();
}

int64_t QWorld::getModEnergy()
{
    return energyStations->getFullModEnergy() + mines->getFullModEnergy() + \
            farms->getFullModEnergy() + labs->getFullModEnergy() + \
            cleaningStation->getFullModEnergy();
}

int64_t QWorld::getModMinerals()
{
    if (energy >= mines->getFullModMinerals ()) {
        return mines->getFullModMinerals() + labs->getFullModMinerals() + \
                cleaningStation->getFullModMinerals();
    } else {
        return 0;
    }
}

float QWorld::getModPollution()
{
    float m = energyStations->getFullModPollution() + mines->getModPollution();
    if (energy > 0) {
        m += cleaningStation->getFullModPollution();
    }
    return m;
}

int64_t QWorld::getModFood()
{
    if (energy > 0) {
        return farms->getFullModFood() - qint64(population * 0.01);
    } else {
        return 0;
    }
}

int64_t QWorld::getModScience()
{
    if (energy > 0) {
        return labs->getFullModScience();
    } else {
        return 0;
    }
}

void QWorld::preUpdate()
{
    if (population <= 0) {
        qDebug("Людю бо-бо");
    }
}

void QWorld::updateEnergyStations()
{
    energy += energyStations->getFullModEnergy();
    pollution += energyStations->getFullModPollution();
}

void QWorld::updateMines()
{
    if (energy >= mines->getFullModEnergy()) {
        energy += mines->getFullModEnergy();
        pollution += mines->getFullModPollution();
        minerals += mines->getFullModMinerals();
    }
}

void QWorld::updateFarms()
{
    if (energy >= farms->getFullModEnergy()) {
        energy += farms->getFullModEnergy();
        food += farms->getFullModFood();
    }
}

void QWorld::updateLabs() {
    if ((energy >= labs->getFullModEnergy()) && (minerals >= labs->getFullModMinerals())) {
        energy += labs->getFullModEnergy();
        minerals += labs->getFullModMinerals();
        science += labs->getFullModScience();
    }
}

void QWorld::updateCleaningStation()
{
    if (energy >= cleaningStation->getFullModEnergy()) {
        energy += cleaningStation->getFullModEnergy();
        minerals += cleaningStation->getFullModMinerals();
        pollution += cleaningStation->getFullModPollution();
    }
}

void QWorld::postUpdate()
{
    checkEnergy();
    checkMinerals();
    checkFood();
    checkPollution();
    checkSolidarity();

    ++year;
}

void QWorld::update()
{
    preUpdate();

    updateEnergyStations();
    updateMines();
    updateFarms();
    updateLabs();
    updateCleaningStation();

    postUpdate();

    QCoreApplication::postEvent(receiver, new QWorldEvent(WorldEvent));
}

void QWorld::buildEnergyStation()
{
    if (minerals < energyStations->getPriceMinerals())
        return;

    minerals -= energyStations->getPriceMinerals();
    energyStations->build();

    update();
}

void QWorld::buildMine()
{
    if (minerals < mines->getPriceMinerals())
        return;

    minerals -= mines->getPriceMinerals();
    mines->build();

    update();
}

void QWorld::buildFarm()
{
    if (minerals < farms->getPriceMinerals())
        return;

    minerals -= farms->getPriceMinerals();
    farms->build();

    update();
}

void QWorld::buildLab()
{
    if(minerals < labs->getPriceMinerals())
        return;

    minerals -= labs->getPriceMinerals();
    labs->build();

    update();
}

void QWorld::buildCleaningStation()
{
    if (minerals < cleaningStation->getPriceMinerals())
        return;

    minerals -= cleaningStation->getPriceMinerals();
    cleaningStation->build();

    update();
}

void QWorld::buildStock() {
    if (minerals < stock->getPriceMinerals())
        return;

    minerals -= stock->getPriceMinerals();
    stock->build();

    update();
}

void QWorld::checkEnergy()
{
    if (energy <= 0) {
        energy = 0;
        solidarity -= float(0.01);
    } else if (energy >= stock->getFullCapacity()) {
        energy = stock->getFullCapacity();
        solidarity += float(0.01);
    }
}

void QWorld::checkMinerals()
{
    if (minerals <= 0) {
        minerals = 0;
        solidarity -= float(0.01);
    } else if (minerals >= stock->getFullCapacity()) {
        minerals = stock->getFullCapacity();
        solidarity += float(0.01);
    }
}

void QWorld::checkFood()
{
    if (food <= 0) {
        food = 0;
        solidarity -= float(0.01);
        population -= population * 0.01;
    } else if (food >= stock->getFullCapacity()) {
        food = stock->getCapacity();
        solidarity += float(0.02);
        population += population * 0.02;
    } else {
        food -= population * 0.01;
        solidarity += float(0.01);
        population += population * 0.01;
    }
}

void QWorld::checkPollution()
{
    if (pollution <= 0) {
        pollution = 0;
    } else if (pollution >= 100) {
        pollution = 100;
        solidarity -= float(0.05);
    } else if (pollution >= 50) {
        solidarity -= float(0.01);
    }

}

void QWorld::checkSolidarity()
{
    if (solidarity <= 0) {
        solidarity = 0;
    } else if (solidarity >= 100) {
        solidarity = 100;
    }
}

void QWorld::destroyLab()
{
    if (labs->getQuantity() == 0)
        return;

    labs->destroy();

    update();
}

void QWorld::destroyFarm()
{
    if (farms->getQuantity() == 0)
        return;

    farms->destroy();

    update();
}

void QWorld::destroyMine()
{
    if (mines->getQuantity() == 0)
        return;

    mines->destroy();

    update();
}

void QWorld::destroyStock()
{
    if (stock->getQuantity() == 1)
        return;

    stock->destroy();

    update();
}

void QWorld::destroyEnergyStation()
{
    if (energyStations->getQuantity() == 0)
        return;

    energyStations->destroy();

    update();
}

void QWorld::destroyCleaningStation()
{
    if (cleaningStation->getQuantity() == 0)
        return;

    cleaningStation->destroy();

    update();
}
