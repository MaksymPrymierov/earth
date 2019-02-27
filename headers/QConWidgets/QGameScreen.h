#pragma once

#include <QtWidgets>
#include "QButtonsPanel.h"
#include "QTextPanel.h"
#include "../QWorld.h"

enum class QButtonPanel : quint8
{
    Menu = 0, Action, Building, Destroy
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
    void showActionPanel(QButtonsPanel *panel = nullptr);
    void showBuildPanel();
    void showDestroyPanel();

protected:
    void addMenuPanel();
    void addActionPanel();
    void addBuildPanel();
    void addDestroyPanel();

    inline void installHeader();
    inline void installFooter();
    inline void installInfoPanel();
    void updateInfoPanel();

    inline QPushButton* button(QButtonPanel panel, QButton button);
    inline void setTextLabel(QButtonPanel panel, QButton button, QString text);

    bool event(QEvent *event);

private:
    QWorld *world = new QWorld(this);
    QPalette *pall = new QPalette();

    QStackedWidget *header = new QStackedWidget();
    QStackedWidget *footer = new QStackedWidget();
    QVBoxLayout *generalLayout = new QVBoxLayout();

    QTextPanel *textPanel = new QTextPanel();

    QMap<QButtonPanel, QButtonsPanel*> buttonsPanels;
};
