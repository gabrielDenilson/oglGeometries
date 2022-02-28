#ifndef DBDESIGN_INTERFACE_H
#define DBDESIGN_INTERFACE_H

#include "dbmanager.h"

#include <QStringList>

class DbDesign_interface
{
public:
    DbDesign_interface();
    virtual ~DbDesign_interface();

    QStringList getTables();

    // Funciotn to create a new table
     void createTable(QString query_create_table);

private:
    DbManager *p_dbManager;
};

#endif // DBDESIGN_INTERFACE_H
