#include "form_showpedidos.h"
#include "ui_form_showpedidos.h"

// by default, the pedido is not editable

Form_ShowPedidos::Form_ShowPedidos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ShowPedidos),
    editable(false),
    id_pedido(""),
    fecha_creacion_pedido(""),
    fecha_verificacion_pedido(""),
    fecha_conclucion_pedido(""),
//    tipo_pedido(""),
    observaciones_pedido("No te pude alcanzar"),
    costo_total_pedido(""),
    saldo_pedido(""),
    deuda_pedido(""),
//    estado_pedido(""),
    id_cliente("")
{
    ui->setupUi(this);


    // set the lineEdit_id_pedido value of id_pedido
    ui->lineEdit_idPedido->setText(id_pedido);
    // set the dateTimeEdit_creacion value of fecha_creacion_pedido
    ui->dateTimeEdit_creacion->setDateTime(QDateTime::fromString(fecha_creacion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the dateTimeEdit_verificacion value of fecha_verificacion_pedido
    ui->dateTimeEdit_verificacion->setDateTime(QDateTime::fromString(fecha_verificacion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the dateTimeEdit_conclucion value of fecha_conclucion_pedido
    ui->dateTimeEdit_conclucion->setDateTime(QDateTime::fromString(fecha_conclucion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the comboBox_tipoPedido value of tipo_pedido
    ui->comboBox_tipoPedido->setCurrentText(tipo_pedido);
    // set the textEdit_observaciones value of observaciones_pedido
    ui->textEdit_observaciones->setText(observaciones_pedido);
    // set the doubleSpinBox_costoTotal value of costo_total_pedido
    ui->doubleSpinBox_costoTotal->setValue(costo_total_pedido.toDouble());
    // set the doubleSpinBox_saldo value of saldo_pedido
    ui->doubleSpinBox_saldo->setValue(saldo_pedido.toDouble());
    // set the doubleSpinBox_deuda value of deuda_pedido
    ui->doubleSpinBox_deuda->setValue(deuda_pedido.toDouble());
    // set the comboBox_estado value of estado_pedido
    ui->comboBox_estado->setCurrentText(estado_pedido);



    // Connect event of pushButton_editarPedido to slot editPedido
    connect(ui->pushButton_editarPedido, SIGNAL(clicked()), this, SLOT(editPedido()));

    // connect event of pushButton_cancelar to slot cancelar
    connect(ui->pushButton_cancelar, SIGNAL(clicked()), this, SLOT(cancelarPedido()));

    // connect event of pushButton_guardarPedido to slot guardarPedido
    connect(ui->pushButton_guardar, SIGNAL(clicked()), this, SLOT(guardarPedido()));

    // hide buttons of guardar and cancelar
    ui->pushButton_guardar->hide();
    ui->pushButton_cancelar->hide();

    habilitarCampos(editable);
}

Form_ShowPedidos::Form_ShowPedidos(QWidget *parent,
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
                        QString id_cliente) :
    QWidget                  (parent),
    ui                       (new Ui::Form_ShowPedidos),
    editable                 (false),
    id_pedido                (id_pedido),
    fecha_creacion_pedido    (fecha_creacion_pedido),
    fecha_verificacion_pedido(fecha_verificacion_pedido),
    fecha_conclucion_pedido  (fecha_conclucion_pedido),
    tipo_pedido              (tipo_pedido),
    observaciones_pedido     (observaciones_pedido),
    costo_total_pedido       (costo_total_pedido),
    saldo_pedido             (saldo_pedido),
    deuda_pedido             (deuda_pedido),
    estado_pedido            (estado_pedido),
    id_cliente               (id_cliente)
{
    ui->setupUi(this);

    // set the lineEdit_id_pedido value of id_pedido
    ui->lineEdit_idPedido->setText(id_pedido);
    // set the dateTimeEdit_creacion value of fecha_creacion_pedido
    ui->dateTimeEdit_creacion->setDateTime(QDateTime::fromString(fecha_creacion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the dateTimeEdit_verificacion value of fecha_verificacion_pedido
    ui->dateTimeEdit_verificacion->setDateTime(QDateTime::fromString(fecha_verificacion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the dateTimeEdit_conclucion value of fecha_conclucion_pedido
    ui->dateTimeEdit_conclucion->setDateTime(QDateTime::fromString(fecha_conclucion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the comboBox_tipoPedido value of tipo_pedido
    ui->comboBox_tipoPedido->setCurrentText(tipo_pedido);
    // set the textEdit_observaciones value of observaciones_pedido
    ui->textEdit_observaciones->setText(observaciones_pedido);
    // set the doubleSpinBox_costoTotal value of costo_total_pedido
    ui->doubleSpinBox_costoTotal->setValue(costo_total_pedido.toDouble());
    // set the doubleSpinBox_saldo value of saldo_pedido
    ui->doubleSpinBox_saldo->setValue(saldo_pedido.toDouble());
    // set the doubleSpinBox_deuda value of deuda_pedido
    ui->doubleSpinBox_deuda->setValue(deuda_pedido.toDouble());
    // set the comboBox_estado value of estado_pedido
    ui->comboBox_estado->setCurrentText(estado_pedido);


    // Connect event of pushButton_editarPedido to slot editPedido
    connect(ui->pushButton_editarPedido, SIGNAL(clicked()), this, SLOT(editPedido()));

    // connect event of pushButton_cancelar to slot cancelar
    connect(ui->pushButton_cancelar, SIGNAL(clicked()), this, SLOT(cancelarPedido()));

    // connect event of pushButton_guardarPedido to slot guardarPedido
    connect(ui->pushButton_guardar, SIGNAL(clicked()), this, SLOT(guardarPedido()));

    // hide buttons of guardar and cancelar
    ui->pushButton_guardar->hide();
    ui->pushButton_cancelar->hide();

    habilitarCampos(editable);
}

Form_ShowPedidos::Form_ShowPedidos(QWidget *parent, QStringList list) :
    QWidget(parent),
    ui(new Ui::Form_ShowPedidos),
    editable(false)
{
    ui->setupUi(this);
    
    id_pedido                 = list.at(0);
    fecha_creacion_pedido     = list.at(1);
    fecha_verificacion_pedido = list.at(2);
    fecha_conclucion_pedido   = list.at(3);
    tipo_pedido               = list.at(4);
    observaciones_pedido      = list.at(5);
    costo_total_pedido        = list.at(6);
    saldo_pedido              = list.at(7);
    deuda_pedido              = list.at(8);
    estado_pedido             = list.at(9);
    id_cliente                = list.at(10);

    // set the lineEdit_id_pedido value of id_pedido
    ui->lineEdit_idPedido->setText(id_pedido);
    // set the dateTimeEdit_creacion value of fecha_creacion_pedido
    ui->dateTimeEdit_creacion->setDateTime(QDateTime::fromString(fecha_creacion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the dateTimeEdit_verificacion value of fecha_verificacion_pedido
    ui->dateTimeEdit_verificacion->setDateTime(QDateTime::fromString(fecha_verificacion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the dateTimeEdit_conclucion value of fecha_conclucion_pedido
    ui->dateTimeEdit_conclucion->setDateTime(QDateTime::fromString(fecha_conclucion_pedido, "yyyy-MM-dd hh:mm:ss"));
    // set the comboBox_tipoPedido value of tipo_pedido
    ui->comboBox_tipoPedido->setCurrentText(tipo_pedido);
    // set the textEdit_observaciones value of observaciones_pedido
    ui->textEdit_observaciones->setText(observaciones_pedido);
    // set the doubleSpinBox_costoTotal value of costo_total_pedido
    ui->doubleSpinBox_costoTotal->setValue(costo_total_pedido.toDouble());
    // set the doubleSpinBox_saldo value of saldo_pedido
    ui->doubleSpinBox_saldo->setValue(saldo_pedido.toDouble());
    // set the doubleSpinBox_deuda value of deuda_pedido
    ui->doubleSpinBox_deuda->setValue(deuda_pedido.toDouble());
    // set the comboBox_estado value of estado_pedido
    ui->comboBox_estado->setCurrentText(estado_pedido);


    // Connect event of pushButton_editarPedido to slot editPedido
    connect(ui->pushButton_editarPedido, SIGNAL(clicked()), this, SLOT(editPedido()));

    // connect event of pushButton_cancelar to slot cancelar
    connect(ui->pushButton_cancelar, SIGNAL(clicked()), this, SLOT(cancelarPedido()));

    // connect event of pushButton_guardarPedido to slot guardarPedido
    connect(ui->pushButton_guardar, SIGNAL(clicked()), this, SLOT(guardarPedido()));

    // hide buttons of guardar and cancelar
    ui->pushButton_guardar->hide();
    ui->pushButton_cancelar->hide();

    habilitarCampos(editable);
}

    


Form_ShowPedidos::~Form_ShowPedidos()
{
    delete ui;
}

void Form_ShowPedidos::setPeididoEditable(bool editable)
{
    this->editable = editable;

    // if the editable is true
}

bool Form_ShowPedidos::getPedidoEditable()
{
    return editable;
} 

void Form_ShowPedidos::habilitarCampos(bool editable)
{
    //
    if(!editable){

        // set the lineEdit_id_pedido read only
        ui->lineEdit_idPedido->setReadOnly(true);
        // set the dateTimeEdit_creacion read only
        ui->dateTimeEdit_creacion->setReadOnly(true);
        // set the dateTimeEdit_verificacion read only
        ui->dateTimeEdit_verificacion->setReadOnly(true);
        // set the dateTimeEdit_conclucion read only
        ui->dateTimeEdit_conclucion->setReadOnly(true);
        // set the comboBox_tipoPedido read only
        ui->comboBox_tipoPedido->setEnabled(false);
        // set the textEdit_observaciones read only
        ui->textEdit_observaciones->setReadOnly(true);
        // set the doubleSpinBox_costoTotal read only
        ui->doubleSpinBox_costoTotal->setReadOnly(true);
        // set the doubleSpinBox_saldo read only
        ui->doubleSpinBox_saldo->setReadOnly(true);
        // set the doubleSpinBox_deuda read only
        ui->doubleSpinBox_deuda->setReadOnly(true);
        // set the comboBox_estado read only
        ui->comboBox_estado->setEnabled(false);


    }else {

        // set the lineEdit_id_pedido writable
        ui->lineEdit_idPedido->setReadOnly(false);
        // set the dateTimeEdit_creacion writable
        ui->dateTimeEdit_creacion->setReadOnly(false);
        // set the dateTimeEdit_verificacion writable
        ui->dateTimeEdit_verificacion->setReadOnly(false);
        // set the dateTimeEdit_conclucion writable
        ui->dateTimeEdit_conclucion->setReadOnly(false);
        // set the comboBox_tipoPedido writable
        ui->comboBox_tipoPedido->setEnabled(true);
        // set the textEdit_observaciones writable
        ui->textEdit_observaciones->setReadOnly(false);
        // set the doubleSpinBox_costoTotal writable
        ui->doubleSpinBox_costoTotal->setReadOnly(false);
        // set the doubleSpinBox_saldo writable
        ui->doubleSpinBox_saldo->setReadOnly(false);
        // set the doubleSpinBox_deuda writable
        ui->doubleSpinBox_deuda->setReadOnly(false);
        // set the comboBox_estado writable
        ui->comboBox_estado->setEnabled(true);

    }
}

QStringList Form_ShowPedidos::getData()
{
    // get all the data of getters of this class
    QStringList list;
    list.append(getPedidoId());
    list.append(getFechaCreacionPedido());
    list.append(getFechaVerificacionPedido());
    list.append(getFechaConclucionPedido());
    list.append(getTipoPedido());
    list.append(getObservacionesPedido());
    list.append(getPrecioTotalPedido());
    list.append(getSaldoPedido());
    list.append(getDeudaPedido());
    list.append(getEstadoPedido());
    list.append(getClientIdFromWidget());
    return list;
}  

// getters and setters of Pedido places
QString Form_ShowPedidos::getPedidoId()
{
    // get the id of the pedido
    id_pedido = ui->lineEdit_idPedido->text();

    return id_pedido;
}

void Form_ShowPedidos::setPedidoId(QString id)
{
    this->id_pedido = id;

    // update the line edit
    ui->lineEdit_idPedido->setText(id_pedido);
}

QString Form_ShowPedidos::getFechaCreacionPedido()
{
    // get the dateTimeEdit_creacion of the pedido
    fecha_creacion_pedido = ui->dateTimeEdit_creacion->dateTime().toString("yyyy-MM-dd hh:mm:ss");

    return fecha_creacion_pedido;
}

void Form_ShowPedidos::setFechaCreacionPedido(QString fecha)
{
    this->fecha_creacion_pedido = fecha;

    // update the dateTimeEdit_creacion
    ui->dateTimeEdit_creacion->setDateTime(QDateTime::fromString(fecha_creacion_pedido, "yyyy-MM-dd hh:mm:ss"));
}

QString Form_ShowPedidos::getFechaVerificacionPedido()
{
    // get the dateTimeEdit_verificacion of the pedido
    fecha_verificacion_pedido = ui->dateTimeEdit_verificacion->dateTime().toString("yyyy-MM-dd hh:mm:ss");

    return fecha_verificacion_pedido;
}

void Form_ShowPedidos::setFechaVerificacionPedido(QString fecha)
{
    this->fecha_verificacion_pedido = fecha;

    // update the dateTimeEdit_verificacion
    ui->dateTimeEdit_verificacion->setDateTime(QDateTime::fromString(fecha_verificacion_pedido, "yyyy-MM-dd hh:mm:ss"));
}

QString Form_ShowPedidos::getFechaConclucionPedido()
{
    // get the dateTimeEdit_conclucion of the pedido
    fecha_conclucion_pedido = ui->dateTimeEdit_conclucion->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    return fecha_conclucion_pedido;
}

void Form_ShowPedidos::setFechaConclucionPedido(QString fecha)
{
    this->fecha_conclucion_pedido = fecha;
    // update the dateTimeEdit_conclucion
    ui->dateTimeEdit_conclucion->setDateTime(QDateTime::fromString(fecha_conclucion_pedido, "yyyy-MM-dd hh:mm:ss"));
}

QString Form_ShowPedidos::getTipoPedido()
{
    // get the tipo of comboBox_tipoPedido the pedido
    tipo_pedido = ui->comboBox_tipoPedido->currentText();

    return tipo_pedido;
}

void Form_ShowPedidos::setTipoPedido(QString tipo)
{
    this->tipo_pedido = tipo;
    // update the comboBox_tipoPedido
    ui->comboBox_tipoPedido->setCurrentText(tipo_pedido);
}

QString Form_ShowPedidos::getObservacionesPedido()
{
    // get the observaciones textEdit_observaciones of the pedido
    observaciones_pedido = ui->textEdit_observaciones->toPlainText();

    return observaciones_pedido;
}

void Form_ShowPedidos::setObservacionesPedido(QString observaciones)
{
    this->observaciones_pedido = observaciones;
    // update the textEdit_observaciones
    ui->textEdit_observaciones->setText(observaciones_pedido);
}

QString Form_ShowPedidos::getPrecioTotalPedido()
{
    // get the precio total of doubleSpinBox_costoTotal the pedido
    costo_total_pedido = ui->doubleSpinBox_costoTotal->value();
    return costo_total_pedido;
}

void Form_ShowPedidos::setPrecioTotalPedido(QString precio)
{
    this->costo_total_pedido = precio;
    // update the doubleSpinBox_costoTotal
    ui->doubleSpinBox_costoTotal->setValue(costo_total_pedido.toDouble());
}

QString Form_ShowPedidos::getSaldoPedido()
{
    // get the saldo of doubleSpinBox_saldo the pedido
    saldo_pedido = ui->doubleSpinBox_saldo->value();
    return saldo_pedido;
}

void Form_ShowPedidos::setSaldoPedido(QString saldo)
{
    this->saldo_pedido = saldo;
    // update the doubleSpinBox_saldo
    ui->doubleSpinBox_saldo->setValue(saldo_pedido.toDouble());
}

QString Form_ShowPedidos::getDeudaPedido()
{
    // get the deuda of doubleSpinBox_deuda the pedido
    deuda_pedido = ui->doubleSpinBox_deuda->value();
    return deuda_pedido;
}

void Form_ShowPedidos::setDeudaPedido(QString deuda)
{
    this->deuda_pedido = deuda;
    // update the doubleSpinBox_deuda
    ui->doubleSpinBox_deuda->setValue(deuda_pedido.toDouble());
}

QString Form_ShowPedidos::getEstadoPedido()
{
    // get the estado of comboBox_estado the pedido
    estado_pedido = ui->comboBox_estado->currentText();
    return estado_pedido;
}

void Form_ShowPedidos::setEstadoPedido(QString estado)
{
    this->estado_pedido = estado;
    // update the comboBox_estado
    ui->comboBox_estado->setCurrentText(estado_pedido);
}

// getters and setters of client places
QString Form_ShowPedidos::getClientIdFromWidget()
{
    return id_cliente;
}

void Form_ShowPedidos::setClientIdFromWidget(QString id)
{
    this->id_cliente = id;
}

void Form_ShowPedidos::editPedido()
{
    setPeididoEditable(true);
    // if editable is true
    if(editable){
        // Keep the buttons unpressed
        ui->pushButton_editarPedido->hide();
        habilitarCampos(editable);
        // show the buttons
        ui->pushButton_guardar->show();
        ui->pushButton_cancelar->show();    
    }
}

void Form_ShowPedidos::guardarPedido()
{
    setPeididoEditable(false);
    // if editable is false
    if(!editable){
        // Keep the buttons unpressed
        ui->pushButton_editarPedido->show();
        habilitarCampos(editable);
        // hide the buttons
        ui->pushButton_guardar->hide();
        ui->pushButton_cancelar->hide();
    }
}

void Form_ShowPedidos::cancelarPedido()
{
    setPeididoEditable(false);
    // if editable is false
    if(!editable){
        // Keep the buttons unpressed
        ui->pushButton_editarPedido->show();
        habilitarCampos(editable);
        // hide the buttons
        ui->pushButton_guardar->hide();
        ui->pushButton_cancelar->hide();
    }
}
