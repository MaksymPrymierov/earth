#ifndef TEXTPANEL_H
#define TEXTPANEL_H

#include <QtWidgets>

enum class QInfo : quint8
{
    Year = 0, Population, Energy, Minerals, Food,
    Science, Pollution, Solidarity
};

class QTextPanel : public QWidget
{
    Q_OBJECT
public:
    explicit QTextPanel(QWidget *parent = nullptr);
    ~QTextPanel();

    void addInfo(QInfo type, int row, int column, QString info);
    void updateInfo(QInfo type, QString info);

    inline QLabel* getLabel(QInfo type) { return labels[type]; }

private:
    QGridLayout *layout = new QGridLayout();
    QMap<QInfo, QLabel*> labels;
};

#endif // TEXTPANEL_H
