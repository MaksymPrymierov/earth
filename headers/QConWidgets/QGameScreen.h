#pragma once

#include <QtWidgets>
#include "QButtonsPanel/QButtonsPanel.h"
#include "QTextPanel.h"
#include "headers/World/World.h"

#include "headers/QConWidgets/QButtonsPanel/QMainMenuPanel.h"
#include "headers/QConWidgets/QButtonsPanel/QActionPanel.h"
#include "headers/QConWidgets/QButtonsPanel/QBuildPanel.h"
#include "headers/QConWidgets/QButtonsPanel/QDestroyPanel.h"
#include "headers/QConWidgets/QButtonsPanel/QSciencePanel.h"

enum class QButtonPanel : quint8
{
    Menu = 0, Action, Building, Destroy, Science
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
    void showMenuPanel();
    void showActionPanel();
    void showBuildPanel();
    void showDestroyPanel();
    void showSciencePanel();

protected:
    inline void handlerMenuPanel();
    inline void handlerActionPanel();
    inline void handlerBuildPanel();
    inline void handlerDestroyPanel();
    inline void handlerSciencePanel();

    inline void installHeader();
    inline void installFooter();
    inline void installInfoPanel();
    void updateInfoPanel();

    inline QPushButton* button(QButtonPanel panel, QButton button);
    inline void setTextLabel(QButtonPanel panel, QButton button, QString text);

    bool event(QEvent *event);

private:
    World *world = new World(this);
    QPalette *pall = new QPalette();

    QStackedWidget *header = new QStackedWidget();
    QStackedWidget *footer = new QStackedWidget();
    QVBoxLayout *generalLayout = new QVBoxLayout();

    QTextPanel *textPanel = new QTextPanel();
    QMainMenuPanel *mainMenuPanel = new QMainMenuPanel();
    QActionPanel *actionPanel = new QActionPanel();
    QBuildPanel *buildPanel = new QBuildPanel();
    QDestroyPanel *destroyPanel = new QDestroyPanel();
    QSciencePanel *sciencePanel = new QSciencePanel();
};
