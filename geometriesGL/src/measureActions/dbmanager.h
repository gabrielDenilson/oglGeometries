#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <vector>

using namespace std;

class DbManager
{
private:
    static DbManager *instance_DbManager;

protected:
    DbManager();
    virtual ~DbManager();

    DbManager (DbManager const&);
    DbManager& operator = (DbManager const&);

public:

    static DbManager *getInstance();

    bool isOpen() const;

    /*
     * Define operations
     * -add new person
     * -remove person
     * -check if person esixt in database
     * -print all persons
     * -delete all persons
    */

    static bool addPerson(const QString& name);
    static bool removePerson(const QString& name);
    static void printAllPersons();
    static QString getPersonName(int id);
    static bool personExist(const QString& name);
    static bool removeAllPersons();
    static bool createTable();

    static int getRows(QString tableName);
    static int getColumns(QString tableName);

    static vector<QStringList> getAllData(QString tableName);

    static QStringList getColumnNames(QString tableName);
    static QStringList getFirstRow(QString tableName);


    //ADD NEW CLIENT FORM FUNCTIONS
    static int getLastIdClient(QString tableName);
    static void addClient(QStringList data);

    // ADD NEW PEDIDO FORM FUNCTIONS
    static QStringList getPedidoData(QString tableName, int idCliente);
    static int getNumeroPedidos(QString tableName, int idCliente);
    static std::vector<QStringList> getPedidoData(int idCliente);

private:
    QSqlDatabase mi_dataBase;

};


#endif // DBMANAGER_H
