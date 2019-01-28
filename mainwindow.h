#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QtWidgets>
#include "earth.h"

class Mainwindow : public QObject
{
  Q_OBJECT
private:
  QLabel lbl;

public:
  explicit Mainwindow(QObject *parent = nullptr);

signals:

public slots:
  void set(QString);
};

#endif // MAINWINDOW_H
