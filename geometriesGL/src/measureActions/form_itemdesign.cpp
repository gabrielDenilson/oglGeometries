#include "form_itemdesign.h"
#include "ui_form_itemdesign.h"

#include <QDebug>

Form_ItemDesign::Form_ItemDesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ItemDesign)
{
    ui->setupUi(this);
}

Form_ItemDesign::Form_ItemDesign(QWidget *parent, QString table_name) :
    QWidget(parent),
    ui(new Ui::Form_ItemDesign),
    tableName(table_name)
{
    ui->setupUi(this);
    // set the name of the table in the label
    ui->label->setText(tableName);
}

Form_ItemDesign::~Form_ItemDesign()
{
    delete ui;
}

void Form_ItemDesign::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "double click event: " << tableName;
}
