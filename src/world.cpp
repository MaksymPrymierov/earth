#include "headers/world.h"
#include <QtCore/QCoreApplication>
#include <QtWidgets>


QWorld::QWorld(QObject *parent) :
    QObject(parent), year(0), population(300), energy(100), minerals(100), food(100), science(0),
    pollution(0), solidarity(60)
{}

QWorld::~QWorld()
{
    delete energyStations;
    delete mines;
    delete farms;
    delete labs;
    delete cleaningStation;
}

QString QWorld::getInfoYear()
{
    return QString::asprintf("Year\n %lld", year);
}

QString QWorld::getInfoPopulation()
{
    return QString::asprintf("Population\n %lldk", population);
}

QString QWorld::getInfoEnergy()
{
    return QString::asprintf("Energy\n %lld [%lld]", energy, getModEnergy());
}

QString QWorld::getInfoMinerals()
{
    return QString::asprintf("Minerals\n %lld [%lld]", minerals, getModMinerals());
}

QString QWorld::getInfoFood()
{
    return QString::asprintf("Food\n %lld [%lld]", food, getModFood());
}

QString QWorld::getInfoScience()
{
    return QString::asprintf("Science\n %lld [%lld]", science, getModScience());
}

QString QWorld::getInfoPollution()
{
    return QString::asprintf("Pollution\n %3.2f %% [%3.2f %%]", double(pollution),
                             double(getModPollution()));
}

QString QWorld::getInfoSolidarity()
{
    return QString::asprintf("Solidarity\n %3.2f %%", double(solidarity));
}

qint64 QWorld::getModEnergy()
{
    return energyStations->getFullModEnergy() + mines->getFullModEnergy() + \
            farms->getFullModEnergy() + labs->getFullModEnergy() + \
            cleaningStation->getFullModEnergy();
}

qint64 QWorld::getModMinerals()
{
    if (energy > 0) {
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

qint64 QWorld::getModFood()
{
    if (energy > 0) {
        return farms->getFullModFood() - qint64(population * 0.01);
    } else {
        return 0;
    }
}

qint64 QWorld::getModScience()
{
    if (energy > 0) {
        return labs->getFullModScience();
    } else {
        return 0;
    }
}

void QWorld::preUpdate()
{
    if (population == 0)
        QCoreApplication::quit();
}

void QWorld::updateEnergyStations()
{
    energy += energyStations->getFullModEnergy();
    pollution += energyStations->getFullModPollution();
}

void QWorld::updateMines()
{
    if (energy > 0) {
        energy += mines->getFullModEnergy();
        pollution += mines->getFullModPollution();
        minerals += mines->getFullModMinerals();
    }
}

void QWorld::updateFarms()
{
    if (energy > 0) {
        energy += farms->getFullModEnergy();
        food += farms->getFullModFood();
    }
}

void QWorld::updateLabs() {
    if ((energy > 0) && (minerals > 0))
    {
        energy += labs->getFullModEnergy();
        minerals += labs->getFullModMinerals();
        science += labs->getFullModScience();
    }
}

void QWorld::updateCleaningStation()
{
    if (energy > 0) {
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

    emit yearUpdate(getInfoYear());
    emit populationUpdate(getInfoPopulation());
    emit energyUpdate(getInfoEnergy());
    emit mineralsUpdate(getInfoMinerals());
    emit foodUpdate(getInfoFood());
    emit scienceUpdate(getInfoScience());
    emit pullutionUpdate(getInfoPollution());
    emit solidarityUpdate(getInfoSolidarity());
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

void QWorld::checkEnergy()
{
    if (energy <= 0) {
        energy = 0;
        solidarity -= float(0.01);
    }
}

void QWorld::checkMinerals()
{
    if (minerals <= 0) {
        minerals = 0;
        solidarity -= float(0.01);
    }
}

void QWorld::checkFood()
{
    if (food <= 0) {
        food = 0;
        solidarity -= float(0.01);
        population -= population * 0.01;
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
