#include "dbmanager_interface.h"

#include <QDebug>

DbManager_interface::DbManager_interface()
{
    p_DbManager = DbManager::getInstance();
}

DbManager_interface::~DbManager_interface()
{

}


// funcion que modifica la tabla
void DbManager_interface::showTable(QTableWidget *table)
{
    //obtener la cantidad de filas de la tabla "ClientR" en la base de datos
//    int rows = mi_dataBasePtr->getRows("ClientR");

    //modificar table para que tenga la cantidad de filas y columnas que corresponden a la tabla "ClientR"
//    table.setColumnCount(columns);
    table->setColumnCount(6);
    table->setRowCount(7);



    //obtener el nomre de las columnas de la tabla "ClientR" en la base de datos
    const QStringList columnNames = p_DbManager->getColumnNames("ClientR");

    //asignar el nombre de las columnas de la tabla "ClientR" en la base de datos a la tabla
    table->setHorizontalHeaderLabels(columnNames);

                //imprimir los nombres de las columnas de la tabla "ClientR" en la base de datos
                for (int i = 0; i < columnNames.size(); i++)
                {
                    qDebug() << columnNames.at(i) << "\n";
                }

    //obtener el primer registro de la tabla "ClientR" en la base de datos
    QStringList firstRow = p_DbManager->getFirstRow("ClientR");

    //asignar el primer registro de la tabla "ClientR" en la base de datos a la tabla
    for(int i = 0; i < firstRow.size(); i++)
    {
        table->setItem(0, i, new QTableWidgetItem(firstRow.at(i)));
    }


}

void DbManager_interface::showAllData(QTableWidget *table)
{
    //obtener la cantidad de filas de la tabla "ClientR" en la base de datos
    int rows = p_DbManager->getRows("ClientR");
    int columns = p_DbManager->getColumns("ClientR");

    //obtener todos los registros de la tabla "ClientR" en la base de datos
    vector<QStringList> allRows = p_DbManager->getAllData("ClientR");

    //modificar table para que tenga la cantidad de filas y columnas que corresponden a la tabla "ClientR"
    table->setColumnCount(columns);
    table->setRowCount(rows);

    //mostrar los datos de la tabla "ClientR" en la base de datos
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            table->setItem(i, j, new QTableWidgetItem(allRows.at(i).at(j)));
        }
    }

    qDebug() << rows << " filas" << "\n";
    qDebug() << columns << " columnas" << "\n";
}
