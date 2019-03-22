#include "headers/QConWidgets/QButtonsPanel/QBuildPanel.h"

QBuildPanel::QBuildPanel()
{
    setTitle("Building");

    addButton(QButton::PowerStation, 0, 0, "Power station");
    addButton(QButton::Mine, 0, 1, "Mine");
    addButton(QButton::Farm, 0, 2, "Farm");
    addButton(QButton::Laboratory, 0, 3, "Laboratory");
    addButton(QButton::CleaningStation, 0, 4, "Cleaning Station");
    addButton(QButton::Stock, 0, 5, "Stock");
    addButton(QButton::Cancel, 0, 6, "Cancel");

    addInfo(QButton::PowerStation, 1, 0, "Power Station");
    addInfo(QButton::Mine, 1, 1, "Mine");
    addInfo(QButton::Farm, 1, 2, "Farm");
    addInfo(QButton::Laboratory, 1, 3, "Laboratory");
    addInfo(QButton::CleaningStation, 1, 4, "Cleaning Station");
    addInfo(QButton::Stock, 1, 5, "Stock");

    setAlignmentContent(Qt::AlignCenter);
}
