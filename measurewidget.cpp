#include "measurewidget.h"

MeasureWidget::MeasureWidget(QWidget *widget) : parent(widget)
{

    setLayoutMeasures();
}

MeasureWidget::~MeasureWidget()
{

}

void MeasureWidget::setLayoutMeasures()
{
    layout_measures = new QVBoxLayout(parent);
    //add inpu text
    inputMeasure = new QLineEdit(parent);
    //set zise of input to 50x30
    inputMeasure->setFixedSize(50,30);
    //set input to center
    inputMeasure->move(0,0);
    //add border black to input
    inputMeasure->setStyleSheet("border: 1px solid gray; border-radius: 7px;");

    //add inpu text
    inputNameMeasure = new QLineEdit(parent);
    //set zise of input to 50x30
    inputNameMeasure->setFixedSize(50,20);
    //set input to center
    inputNameMeasure->move(0,0);
    //add border black to input
    inputNameMeasure->setStyleSheet("border: 1px solid gray; border-radius: 7px; background-color: lightblue;");

    //create vertical layout

//    layout_measures = new QVBoxLayout;
    //add inputNameMeasure to vertical layout
    layout_measures->addWidget(inputNameMeasure);
    //add input to vertical layout
    layout_measures->addWidget(inputMeasure);
}

QVBoxLayout *MeasureWidget::getMeasueWiget()
{

    return layout_measures;
}
