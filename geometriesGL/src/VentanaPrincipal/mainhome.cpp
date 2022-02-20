#include "mainhome.h"
#include "ui_mainhome.h"

#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QDir>
#include <QAction>

#include "geometriesGL/src/VentanaPrincipal/interface_modulos.h"

MainHome::MainHome(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainHome)
    , parent(parent)
{
    ui->setupUi(this);

    // remove border
    this->setWindowFlags(Qt::FramelessWindowHint);

    //    QString path = QDir().absoluteFilePath("C:/Users/GabrielSinn/OneDrive/Documento/QML_all/repositorios/VentanaPrincipal/themes/py_dracula_dark.qss");

    qDebug() << "Coneccion a base de datos /n";
    // crear objeto ip_dadatabe

    iP_interface = QSharedPointer<DbManager_interface>(new DbManager_interface());



    //    QFile file(path);
        QFile file("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/repositorios/oglGeometries/geometriesGL/src/VentanaPrincipal/themes/py_dracula_dark.qss");

    //    interface_modulos func;
        interface_modulos::theme(this, file, true);
        interface_modulos::set_theme(this);

        widget = ui;

        //set the current home
        setCurrentHome();

    //    interface_modulos function;

        connect(ui->closeAppBtn, SIGNAL(clicked() ), this, SLOT(close()));
        connect(ui->maximizeRestoreAppBtn, SIGNAL(clicked() ), this, SLOT(showMaximized()));
        connect(ui->minimizeAppBtn, SIGNAL(clicked() ), this, SLOT(showMinimized()));


        connect(ui->btn_home,    SIGNAL(clicked() ), this, SLOT(setCurrentHome()));
        connect(ui->btn_widgets, SIGNAL(clicked() ), this, SLOT(setCurrentHome2()));
        connect(ui->btn_new,     SIGNAL(clicked() ), this, SLOT(setCurrentHome3()));
        connect(ui->btn_pedidos, SIGNAL(clicked() ), this, SLOT(setCurrentHome4()));


        connect(ui->toggleButton, SIGNAL(clicked()), this, SLOT(slotMenuToggle()));
        connect(ui->toggleLeftBox, SIGNAL(clicked()), this, SLOT(slotLeftBoxToggle()));
        connect(ui->settingsTopBtn, SIGNAL(clicked()), this, SLOT(slotRightBoxToggle()));

        //connect button ui->btn_addClient to slot showFormAddClient
        connect(ui->btn_addClient, SIGNAL(clicked()), this, SLOT(showFormAddClient()));

    //    connect(ui->pushButtonStartDrawing, SIGNAL(clicked()), this, SLOT(slotRightBoxToggle()));

        animation = new QPropertyAnimation(widget->home, "geometry");

         ////////////////////////////    2   contructor of page ///////////////////////////





        ////////////////////////////    4   contructor of page ///////////////////////////

        // Adjust TableWidget to provide context menu
        ui->tableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        // Create action "Mostrar Pedidos" to context menu
        action_showPedidos = new QAction("Mostrar Pedidos");
        // Create action "Eliminar Cliente" to context menu
        action_deleteClient = new QAction("Eliminar Cliente");

        // Connect action to slotts "doSomething"
        connect(action_showPedidos, SIGNAL(triggered()), this, SLOT(slot_EmmitPedidos()));
        connect(action_deleteClient, SIGNAL(triggered()), this, SLOT(slot_EmmitRegistro()));

        ui->tableWidget->addAction(action_deleteClient);

        // Add actions
        ui->tableWidget->addAction(action_showPedidos);

        // modify the table widget
        iP_interface->showAllData(ui->tableWidget);
}

MainHome::~MainHome()
{
    delete ui;
}



void MainHome::mousePressEvent(QMouseEvent *event)
{
    this->eventoMouse = event;
}

void MainHome::slotMenuToggle()
{
    interface_modulos::toggleMenu(this, true);
}

void MainHome::slotLeftBoxToggle()
{
    interface_modulos::toggleLeftBox(this, true);
}

void MainHome::slotRightBoxToggle()
{
    interface_modulos::toggleRightBox(this, true);
}

void MainHome::setCurrentHome()
{
    ui->stackedWidget->setCurrentWidget(this->ui->home);
    interface_modulos::resetStyle(this, ui->btn_home);
    ui->btn_home->setStyleSheet(interface_modulos::selectMenu(ui->btn_home->styleSheet()));
}

void MainHome::setCurrentHome2()
{
    // create form viewwidget_design
   iP_form_viewwidget_design = new Form_ViewWidget_Design(this);
    // add form viewwidget_design to widget design
    ui->stackedWidget->addWidget(iP_form_viewwidget_design);

    ui->stackedWidget->setCurrentWidget(iP_form_viewwidget_design);
    interface_modulos::resetStyle(this, ui->btn_widgets);
    ui->btn_widgets->setStyleSheet(interface_modulos::selectMenu(ui->btn_widgets->styleSheet()));
}

void MainHome::setCurrentHome3()
{
    ui->stackedWidget->setCurrentWidget(this->ui->new_page);
    interface_modulos::resetStyle(this, ui->btn_new);
    ui->btn_new->setStyleSheet(interface_modulos::selectMenu(ui->btn_new->styleSheet()));
}

void MainHome::setCurrentHome4()
{
    ui->stackedWidget->setCurrentWidget(this->ui->widgets);
    //StyleSheets para widgets
    ui->pushButton_buscar->setStyleSheet("QPushButton {background-color: violet;border-width: 2px;border-radius: 15px;border-color: violet;padding: 4px;} QPushButton:hover {background-color: rgb(57, 65, 80);border: 2px solid rgb(61, 70, 86);} QPushButton:pressed {background-color: rgb(35, 40, 49);border: 2px solid rgb(43, 50, 61);}");
    interface_modulos::resetStyle(this, ui->btn_pedidos);
    ui->btn_pedidos->setStyleSheet(interface_modulos::selectMenu(ui->btn_pedidos->styleSheet()));


    ////////////////////////////    4   contructor of page ///////////////////////////

}




void MainHome::showFormAddClient()
{
    // UI to add a client to DB
    iP_form_addClient = new Form_addClient();
    //set theme of form
    QFile file("../src/VentanaPrincipal/themes/widgets_dracula.qss");

    interface_modulos::set_themeWidget(iP_form_addClient, file);

    //iP_form_addClient->show();
    iP_form_addClient->show();
}

void MainHome::setCurrentPedidosClient()
{
    //get the selected row
    int row = ui->tableWidget->currentRow();

    //get the selected item
    QTableWidgetItem *item = ui->tableWidget->item(row, 0);

    //get the text of the selected item
    QString text = item->text();

    //Print the text
    qDebug() << text;


    // create a new form view pedidos
    iP_form_viewwidget_showpedidos = new Form_ViewWidget_ShowPedidos(this, text);
    QFile file("../src/VentanaPrincipal/themes/widgets_dracula.qss");
    interface_modulos::set_themeWidget(iP_form_viewwidget_showpedidos, file);

    // add ip_form_viewwidget_showpedidos to widgetPage_pedididos
    ui->stackedWidget->addWidget(iP_form_viewwidget_showpedidos);


}

void MainHome::makePush()
{
    qDebug() << "se presiono el boton ese";

}

void MainHome::closedDrawing()
{
    this->show();
}

void MainHome::slot_EmmitPedidos()
{
    //Print "Pedidos is pressed"
    qDebug() << "Pedidos is pressed";

    //set the current widget to widgetPage_pedididos
    setCurrentPedidosClient();
    ui->stackedWidget->setCurrentWidget(iP_form_viewwidget_showpedidos);

}

void MainHome::slot_EmmitRegistro()
{
    //Print "Eliminar is pressed"
    qDebug() << "Eliminar is pressed";
}

void MainHome::slot_printItem(QTableWidgetItem *item)
{
    //Print the item text
    qDebug() << item->text();


}

void MainHome::on_pushButtonStartDrawing_clicked()
{
}
