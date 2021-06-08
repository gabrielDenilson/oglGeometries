#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgettrazado.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widgetTrazado *myWidget = new widgetTrazado();
    ui->lienzo->addWidget(myWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}

