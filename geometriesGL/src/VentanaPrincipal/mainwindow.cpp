#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_main.h"
#include "mainsimplewindow.h"

#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QDir>

#include "interface_modulos.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , parent(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QString path = QDir().absoluteFilePath("C:/Users/GabrielSinn/OneDrive/Documento/QML_all/repositorios/VentanaPrincipal/themes/py_dracula_dark.qss");

//    qDebug() << path;
//    QFile file(path);
    QFile file("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/repositorios/VentanaPrincipal/themes/py_dracula_light.qss");

//    interface_modulos func;
    interface_modulos::theme(this, file, true);
    interface_modulos::set_theme(this);

    widget = ui;

    widget->btn_widgets->clicked(true);

//    interface_modulos function;

    connect(ui->closeAppBtn, SIGNAL(clicked() ), this, SLOT(close()));
    connect(ui->maximizeRestoreAppBtn, SIGNAL(clicked() ), this, SLOT(showMaximized()));
    connect(ui->minimizeAppBtn, SIGNAL(clicked() ), this, SLOT(showMinimized()));

    connect(ui->btn_home, SIGNAL(clicked() ), this, SLOT(setCurrentHome()));
    connect(ui->btn_widgets, SIGNAL(clicked() ), this, SLOT(setCurrentHome2()));
    connect(ui->btn_new, SIGNAL(clicked() ), this, SLOT(setCurrentHome3()));

    connect(ui->toggleButton, SIGNAL(clicked()), this, SLOT(slotMenuToggle()));

    connect(ui->toggleLeftBox, SIGNAL(clicked()), this, SLOT(slotLeftBoxToggle()));

    connect(ui->settingsTopBtn, SIGNAL(clicked()), this, SLOT(slotRightBoxToggle()));

//    connect(ui->pushButtonStartDrawing, SIGNAL(clicked()), this, SLOT(slotRightBoxToggle()));

    animation = new QPropertyAnimation(widget->home, "geometry");
    simpleWindow = new MainSimpleWindow(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    this->eventoMouse = event;
}

void MainWindow::slotMenuToggle()
{
    interface_modulos::toggleMenu(this, true);
}

void MainWindow::slotLeftBoxToggle()
{
    interface_modulos::toggleLeftBox(this, true);
}

void MainWindow::slotRightBoxToggle()
{
    interface_modulos::toggleRightBox(this, true);
}

void MainWindow::setCurrentHome()
{
    ui->stackedWidget->setCurrentWidget(this->ui->home);
    interface_modulos::resetStyle(this, ui->btn_home);
    ui->btn_home->setStyleSheet(interface_modulos::selectMenu(ui->btn_home->styleSheet()));
}

void MainWindow::setCurrentHome2()
{
    ui->stackedWidget->setCurrentWidget(this->ui->widgets);
    interface_modulos::resetStyle(this, ui->btn_widgets);
    ui->btn_widgets->setStyleSheet(interface_modulos::selectMenu(ui->btn_widgets->styleSheet()));
}

void MainWindow::setCurrentHome3()
{
    ui->stackedWidget->setCurrentWidget(this->ui->new_page);
    interface_modulos::resetStyle(this, ui->btn_new);
    ui->btn_new->setStyleSheet(interface_modulos::selectMenu(ui->btn_new->styleSheet()));
}

void MainWindow::makePush()
{
    qDebug() << "se presiono el boton ese";

}

void MainWindow::closedDrawing()
{
    this->show();
}

void MainWindow::on_pushButtonStartDrawing_clicked()
{
    simpleWindow->show();
}
