#include "form_measures.h"
#include "ui_form_measures.h"
#include <QDebug>

Form_measures::Form_measures(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_measures)
{
    ui->setupUi(this);

    //set this widget background transparent
    this->setAttribute(Qt::WA_TranslucentBackground);



    //set size of this equal to 75x50
    this->setFixedSize(95,70);
    //remove title bar
    this->setWindowFlags(Qt::FramelessWindowHint);

    //add inpu text
    QLineEdit *input = new QLineEdit(this);
    //set zise of input to 50x30
    input->setFixedSize(50,30);
    //set input to center
    input->move(0,0);
    //add border black to input
    input->setStyleSheet("border: 1px solid gray; border-radius: 7px;");

    //add inpu text
    QLineEdit *inputNameMeasure = new QLineEdit(this);
    //set zise of input to 50x30
    inputNameMeasure->setFixedSize(50,20);
    //set input to center
    inputNameMeasure->move(0,0);
    //add border black to input
    inputNameMeasure->setStyleSheet("border: 1px solid gray; border-radius: 7px; background-color: lightblue;");

    //create button
    button = new QPushButton(this);
    //set size of button to 15x50
    button->setFixedSize(15,50);
    //set simbol of button to +
    button->setText("+");


    //create horizontal layout Principal
    Principal = new QHBoxLayout;

    //create vertical layout
    QVBoxLayout *vertical = new QVBoxLayout;

    //add inputNameMeasure to vertical layout
    vertical->addWidget(inputNameMeasure);
    //add input to vertical layout
    vertical->addWidget(input);

    //add vertical layout to Principal
    Principal->addLayout(vertical);
    //add button to Principal
    Principal->addWidget(button);

    //set Principal to this
    this->setLayout(Principal);

    //connect button to slot add_measure
    connect(button, SIGNAL(clicked()), this, SLOT(add_measure()));

}

Form_measures::~Form_measures()
{
    delete ui;
}

void Form_measures::add_measure()
{
    //add Measure to Principal layout
    MeasureWidget *myPointer = new MeasureWidget(this);
    Principal->addLayout(myPointer->getMeasueWiget());

    //update button position at end
    //increment size of this to 50 more width
    this->setFixedSize(this->width()+50,this->height());

    qDebug() << height() << " - " << this->width();

    Principal->addWidget(button);
    //add Measure to setOfMeasures
    setOfMeasures.push_back(*myPointer);

    //update this
    this->update();
    
}

