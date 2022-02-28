#include "form_viewinfo_design.h"
#include "ui_form_viewinfo_design.h"

Form_ViewInfo_Design::Form_ViewInfo_Design(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ViewInfo_Design)
{
    ui->setupUi(this);
}

Form_ViewInfo_Design::Form_ViewInfo_Design(QWidget *parent, QString nombre) :
    QWidget(parent),
    ui(new Ui::Form_ViewInfo_Design),
    nombre(nombre)
{
    ui->setupUi(this);


}

Form_ViewInfo_Design::~Form_ViewInfo_Design()
{
    delete ui;
}

void Form_ViewInfo_Design::setNameOfLabels(QStringList valuesOfTable, QString nameTable)
{

}

void Form_ViewInfo_Design::addValuesToGridLayout(QStringList valuesOfTable)
{

}
