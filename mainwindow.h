#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

class mainwindow : public QObject
{
  Q_OBJECT
public:
  explicit mainwindow(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MAINWINDOW_H