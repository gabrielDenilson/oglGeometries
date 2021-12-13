#include "dialog_createfigures.h"
#include "ui_dialog_createfigures.h"

#include <QLabel>
#include <QLineEdit>

#include <QSpinBox>

#include <QBoxLayout>

#include <QGroupBox>


Dialog_CreateFigures::Dialog_CreateFigures(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CreateFigures)
{

    ui->setupUi(this);

    //create principal layout vertical
    QVBoxLayout *principalLayout = new QVBoxLayout;

    //Create layout horizontal
    QHBoxLayout *layout_title = new QHBoxLayout;

    //Create label with name "Title File"
    QLabel *label_title = new QLabel(this);
    label_title->setText("Nombre de archivo");
    //Create Enter text next to label "Title File"
    QLineEdit *line_title = new QLineEdit(this);
    //Add label and line to layout
    layout_title->addWidget(label_title);
    layout_title->addWidget(line_title);

//create layout horizontal
    QHBoxLayout *layout_Table = new QHBoxLayout;
    //Create table with name "Measures" whit two columns
    table_measures = new QTableWidget(this);
    table_measures->setColumnCount(2);
    table_measures->setRowCount(1);
    table_measures->setHorizontalHeaderLabels(QString("Measure;Value").split(";"));
    //set the size of table
    table_measures->setColumnWidth(0,150);
    table_measures->setColumnWidth(1,150);

    //create spinbox with name "Number of measures"
    QSpinBox *spin_measures = new QSpinBox(this);
    spin_measures->setRange(1,100);
    spin_measures->setValue(1);
    spin_measures->setSingleStep(1);

    QHBoxLayout *layout_dialog = new QHBoxLayout;
    layout_dialog->addWidget(ui->buttonBox);

// add table and spinbox to layout horizontal
    layout_Table->addWidget(table_measures);
    layout_Table->addWidget(spin_measures);
    
    //Create groupbox with name "Measures"
    QGroupBox *group_measures = new QGroupBox(this);
    group_measures->setTitle("Measures");
    group_measures->setLayout(layout_Table);

    //Add layout to principal layout
    principalLayout->addLayout(layout_title);
    principalLayout->addWidget(group_measures);
    principalLayout->addLayout(layout_dialog);

    //Set layout principal to dialog
    this->setLayout(principalLayout);

    
    //set the Rows of table_measures with the spinbox
    table_measures->setRowCount(spin_measures->value());

    //connect the spinbox with the table_measures
    connect(spin_measures,SIGNAL(valueChanged(int)),this,SLOT(insertRowMeasures(int)));


}

Dialog_CreateFigures::~Dialog_CreateFigures()
{
    delete ui;
}


//void Dialog_CreateFigures::on_spinBox_valueChanged(int arg1)
//{
//    table_measures->setRowCount(arg1);
//}

void Dialog_CreateFigures::insertRowMeasures(int arg1)
{
    table_measures->setRowCount(arg1);
}
