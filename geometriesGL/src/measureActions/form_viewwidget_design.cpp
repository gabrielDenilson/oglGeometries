#include "form_viewwidget_design.h"
#include "ui_form_viewwidget_design.h"

Form_ViewWidget_Design::Form_ViewWidget_Design(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ViewWidget_Design)
{
    ui->setupUi(this);

    // create form_itemdesigns
    form_itemdesigns.push_back(new Form_ItemDesign(this));
    form_itemdesigns.push_back(new Form_ItemDesign(this));
    form_itemdesigns.push_back(new Form_ItemDesign(this));
    form_itemdesigns.push_back(new Form_ItemDesign(this));
    form_itemdesigns.push_back(new Form_ItemDesign(this));
    form_itemdesigns.push_back(new Form_ItemDesign(this));

    // create grid layout
    QGridLayout *gridLayout = new QGridLayout(this->ui->scrollAreaWidgetContents);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));

    // add form_itemdesigns to grid layout only four columns
    for (int i = 0; i < form_itemdesigns.size(); i++)
    {
        if (i % 4 == 0)
        {

            gridLayout->addWidget(form_itemdesigns[i], i / 4, 0, 1, 1);

        }
        else
        {
            gridLayout->addWidget(form_itemdesigns[i], i / 4, i % 4, 1, 1);
        }
    }

//    // add form_itemdesigns to grid layout
//    for (int i = 0; i < form_itemdesigns.size(); ++i)
//    {
//        gridLayout->addWidget(form_itemdesigns[i], i, 0, 1, 1);
//    }

    // set grid layout to scrollAreaWidgetContents
    ui->scrollAreaWidgetContents->setLayout(gridLayout);

}

Form_ViewWidget_Design::~Form_ViewWidget_Design()
{
    delete ui;
}
