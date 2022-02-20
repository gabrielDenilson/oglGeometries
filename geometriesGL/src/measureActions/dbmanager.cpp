#include "dbmanager.h"

#include "QDebug"

DbManager* DbManager::instance_DbManager=NULL;

DbManager::DbManager()
{
    QString path = "C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/repositorios/oglGeometries/geometriesGL/res/clientManager.db";
    mi_dataBase = QSqlDatabase::addDatabase("QSQLITE");
    mi_dataBase.setDatabaseName(path);

    if(!mi_dataBase.open()){
        qDebug() << "Error: coneccion con base de datos fallida";
    } else {
        qDebug() << "Database: coneccion correcta";
    }
}



DbManager::~DbManager()
{
    if(mi_dataBase.isOpen()){
        mi_dataBase.close();
    }
}

DbManager *DbManager::getInstance()
{
    if(instance_DbManager == NULL)
        instance_DbManager = new DbManager();
    else
        qDebug() << "Se obtuvo una instancia ya existente. ";

    return instance_DbManager;
}




bool DbManager::isOpen() const
{
    return mi_dataBase.isOpen();
}

bool DbManager::addPerson(const QString &name)
{
    bool exito = false;

    if(!name.isEmpty()){

        //revisamos si el argumento esta correcto
        QSqlQuery consulta;

        consulta.prepare(    "INSERT INTO gente (name) VALUES (:name)");
        consulta.bindValue(  ":name", name);
        if(consulta.exec()){
            exito = true;
        }
        else {
                qDebug() << "agregar a persona error: "
                     << consulta.lastError();
        }

    }
    else {
        qDebug() << "add person failed: nombre no puede estar vacio ";
    }

    return exito;
}

bool DbManager::removePerson(const QString &name)
{
    bool exito = false;

    if(personExist(name)){

            //revisamos si el argumento esta correcto
            QSqlQuery consulta;

            consulta.prepare(    "DELETE FROM gente WHERE name = :name");
            consulta.bindValue(  ":name", name);
            if(consulta.exec()){
                exito = true;
            }
            else {
                    qDebug() << "remover persona error: "
                        << consulta.lastError();
            }

        }
        else {
            qDebug() << "remove person failed: nombre no existe ";
    }

    return exito;
}



void DbManager::printAllPersons()
{
    QSqlQuery consulta("SELECT * FROM ClientR");
    int idName = consulta.record().indexOf("nombre");

    while(consulta.next()){
        QString name = consulta.value(idName).toString();
        qDebug() << "persona: " << name;
    }
}

QString DbManager::getPersonName(int id) 
{
    QSqlQuery consulta;
    consulta.prepare("SELECT nombre FROM ClientR WHERE id = :id");
    consulta.bindValue(":id", id);

    if(consulta.exec()){
        if(consulta.next()){
            return consulta.value(0).toString();
        }
    }
    else {
        qDebug() << "get person name error: "
             << consulta.lastError();
    }

    return "";
}



bool DbManager::personExist(const QString &name)
{
    bool exists = false;

    QSqlQuery verConsulta;
    verConsulta.prepare("SELECT name FROM gente WHERE name = (:name)");
    verConsulta.bindValue(":name", name);

    if(verConsulta.exec()){
        if(verConsulta.next()){
            exists = true;
        }
    }
    else {
        qDebug() << "personExist error: " << verConsulta.lastError();
    }

    return exists;

}




bool DbManager::removeAllPersons()
{
    bool exito = false;

    QSqlQuery consulta;
    consulta.prepare("DELETE FROM gente");

    if(consulta.exec()){
        exito = true;
    }
    else {
        qDebug() << "removeAllPersons error: " << consulta.lastError();
    }

    return exito;

}

bool DbManager::createTable()
{
    bool exito = false;

    QSqlQuery consulta;
    consulta.prepare("CREATE TABLE people(id INTEGER PRIMARY KEY, name TEXT);");

    if (!consulta.exec())
    {
        qDebug() << "Couldn't create the table 'people': one might already exist.";
        exito = false;
    }

    return exito;
}


//Function to get the number of rows in the table 'tableName' in the database
int DbManager::getRows(QString tableName) 
{
    //Create a query to get the number of rows in the table
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM " + tableName);

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return -1;
    }

    //Get the number of rows in the table
    query.next();
    int rows = query.value(0).toInt();

    return rows;
}

int DbManager::getColumns(QString tableName)
{
    QStringList columnNamesSize;

    //store the column names in a QStringList
    QSqlQuery query;
    query.prepare("PRAGMA table_info(" + tableName + ")");

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return columnNamesSize.size();
    }
    
    //Get the column names
    while(query.next())
    {
        columnNamesSize.append(query.value(1).toString());
    }

    return columnNamesSize.size();

}

vector<QStringList> DbManager::getAllData(QString tableName)
{
    //Create vector of QStringLists to store the data
    vector<QStringList> rowData;

    //Create a query to get the data from the table
    QSqlQuery query;

    //execute the query
    if(!query.exec("SELECT * FROM " + tableName))
    {
        qDebug() << "Error: " << query.lastError();
        return rowData;
    }

    //Add the data to the vector
    while(query.next())
    {
        QStringList row;
        for(int i = 0; i < getColumns(tableName); i++)
        {
            row.push_back(query.value(i).toString());
        }
        rowData.push_back(row);
    }

    return rowData;

    qDebug() << rowData.size() << " rows retrieved.";

}

QStringList DbManager::getColumnNames(QString tableName) 
{
    QStringList columnNames;

    //store the column names in a QStringList
    QSqlQuery query;
    query.prepare("PRAGMA table_info(" + tableName + ")");

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return columnNames;
    }
    
    //Get the column names
    while(query.next())
    {
        columnNames.append(query.value(1).toString());
    }

    return columnNames;
}

QStringList DbManager::getFirstRow(QString tableName) 
{
    QStringList firstRow;
    //Create a query to get the first row in the table
    QSqlQuery query;
    query.prepare("SELECT * FROM " + tableName + " LIMIT 1");

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return QStringList();
    }

    //Get the first row
    query.next();
    for(int i = 0; i < query.record().count(); i++)
    {
        firstRow.append(query.value(i).toString());
    }

    return firstRow;
}

int DbManager::getLastIdClient(QString tableName)
{
    //Create a query to get the last id in the table
    QSqlQuery query;
    query.prepare("SELECT id FROM " + tableName + " ORDER BY id DESC LIMIT 1");

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return -1;
    }

    //Get the last id
    query.next();
    int lastId = query.value(0).toInt();

    return lastId;
}

void DbManager::addClient(QStringList data)
{
    //Get the first QString from the QStringList and convert it to an int
    int id = data.at(0).toInt();

    //get the second QString from the QStringList
    QString date = data.at(1);

    //Get the second QString from the QStringList
    QString name = data.at(2);

    //Get the third QString from the QStringList
    QString lastName = data.at(3);

    //Get the fourth QString from the QStringList
    QString contact = data.at(4);

    //Get the fifth QString from the QStringList
    QString pedidos = data.at(5);

    //Get the sixth QString from the QStringList
    QString tipo = data.at(6);

    //Create a query to insert the data into the table
    QSqlQuery query;
    query.prepare("INSERT INTO ClientR (id, fechaRegistro, nombre, apellido, contacto, design, tipo) VALUES (:id, :date, :name, :lastName, :contact, :pedidos, :tipo)");

    //Bind the values to the query
    query.bindValue(":id", id);
    query.bindValue(":date", date);
    query.bindValue(":name", name);
    query.bindValue(":lastName", lastName);
    query.bindValue(":contact", contact);
    query.bindValue(":pedidos", pedidos);
    query.bindValue(":tipo", tipo);

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
    }

    qDebug() << "Client added.";
    

}

QStringList DbManager::getPedidoData(QString tableName, int idCliente)
{
    //Create a query to get the data from the table PedidosR where the idCliente is equal to the idCliente parameter
    QSqlQuery query;
    query.prepare("SELECT * FROM " + tableName + " WHERE id_Cliente = " + QString::number(idCliente));
    
    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return QStringList();
    }

    //Get the data
    query.next();
    QStringList data;

    for(int i = 0; i < query.record().count(); i++)
    {
        data.append(query.value(i).toString());
    }

    return data;
}



int DbManager::getNumeroPedidos(QString tableName, int idCliente)
{
    // Create a query to get the data from the table PedidosR where the idCliente is equal to the idCliente parameter
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM " + tableName + " WHERE id_cliente = " + QString::number(idCliente));

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return -1;
    }

    //Get the data
    query.next();
    int numeroPedidos = query.value(0).toInt();

    return numeroPedidos;
}



std::vector<QStringList> DbManager::getPedidoData(int idCliente)
{
    //Create a vector to store the data
    vector<QStringList> pedidoData;

    //Create a query to get the data from the table PedidosR where the idCliente is equal to the idCliente parameter
    QSqlQuery query;
    query.prepare("SELECT * FROM PedidosR WHERE id_cliente = " + QString::number(idCliente));

    //Execute the query
    if(!query.exec())
    {
        qDebug() << "Error: " << query.lastError();
        return pedidoData;
    }

    //Get the data
    while(query.next())
    {
        QStringList data;
        for(int i = 0; i < query.record().count(); i++)
        {
            data.append(query.value(i).toString());
        }
        pedidoData.push_back(data);
    }

    return pedidoData;
}



