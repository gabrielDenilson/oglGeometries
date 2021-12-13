#ifndef MEASUREWIDGET_H
#define MEASUREWIDGET_H

#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

class MeasureWidget
{
public:
    MeasureWidget(QWidget *parent);

    void setLayoutMeasures();
    QVBoxLayout *getMeasueWiget();

    ~MeasureWidget();

private:
    QWidget *parent;

    QVBoxLayout *layout_measures;
    QLineEdit *inputMeasure;
    QLineEdit *inputNameMeasure;
};

#endif // MEASUREWIDGET_H
