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


    // set grid layout to scrollAreaWidgetContents
    ui->scrollAreaWidgetContents->setLayout(gridLayout);

    // connect pushButton_agregarDiseno to slot show_Form_AgregarDiseno
    connect(ui->pushButton_agregarDiseno, SIGNAL(clicked()), this, SLOT(show_Form_AgregarDiseno()));


}

Form_ViewWidget_Design::~Form_ViewWidget_Design()
{
    delete ui;
}

void Form_ViewWidget_Design::show_Form_AgregarDiseno()
{
    // create form_new_design_file
    form_new_design_file = new Form_New_Design_File();

    // show form_new_design_file
    form_new_design_file->show();
}
