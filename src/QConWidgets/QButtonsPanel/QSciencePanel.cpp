#include "headers/QConWidgets/QButtonsPanel/QSciencePanel.h"

QSciencePanel::QSciencePanel()
{
    setTitle("Research");

    addButton(QButton::PowerStation, 0, 0, "Power station");
    addButton(QButton::Mine, 0, 1, "Mine");
    addButton(QButton::Farm, 0, 2, "Farm");
    addButton(QButton::Laboratory, 0, 3, "Laboratory");
    addButton(QButton::CleaningStation, 0, 4, "Cleaning Station");
    addButton(QButton::Stock, 0, 5, "Stock");
    addButton(QButton::Cancel, 0, 6, "Cancel");

    setAlignmentContent(Qt::AlignCenter);
}
