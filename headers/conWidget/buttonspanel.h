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
  QBoxLayout *layout;
  QMap<Button, QPushButton*> buttons;
public:
  explicit ButtonsPanel(QBoxLayout::Direction direction, QGroupBox *parent = nullptr);
  void addButton(Button button, QString text);
  QPushButton* getButton(Button button);
  void setAlignmentContent(Qt::AlignmentFlag align);
};

#endif // BOTTONSPANEL_H
