#ifndef FORM_VIEWWIDGET_SHOWPEDIDOS_H
#define FORM_VIEWWIDGET_SHOWPEDIDOS_H

#include <QWidget>
#include <QVBoxLayout>

#include "form_showpedidos.h"
#include "dbpedidos_interface.h"


namespace Ui {
class Form_ViewWidget_ShowPedidos;
}

class Form_ViewWidget_ShowPedidos : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ViewWidget_ShowPedidos(QWidget *parent = nullptr);
    Form_ViewWidget_ShowPedidos(QWidget *parent = nullptr, QString idCliente = "");

    ~Form_ViewWidget_ShowPedidos();

    // Function to set the pedidos of the client
    std::vector<QStringList> getPedidosOfClientData(int idClient);

    void add_PedidosForms(QString idCliente);

private:
    Ui::Form_ViewWidget_ShowPedidos *ui;
    // interface for database
    QSharedPointer<DbPedidos_interface> iP_Pedidosinterface;

    // vector of widget form_showpedidos
    std::vector<Form_ShowPedidos*> form_showpedidos;

    QString id_cliente;

    QWidget *containerWidget;
    QVBoxLayout *containerLayout;
    
};

#endif // FORM_VIEWWIDGET_SHOWPEDIDOS_H
