#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QtWidgets>
#include "buttonspanel.h"
#include "../world.h"

enum class ButtonPanel : quint8 {
  Menu, Action, Building
};

class GameScreen : public QWidget {
  Q_OBJECT
private:
  World *world = new World();
  QPalette *pall = new QPalette();

  QStackedWidget *header = new QStackedWidget();
  QStackedWidget *footer = new QStackedWidget();
  QVBoxLayout *generalLayout = new QVBoxLayout();

  QLabel *textPanel = new QLabel();

  QMap<ButtonPanel, ButtonsPanel*> buttonsPanels;

public:
  explicit GameScreen(QWidget *parent = nullptr);
  ~GameScreen();

private:
  void addMenuPanel();
  void addActionPanel();
  void addBuildPanel();

  void installHeader();
  void installFooter();
  void installInfoPanel();

signals:
  void clickedMenu();
  void clickedExit();

public slots:
  inline void showMenuPanel() { header->setCurrentWidget(buttonsPanels[ButtonPanel::Menu]); }
  inline void showActionPanel() { footer->setCurrentWidget(buttonsPanels[ButtonPanel::Action]); }
  inline void showBuildPanel() { footer->setCurrentWidget(buttonsPanels[ButtonPanel::Building]); }

};

#endif // GAMESCREEN_H
