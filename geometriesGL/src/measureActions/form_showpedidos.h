#ifndef FORM_SHOWPEDIDOS_H
#define FORM_SHOWPEDIDOS_H

#include <QWidget>

namespace Ui {
class Form_ShowPedidos;
}

class Form_ShowPedidos : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ShowPedidos(QWidget *parent = nullptr);
    //Constructor with parameters
    Form_ShowPedidos(QWidget *parent,
                        QString id_pedido,
                        QString fecha_creacion_pedido,
                        QString fecha_verificacion_pedido,
                        QString fecha_conclucion_pedido,
                        QString tipo_pedido,
                        QString observaciones_pedido,
                        QString costo_total_pedido,
                        QString saldo_pedido,
                        QString deuda_pedido,
                        QString estado_pedido,
                        QString id_cliente);

    //Constructor with a list of parameters
    Form_ShowPedidos(QWidget *parent, QStringList list);

    ~Form_ShowPedidos();

    void setPeididoEditable(bool editable);
    bool getPedidoEditable();

    void habilitarCampos(bool habilitar);

    //Function to get all the data of the form
    QStringList getData();
    //Function to set all the data of the form
    void setData(QStringList list);
  
  
  
    /////////////// getters and setters of Pedido places //////////////////
     QString getPedidoId();
    void setPedidoId(QString id);

    QString getFechaCreacionPedido();
    void setFechaCreacionPedido(QString fecha);

    QString getFechaVerificacionPedido();
    void setFechaVerificacionPedido(QString fecha);

    QString getFechaConclucionPedido();
    void setFechaConclucionPedido(QString fecha);

    QString getTipoPedido();
    void setTipoPedido(QString tipo);

    QString getObservacionesPedido();
    void setObservacionesPedido(QString observaciones);

    QString getPrecioTotalPedido();
    void setPrecioTotalPedido(QString precio);

    QString getSaldoPedido();
    void setSaldoPedido(QString saldo);

    QString getDeudaPedido();
    void setDeudaPedido(QString deuda);

    QString getEstadoPedido();
    void setEstadoPedido(QString estado);

    // getters and setters of client places
    QString getClientIdFromWidget();
    void setClientIdFromWidget(QString id);

private:
    Ui::Form_ShowPedidos *ui;

    bool editable;

//PEDIDO places
    QString id_pedido;
    QString fecha_creacion_pedido;
    QString fecha_verificacion_pedido;    
    QString fecha_conclucion_pedido;
    QString tipo_pedido;
    QString observaciones_pedido;
    QString costo_total_pedido;
    QString saldo_pedido;
    QString deuda_pedido;
    QString estado_pedido;
    
//CLIENTE places    
    QString id_cliente;

public slots:

    //Slot to chacghe the 
    void editPedido();

    void guardarPedido();
    void cancelarPedido();
};

#endif // FORM_SHOWPEDIDOS_H
