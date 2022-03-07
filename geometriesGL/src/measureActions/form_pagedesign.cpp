#include "form_pagedesign.h"
#include "ui_form_pagedesign.h"

Form_PageDesign::Form_PageDesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_PageDesign)
{
    ui->setupUi(this);
}

Form_PageDesign::~Form_PageDesign()
{
    delete ui;
}
