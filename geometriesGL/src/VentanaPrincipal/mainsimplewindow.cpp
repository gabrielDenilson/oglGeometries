#include "mainsimplewindow.h"
#include "ui_mainwindow.h"

MainSimpleWindow::MainSimpleWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimpleMainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonListo, SIGNAL(clicked()), this, SLOT(close()));
//    connect(ui->pushButtonListo, SIGNAL(clicked()), this, SLOT(maxi)));


}

MainSimpleWindow::~MainSimpleWindow()
{
    emit close();
    delete ui;
}
