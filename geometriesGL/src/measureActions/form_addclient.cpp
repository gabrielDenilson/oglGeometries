#include "form_addclient.h"
#include "ui_form_addclient.h"

Form_addClient::Form_addClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_addClient)
{
    ui->setupUi(this);

// remove border
    this->setWindowFlags(Qt::FramelessWindowHint);

    //Connections

    connect(ui->btn_cancelar, SIGNAL(clicked() ), this, SLOT(close()));

}

Form_addClient::~Form_addClient()
{
    delete ui;
}



//private slots:
    void Form_addClient::closeForm()
{
    //Close the form
    this->close();
}
