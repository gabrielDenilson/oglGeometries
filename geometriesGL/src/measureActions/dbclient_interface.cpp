#include "dbclient_interface.h"

DbClient_interface::DbClient_interface()
{
    p_DbManager = DbManager::getInstance();
}

DbClient_interface::~DbClient_interface()
{

}

void DbClient_interface::addForm_ShowNewIdClient(QLineEdit *lineEdit)
{
    //Make lineEdit read only
    lineEdit->setReadOnly(true);

    //Get last id from db
    int lastId = p_DbManager->getLastIdClient("ClientR");

    //Set new id on lineEdit
    lineEdit->setText(QString::number(lastId + 1));
}

void DbClient_interface::addForm_ShowDate(QDateTimeEdit *DateTime)
{
    //Set current date on lineEdit
    DateTime->setDateTime(QDateTime::currentDateTime());

    //Make lineEdit read only
    DateTime->setReadOnly(false);

    //Set format
    DateTime->setDisplayFormat("dd/MM/yyyy hh:mm:ss");

}

void DbClient_interface::addClient(QStringList data)
{
    p_DbManager->addClient(data);
}
