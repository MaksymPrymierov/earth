#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QtWidgets>
#include "buttonspanel.h"

enum class ButtonPanel : quint8 {
  Menu, Action, Building
};

class GameScreen : public QWidget {
  Q_OBJECT
private:
  QWidget *infoPanel = new QWidget();
  QStackedWidget *header = new QStackedWidget();
  QStackedWidget *footer = new QStackedWidget();
  QPalette *pall = new QPalette();
  QVBoxLayout *generalLayout = new QVBoxLayout();
  QMap<ButtonPanel, ButtonsPanel*> buttonsPanels;
public:
  explicit GameScreen(QWidget *parent = nullptr);

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
  void showMenuPanel();
  void showActionPanel();
  void showBuildPanel();
};

#endif // GAMESCREEN_H
