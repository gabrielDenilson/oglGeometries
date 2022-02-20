#include "form_viewwidget_showpedidos.h"
#include "ui_form_viewwidget_showpedidos.h"

#include <QDebug>

Form_ViewWidget_ShowPedidos::Form_ViewWidget_ShowPedidos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ViewWidget_ShowPedidos)
{
    ui->setupUi(this);

    // add seven form_showpedidos to the vector
    form_showpedidos.push_back(new Form_ShowPedidos(this));
    form_showpedidos.push_back(new Form_ShowPedidos(this));
    form_showpedidos.push_back(new Form_ShowPedidos(this));
    form_showpedidos.push_back(new Form_ShowPedidos(this));
    form_showpedidos.push_back(new Form_ShowPedidos(this));
    form_showpedidos.push_back(new Form_ShowPedidos(this));
    form_showpedidos.push_back(new Form_ShowPedidos(this));

    // set vertical alignment of scrollArea_pedidosWidget
    ui->scrollArea_pedidosWidget->setAlignment(Qt::AlignVCenter);

    // create a widget to add to scrollArea_pedidosWidget
    QWidget *widget = new QWidget(ui->scrollArea_pedidosWidget);
    widget->setObjectName(QStringLiteral("widget"));
    // set the layout of widget
    QVBoxLayout *verticalLayout = new QVBoxLayout(widget);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    // add form_showpedidos to the layout
    verticalLayout->addWidget(form_showpedidos[0]);
    verticalLayout->addWidget(form_showpedidos[1]);
    verticalLayout->addWidget(form_showpedidos[2]);
    verticalLayout->addWidget(form_showpedidos[3]);
    verticalLayout->addWidget(form_showpedidos[4]);
    verticalLayout->addWidget(form_showpedidos[5]);
    verticalLayout->addWidget(form_showpedidos[6]);
    // set the layout of widget

    // add border of 30px top and bottom to the verticalLayout
    verticalLayout->setContentsMargins(0, 30, 0, 30);


    widget->setLayout(verticalLayout);
    // set the widget to scrollArea_pedidosWidget
    ui->scrollArea_pedidosWidget->setWidget(widget);


}

Form_ViewWidget_ShowPedidos::Form_ViewWidget_ShowPedidos(QWidget *parent, QString idCliente):
    QWidget(parent),
    ui(new Ui::Form_ViewWidget_ShowPedidos)
{
    ui->setupUi(this);

    // create QSharedPointer ip_Pedidosinterface
    iP_Pedidosinterface = QSharedPointer<DbPedidos_interface>(new DbPedidos_interface());

    // set vertical alignment of scrollArea_pedidosWidget
    ui->scrollArea_pedidosWidget->setAlignment(Qt::AlignVCenter);

    // create a widget to add to scrollArea_pedidosWidget
    containerWidget = new QWidget(ui->scrollArea_pedidosWidget);
    containerWidget->setObjectName(QStringLiteral("containerWidget"));
    // set the layout of widget
    containerLayout = new QVBoxLayout(containerWidget);
    containerLayout->setObjectName(QStringLiteral("containerLayout"));

    // add form_showpedidos to the layout
    add_PedidosForms(idCliente);

    // add border of 30px top and bottom to the verticalLayout
    containerLayout->setContentsMargins(0, 30, 0, 30);

    // set the layout of widget
    containerWidget->setLayout(containerLayout);
    // set the widget to scrollArea_pedidosWidget
    ui->scrollArea_pedidosWidget->setWidget(containerWidget);
}


Form_ViewWidget_ShowPedidos::~Form_ViewWidget_ShowPedidos()
{
    delete ui;
}

std::vector<QStringList> Form_ViewWidget_ShowPedidos::getPedidosOfClientData(int idClient)
{
    // get the data from the database on a vector of QStringList
    std::vector<QStringList> pedidosData = iP_Pedidosinterface->getPedidosOfClient(idClient);

    return pedidosData;
}

void Form_ViewWidget_ShowPedidos::add_PedidosForms(QString idCliente)
{
    // add form_showpedidos to the layout
    int numeroPedidos = iP_Pedidosinterface->getNumeroPedidos("PedidosR", idCliente.toInt());

    // create a vector void of QStringList
    std::vector<QStringList> pedidosData = std::vector<QStringList>();

    // get the data from the database on a vector of QStringList
    pedidosData = iP_Pedidosinterface->getPedidosOfClient(idCliente.toInt());

    qDebug() << numeroPedidos << " pedidos";
    // print pedidosData
    for(int i = 0; i < numeroPedidos; i++)
    {
        QStringList pedidoData = pedidosData[i];
        qDebug() << pedidoData  << " pedidoData";
    }

    // create pedidosForms 
    for(int i = 0; i < numeroPedidos; i++)
    {
        // add form_showpedidos to the vector
        form_showpedidos.push_back(new Form_ShowPedidos(this, pedidosData[i]));

        // print the pedidosData
        qDebug() << pedidosData[i];
    }
    for(int i = 0; i < numeroPedidos; i++)
    {
        // add form_showpedidos to the layout
        containerLayout->addWidget(form_showpedidos[i]);
    }
 
}
