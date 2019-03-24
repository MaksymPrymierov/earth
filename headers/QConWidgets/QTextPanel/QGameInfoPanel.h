#pragma once

#include "headers/QConWidgets/QTextPanel/QTextPanel.h"
#include "headers/World/World.h"

class QGameInfoPanel : public QTextPanel
{
    Q_OBJECT
public:
    QGameInfoPanel(World *source, QTextPanel *parent = nullptr);
    ~QGameInfoPanel() = default;

    void update();

private:
    World *world;

    inline void installWorldStatsInfo();
    inline void installActionEventInfo();

    inline void updateWorldStatsInfo();
    inline void updateActionEventInfo();
};
