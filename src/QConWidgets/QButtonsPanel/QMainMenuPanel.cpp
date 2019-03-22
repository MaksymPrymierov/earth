#include "headers/QConWidgets/QButtonsPanel/QMainMenuPanel.h"

QMainMenuPanel::QMainMenuPanel()
{
    setTitle("Select an action");

    addButton(QButton::Save, 0, 0, "Save");
    addButton(QButton::Load, 0, 1, "Load");
    addButton(QButton::ExitToMenu, 0, 2, "Exit to Menu");
    addButton(QButton::Exit, 0, 3, "Exit");

    setAlignmentContent(Qt::AlignCenter);
}
