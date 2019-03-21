#include <QString>
#include <QtWidgets>

#include "headers/QConWidgets/QGameMainWindow.h"
#include "headers/QConResources.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QConResources r;

    r.setMainMenuTheme(":/images/mainMenuBackground-1368x768");

    QGameMainWindow *mainWindow = new QGameMainWindow(&r);
    mainWindow->show();

    return a.exec();
}
