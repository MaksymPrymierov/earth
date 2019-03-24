#pragma once

#include <QtWidgets>
#include <string>

enum class QInfo : quint8
{
    Year = 0, Population, Energy, Minerals, Food,
    Science, Pollution, Solidarity, Capacity, War,
    Epidemic, Revolution, ActOfTerrorism, AlienAttack, GlobalCataclysm,
    GlobalAccident, Risks, PastEvent, InfoYear, InfoPopulation,
    InfoEnergy, InfoMinerals, InfoFood, InfoScience, InfoPollution,
    InfoSolidarity, InfoCapacity
};

class QTextPanel : public QWidget
{
    Q_OBJECT
public:
    explicit QTextPanel(QWidget *parent = nullptr);
    ~QTextPanel();

    void addInfo(QInfo type, int row, int column, QString info);
    void updateInfo(QInfo type, QString info) { labels[type]->setText(info); }

    inline QLabel* getLabel(QInfo type) { return labels[type]; }

private:
    QGridLayout *layout = new QGridLayout();
    QMap<QInfo, QLabel*> labels;
};
