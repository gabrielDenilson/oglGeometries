#include "form_itemdesign.h"
#include "ui_form_itemdesign.h"

#include <QDebug>

Form_ItemDesign::Form_ItemDesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ItemDesign)
{
    ui->setupUi(this);
}

Form_ItemDesign::~Form_ItemDesign()
{
    delete ui;
}

void Form_ItemDesign::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "double click event";
}
