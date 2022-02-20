#ifndef DBPEDIDOS_INTERFACE_H
#define DBPEDIDOS_INTERFACE_H

#include "dbmanager.h"

class DbPedidos_interface
{
public:
    DbPedidos_interface();
    ~DbPedidos_interface();

    QStringList getAllDataPedidos(QString tableName, int idCliente);
    int getNumeroPedidos(QString tableName, int idCliente);

    // Function to get the data of a pedido
    std::vector<QStringList> getPedidosOfClient(int idClient);

private:
    DbManager *p_DbManager;

};

#endif // DBPEDIDOS_INTERFACE_H
