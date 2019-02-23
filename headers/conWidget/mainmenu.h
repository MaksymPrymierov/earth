#ifndef MAINMENU_H
#define MAINMENU_H

#include <QtWidgets>
#include "buttonspanel.h"

class MainMenu : public QWidget {
  Q_OBJECT
private:
  QPalette *pall = new QPalette();

  QLabel *title = new QLabel();
  ButtonsPanel *menu = new ButtonsPanel();

  QVBoxLayout *generalLayout = new QVBoxLayout();

  void setTitle(QString text);
  void installMenu();

public:
  explicit MainMenu(QWidget *parent = nullptr);
  ~MainMenu();

signals:
  void clickedNewGame();
  void clickedExit();

};

#endif // MAINMENU_H
