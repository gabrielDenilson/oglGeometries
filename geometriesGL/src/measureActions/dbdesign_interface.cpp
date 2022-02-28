#include "dbdesign_interface.h"

DbDesign_interface::DbDesign_interface()
{
    // create the dbManager
    p_dbManager = DbManager::getInstance();
}

DbDesign_interface::~DbDesign_interface()
{

}

QStringList DbDesign_interface::getTables()
{
    // get the tables from the dbManager
    QStringList tables = p_dbManager->getTables();

    // select all tables that begin with "jj_"
    QStringList jjTables;

    for (int i = 0; i < tables.size(); i++)
    {
        if (tables.at(i).startsWith("jj_"))
        {
            jjTables.append(tables.at(i));
        }
    }

    return jjTables;
}

void DbDesign_interface::createTable(QString query_create_table)
{
    // create the table
    p_dbManager->executeQueryInDataBase(query_create_table);
}

