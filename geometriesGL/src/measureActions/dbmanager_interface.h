#ifndef DBMANAGER_INTERFACE_H
#define DBMANAGER_INTERFACE_H

#include <QSharedPointer> // shared pointer para la base de datos   
#include <QTableWidget> // tabla para mostrar datos
#include <QStringList> // lista de strings

#include "dbmanager.h"

using namespace std;

class DbManager_interface
{
public:
    DbManager_interface();
    ~DbManager_interface();

    void showTable(QTableWidget *table); // funcion que modifica la tabla
    void showAllData(QTableWidget *table); // funcion que muestra todos los datos en una tabla

private:

    DbManager *p_DbManager;
    QString path;

};

#endif // DBMANAGER_INTERFACE_H
