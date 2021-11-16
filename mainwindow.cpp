#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QObject>

#include "widgettrazado.h"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->openGLWidget->setWi
    this->setContentsMargins(0, 0, 0, 0);

    QObject::connect(ui->buttonLinea, SIGNAL (released()),
                     ui->openGLWidget, SLOT (nuevaLinea()));

    //widgetTrazado *myWidget = new widgetTrazado();
    //ui->lienzo->addWidget(myWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}

