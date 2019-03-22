#include "headers/QConWidgets/QButtonsPanel/QActionPanel.h"

QActionPanel::QActionPanel()
{
    addButton(QButton::Building, 0, 0, "Building");
    addButton(QButton::Destroy, 0, 1, "Destroy");
    addButton(QButton::Science, 0, 2, "Science");
    addButton(QButton::Events, 0, 3, "Events");

    setAlignmentContent(Qt::AlignCenter);
}
