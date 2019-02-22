#ifndef BOTTONSPANEL_H
#define BOTTONSPANEL_H

#include <QtWidgets>

enum class Button : quint8 {
  Save = 0, Load, ExitToMenu, Exit, Building,
  Destroy, Science, Events, PowerStation, Mine,
  Farm, Laboratory, Cancel, NewGame
};

class ButtonsPanel : public QGroupBox {
  Q_OBJECT
private:
  QGridLayout *layout;
  QMap<Button, QPushButton*> buttons;
  QMap<Button, QLabel*> labels;
public:
  explicit ButtonsPanel(QGroupBox *parent = nullptr);
  void addButton(Button button, int row, int column, QString text);
  void addInfo(Button button, int row, int column, QString info);
  void updateInfo(Button button, QString info);
  QPushButton* getButton(Button button);
  void setAlignmentContent(QFlags<Qt::AlignmentFlag> align);
};

#endif // BOTTONSPANEL_H