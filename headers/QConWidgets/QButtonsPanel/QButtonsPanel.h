#pragma once

#include <QtWidgets>

enum class QButton : quint8
{
    Save = 0, Load, ExitToMenu, Exit, Building,
    Destroy, Science, Events, PowerStation, Mine,
    Farm, Laboratory, CleaningStation, Stock, Cancel,
    NewGame, Continue, Settings
};

class QButtonsPanel : public QGroupBox
{
    Q_OBJECT
public:
    explicit QButtonsPanel(QGroupBox *parent = nullptr);
    ~QButtonsPanel();

    void addButton(QButton button, int row, int column, QString text);

    inline QPushButton* getButton(QButton button) { return buttons[button]; }

    void setAlignmentContent(QFlags<Qt::AlignmentFlag> align);

private:
    QGridLayout *layout = new QGridLayout();
    QMap<QButton, QPushButton*> buttons;
};
