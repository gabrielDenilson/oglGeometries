#include "form_addclient.h"
#include "ui_form_addclient.h"

#include <QDebug>

Form_addClient::Form_addClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_addClient)
{
    flag_nombre = false;
    flag_apellido = false;
    flag_contacto = false;

    ui->setupUi(this);

    //Create instance of DbClient_interface
    iP_interfaceClient = QSharedPointer<DbClient_interface>(new DbClient_interface());

// remove border
    this->setWindowFlags(Qt::FramelessWindowHint);

    //Connections

    connect(ui->btn_cancelar, SIGNAL(clicked() ), this, SLOT(close()));
    connect(ui->btn_agregar, SIGNAL(clicked() ), this, SLOT(addClient()));

    iP_interfaceClient->addForm_ShowNewIdClient(ui->lineEdit_idClient);
    iP_interfaceClient->addForm_ShowDate(ui->dateTimeEdit_Client);

}

Form_addClient::~Form_addClient()
{
    delete ui;
}


//Function to validate the data of QLineEdit
bool Form_addClient::validateDataIsEmpty(QLineEdit *lineEdit)
{
    //Check if the lineEdit is empty
    if(lineEdit->text().isEmpty())
    {
        //Set the lineEdit to red
        lineEdit->setStyleSheet("background-color: rgb(255, 85, 85);");
        return true;
    }
    else
    {
        //Set the lineEdit to green
        lineEdit->setStyleSheet("background-color:  rgb(80, 250, 123);");
        return false;
    }
}


//Function to validate if QLineEdit is numeric
bool Form_addClient::validateDataIsNumeric(QLineEdit *lineEdit)
{
    //Check if the lineEdit is numeric
    if(lineEdit->text().toInt() == 0)
    {
        //Set the lineEdit to red
        lineEdit->setStyleSheet("background-color: rgb(255, 85, 85);");
        return false;
    }
    else
    {
        //Set the lineEdit to green
        lineEdit->setStyleSheet("background-color: rgb(80, 250, 123);");
        return true;
    }
}

QString Form_addClient::returnFirstCharacterToUpper(QString string)
{
    //ChecK if the first character is not empty
    if(!string.isEmpty())
    {
        //Return the first character to upper
        return string.left(1).toUpper() + string.mid(1);
    }
    else
    {
        return string;
    }

}


//Function to set format of QLineEdit
void Form_addClient::setFormat(QLineEdit *lineEdit)
{
    //check if the lineEdit is numeric
    bool isNumeric = validateDataIsNumeric(lineEdit);
    bool isEmpty = validateDataIsEmpty(lineEdit);

    //if isNumeric is false set the first character to uppercase
    if(isNumeric == false && isEmpty == false)
    {
        lineEdit->setText(returnFirstCharacterToUpper(lineEdit->text()));
    }
}


//Function to set data on a QStringList
QStringList Form_addClient::getDataFromForm()
{
    //Create the order of the data to be inserted in the same order of the database


    //Create a QStringList
    QStringList data;

//id
    //Add data to QStringList
    data.append(ui->lineEdit_idClient->text());

//fechaRegistro

    //Add Date YYYY-MM-DD HH:MM:SS to QStringList
    data.append(ui->dateTimeEdit_Client->dateTime().toString("yyyy-MM-dd hh:mm:ss"));

//nombre

    //check if the lineEdit is empty
    if(validateDataIsEmpty(ui->lineEdit_nombreCliente) == false)
    {
        //set the first character to uppercase
        setFormat(ui->lineEdit_nombreCliente);

        //Add data to QStringList
        data.append(ui->lineEdit_nombreCliente->text());

        //Set flag_nombre to true
        flag_nombre = true;
    }
    else
    {
        //Write on placeHolder could not be empty
        ui->lineEdit_nombreCliente->setPlaceholderText("Nombre Could not be empty!");
        flag_nombre = false;
        
    }

//apellido
    //check if the lineEdit is empty
    if(validateDataIsEmpty(ui->lineEdit_apellidoCliente) == false)
    {
        //set the first character to uppercase
        setFormat(ui->lineEdit_apellidoCliente);

        //Add data to QStringList
        data.append(ui->lineEdit_apellidoCliente->text());

        flag_apellido = true;
    }
    else
    {
        //Write on placeHolder could not be empty
        ui->lineEdit_apellidoCliente->setPlaceholderText("Apellido Could not be empty!");

        //Set flag_apellido to false
        flag_apellido = false;
    }

//contacto
    //check if the lineEdit is empty and numeric
    if(validateDataIsEmpty(ui->lineEdit_ContactoCliente) == false)
    {
        //Add data to QStringList
        data.append(ui->lineEdit_ContactoCliente->text());

        //Set flag_contacto to true
        flag_contacto = true;
    }
    else
    {
        //Write on placeHolder could not be empty
        ui->lineEdit_ContactoCliente->setPlaceholderText("Contacto Could not be empty or numeric!");

        //Set flag_contacto to false
        flag_contacto = false;
    }

//design (number of Pedidos)
    //Add pedido to QStringList equal to 0
    data.append("0");

//tipo (M, H, C)
    //Add tipo to QStringList
    data.append(ui->comboBox_3->currentText());

    //Return the QStringList
    return data;

}


//Function to set data on a DbClient_interface
void Form_addClient::setDataToDb()
{
    //print the data
    QStringList dataToPrint;

    // use getDataFromForm to get the data
    dataToPrint = getDataFromForm();
    //if flag_nombre, flag_apellido, flag_contacto are true add data to DbClient_interface
    if(flag_nombre == true && flag_apellido == true && flag_contacto == true)
    {
        //Add data to DbClient_interface
        iP_interfaceClient->addClient(dataToPrint);
    }


    //print the data to be inserted
    qDebug() << "Data to be inserted: " << dataToPrint;

}



//private slots:
    void Form_addClient::closeForm()
{
    //Close the form
    this->close();
}

void Form_addClient::addClient()
{
    setDataToDb();
}
