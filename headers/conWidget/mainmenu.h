#ifndef MAINMENU_H
#define MAINMENU_H

#include <QtWidgets>
#include "buttonspanel.h"

class MainMenu : public QWidget {
  Q_OBJECT
private:
  QColor *background = new QColor(18, 46, 62);
  QPixmap *pix;
  QLabel *title = new QLabel();
  QPalette *pall = new QPalette();
  QVBoxLayout *generalLayout = new QVBoxLayout();
  ButtonsPanel *menu = new ButtonsPanel(QBoxLayout::Direction::TopToBottom);

  void setTitle(QString text);
  void installMenu();

public:
  explicit MainMenu(QWidget *parent = nullptr);
signals:
  void clickedNewGame();
  void clickedExit();
};

#endif // MAINMENU_H
