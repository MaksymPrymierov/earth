#include "headers/QConResources.h"

QConResources::QConResources()
{

}

void QConResources::setMainMenuTheme(QString path)
{
    mainMenuTheme = QBrush(QPixmap(path));
}

QBrush* QConResources::getMainMenuTheme()
{
    return &mainMenuTheme;
}
