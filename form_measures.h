#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

#include "measurewidget.h"

#ifndef FORM_MEASURES_H
#define FORM_MEASURES_H

namespace Ui {
class Form_measures;
}

class Form_measures : public QWidget
{
    Q_OBJECT

public:
    explicit Form_measures(QWidget *parent = nullptr);
    ~Form_measures();

    //function to change the element of widget
public slots:
    void add_measure();

private:
    Ui::Form_measures *ui;

    std::vector<MeasureWidget> setOfMeasures;

    QHBoxLayout *Principal;
    QPushButton *button;
};

//Class to add measures to the widget

#endif // FORM_MEASURES_H

