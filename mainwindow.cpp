#include "mainwindow.h"

Mainwindow::Mainwindow(QObject *parent) : QObject(parent), lbl("null") {
  lbl.show();
}

void Mainwindow::set(QString) {
 // lbl.setText(QString);
}
