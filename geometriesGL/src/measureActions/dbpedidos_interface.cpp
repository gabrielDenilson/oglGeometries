#include "dbpedidos_interface.h"

DbPedidos_interface::DbPedidos_interface()
{
    p_DbManager = DbManager::getInstance();
}

DbPedidos_interface::~DbPedidos_interface()
{

}

QStringList DbPedidos_interface::getAllDataPedidos(QString tableName, int idCliente)
{
    QStringList data;

    data = p_DbManager->getPedidoData(tableName, idCliente);

    return data;
}

int DbPedidos_interface::getNumeroPedidos(QString tableName, int idCliente)
{
    int numeroPedidos;

    numeroPedidos = p_DbManager->getNumeroPedidos(tableName, idCliente);

    return numeroPedidos;
}

std::vector<QStringList> DbPedidos_interface::getPedidosOfClient(int idClient)
{
    std::vector<QStringList> pedidos;

    pedidos = p_DbManager->getPedidoData(idClient);

    return pedidos;
}
