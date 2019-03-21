#pragma once

#include <QBrush>
#include <QString>

class QConResources
{
public:
    QConResources();
    ~QConResources() = default;

    void setMainMenuTheme(QString path);

    QBrush* getMainMenuTheme();

private:
    QBrush mainMenuTheme;
};
