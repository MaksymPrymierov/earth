#ifndef MAINMENU_H
#define MAINMENU_H

#include <QtWidgets>
#include "buttonspanel.h"

class QMainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit QMainMenu(QWidget *parent = nullptr);
    ~QMainMenu();

signals:
    void clickedNewGame();
    void clickedExit();

protected:
    void setTitle(QString text);
    void installMenu();

private:
    QPalette *pall = new QPalette();

    QLabel *title = new QLabel();
    QButtonsPanel *menu = new QButtonsPanel();

    QVBoxLayout *generalLayout = new QVBoxLayout();

};

#endif // MAINMENU_H
