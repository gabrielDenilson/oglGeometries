#ifndef DBCLIENT_INTERFACE_H
#define DBCLIENT_INTERFACE_H

#include <QLineEdit>
#include <QDateTimeEdit>

#include "dbmanager.h"

class DbClient_interface
{
public:
    DbClient_interface();
    ~DbClient_interface();

    void addForm_ShowNewIdClient(QLineEdit *lineEdit);

    void addForm_ShowDate(QDateTimeEdit *DateTime);

    void addClient(QStringList data);


private:

    DbManager *p_DbManager;

};

#endif // DBCLIENT_INTERFACE_H
