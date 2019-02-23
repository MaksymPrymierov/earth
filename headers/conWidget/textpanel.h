#ifndef TEXTPANEL_H
#define TEXTPANEL_H

#include <QtWidgets>

enum class Info : quint8 {
  Year = 0, Population, Energy, Minerals, Food,
  Science, Pollution, Solidarity
};

class TextPanel : public QWidget {
  Q_OBJECT
private:
  QGridLayout *layout = new QGridLayout();
  QMap<Info, QLabel*> labels;

public:
  explicit TextPanel(QWidget *parent = nullptr);
  ~TextPanel();

  void addInfo(Info type, int row, int column, QString info);
  void updateInfo(Info type, QString info);

  inline QLabel* getLabel(Info type) { return labels[type]; }
};

#endif // TEXTPANEL_H
