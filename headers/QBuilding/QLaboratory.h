#pragma once

#include "QBuilding.h"

class QLaboratory : public QBuilding
{
    Q_OBJECT
public:
    explicit QLaboratory(QBuilding *parent = nullptr);
    ~QLaboratory() = default;

    inline void setModMinerals(qint64 m) { modScience = m; }
    inline void setModScience(qint64 m) { modMinerals = m; }

    inline qint64 getModMinerals() { return modMinerals; }
    inline qint64 getModScience() { return modScience; }
    inline qint64 getFullModMinerals() { return modMinerals * getQuantity(); }
    inline qint64 getFullModScience() { return modScience * getQuantity(); }
    QString getInfo();

private:
    qint64 modMinerals;
    qint64 modScience;
};
