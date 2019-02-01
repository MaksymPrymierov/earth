#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define GENERAL_LAYOUT 0

#include <QtWidgets>

class MainWindow : public QWidget
{
  Q_OBJECT
private:
  int x, y;
  QLabel *info = new QLabel();
  QPalette *pall = new QPalette();
  QList<QPushButton*> buttons;
  QList<QLabel*> textLines;
  QList<QBoxLayout*> layouts;

public: 
  explicit MainWindow(QWidget *parent = nullptr);

  void addButton(QString text);
  void addLayout(int parentId, QBoxLayout::Direction direction);
  void addTextInformation(QString text);
  void addTextLine(QString text);

  QPushButton* getButton(int id);

signals:

public slots:
  void setInformation(QString);
};

#endif // MAINWINDOW_H
