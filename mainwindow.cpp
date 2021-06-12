#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QObject>

#include "widgettrazado.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonLinea, SIGNAL (released()),
                     ui->openGLWidget, SLOT (nuevaLinea()));

    //widgetTrazado *myWidget = new widgetTrazado();
    //ui->lienzo->addWidget(myWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}

