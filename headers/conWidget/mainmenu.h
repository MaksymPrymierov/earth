#ifndef MAINMENU_H
#define MAINMENU_H

#include <QtWidgets>
#include "buttonspanel.h"

class MainMenu : public QWidget {
  Q_OBJECT
private:
  QPixmap *pix;
  QLabel *title = new QLabel();
  QPalette *pall = new QPalette();
  QBrush *brush = new QBrush(Qt::TexturePattern);
  QVBoxLayout *generalLayout = new QVBoxLayout();
  ButtonsPanel *menu = new ButtonsPanel();

  void setTitle(QString text);
  void installMenu();

public:
  explicit MainMenu(QWidget *parent = nullptr);
signals:
  void clickedNewGame();
  void clickedExit();
};

#endif // MAINMENU_H
