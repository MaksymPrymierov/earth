#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QtWidgets>
#include "buttonspanel.h"
#include "textpanel.h"
#include "../world.h"

enum class QButtonPanel : quint8
{
    Menu = 0, Action, Building
};

class QGameScreen : public QWidget
{
    Q_OBJECT
public:
    explicit QGameScreen(QWidget *parent = nullptr);
    ~QGameScreen();

signals:
    void clickedMenu();
    void clickedExit();

public slots:
    inline void showMenuPanel() { header->setCurrentWidget(buttonsPanels[QButtonPanel::Menu]); }
    inline void showActionPanel() { footer->setCurrentWidget(buttonsPanels[QButtonPanel::Action]); }
    inline void showBuildPanel() { footer->setCurrentWidget(buttonsPanels[QButtonPanel::Building]); }

protected:
    void addMenuPanel();
    void addActionPanel();
    void addBuildPanel();

    void installHeader();
    void installFooter();
    void installInfoPanel();

private:
    QWorld *world = new QWorld();
    QPalette *pall = new QPalette();

    QStackedWidget *header = new QStackedWidget();
    QStackedWidget *footer = new QStackedWidget();
    QVBoxLayout *generalLayout = new QVBoxLayout();

    QTextPanel *textPanel = new QTextPanel();

    QMap<QButtonPanel, QButtonsPanel*> buttonsPanels;
};

#endif // GAMESCREEN_H
