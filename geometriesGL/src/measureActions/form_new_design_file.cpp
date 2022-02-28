#include "form_new_design_file.h"
#include "ui_form_new_design_file.h"

#include <QDebug>

Form_New_Design_File::Form_New_Design_File(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_New_Design_File),
    num_rows(0)
{
    ui->setupUi(this);

    // connect   pushButton_addRow to slot add row of tableWidget_columnsDiseno
    connect(ui->pushButton_addRow, SIGNAL(clicked()), this, SLOT(addRow()));

    // connect pushButton_lessRow to slot less row of tableWidget_columnsDiseno
    connect(ui->pushButton_lessRow, SIGNAL(clicked()), this, SLOT(lessRow()));

    // deshabilitar pushButton_lessRow
    ui->pushButton_lessRow->setEnabled(false);

    // connect pushButton_crearDiseno to slot slot_receiveSaveDiseno
    connect(ui->pushButton_crearDiseno, SIGNAL(clicked()), this, SLOT(slot_receiveSaveDiseno()));

    // initialize tableWidget_columnsDiseno with 1 column
    ui->tableWidget_columnsDiseno->setColumnCount(1);

}

Form_New_Design_File::~Form_New_Design_File()
{
    delete ui;
}

QStringList Form_New_Design_File::storeRows()
{
    // store all rows of tableWidget_columnsDiseno
    QStringList lista_rows;

    for (int i = 0; i < ui->tableWidget_columnsDiseno->rowCount(); i++)
    {
        lista_rows.push_back(ui->tableWidget_columnsDiseno->item(i, 0)->text());
    }

    return lista_rows;
}


void Form_New_Design_File::addRow()
{

    // add row to tableWidget_columnsDiseno
    // check if exist a row selected
    if(ui->tableWidget_columnsDiseno->currentRow() != -1)
    {
        // add row
        ui->tableWidget_columnsDiseno->insertRow(ui->tableWidget_columnsDiseno->currentRow() + 1);

        // add item to row
//        QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(pow(row, column+1)));
        ui->tableWidget_columnsDiseno->setItem(ui->tableWidget_columnsDiseno->currentRow() + 1, 0, new QTableWidgetItem("no se edita creo"));

        // increase num_rows
        num_rows++;
    }
    else
    {
        // add row
        ui->tableWidget_columnsDiseno->insertRow(num_rows);

        // add editable item to row
        ui->tableWidget_columnsDiseno->setItem(num_rows, 0, new QTableWidgetItem(" No se editta ciertoo"));

        // increase num_rows
        num_rows++;

        // print num_rows
        qDebug() << "num_rows: " << num_rows;
    }

    // enable pushButton_lessRow
    ui->pushButton_lessRow->setEnabled(true);

    // set tableWidget_columnsDiseno to current row
    ui->tableWidget_columnsDiseno->setCurrentCell(ui->tableWidget_columnsDiseno->currentRow(), 0);



}

void Form_New_Design_File::lessRow()
{
    // remove row from tableWidget_columnsDiseno
    // check if num_rows > 0
    if (num_rows > 0)
    {
        //check if exist a row selected
        if (ui->tableWidget_columnsDiseno->currentRow() != -1)
        {
            // remove row
            ui->tableWidget_columnsDiseno->removeRow(ui->tableWidget_columnsDiseno->currentRow());

            // decrease num_rows
            num_rows--;
        }
        // else delete last row
        else
        {
            // remove last row
            ui->tableWidget_columnsDiseno->removeRow(num_rows - 1);

            // decrease num_rows
            num_rows--;
        }

        // check if num_rows == 0
        if (num_rows == 0)
        {
            // disable pushButton_lessRow
            ui->pushButton_lessRow->setEnabled(false);
        }

        // set tableWidget_columnsDiseno to current row
        ui->tableWidget_columnsDiseno->setCurrentCell(ui->tableWidget_columnsDiseno->currentRow(), 0);

    }
}

void Form_New_Design_File::slot_receiveSaveDiseno()
{
    // create a QStringList to save the columns of the design file
    QStringList lista_columnas;

    // get the name of the table
    table_name = ui->lineEdit_nombreDiseno->text();

    // add jj_ at the begining of the table name
    table_name.prepend("jj_");

    lista_columnas.append(table_name);

    // get the list of rows of function storeRows
    QStringList lista_rows = storeRows();

    // add the comboBox_unidadMedida to lista_columnas
    lista_columnas.append(ui->comboBox_unidadMedida->currentText());

    // add the list of rows to the list of columns
    lista_columnas.append(lista_rows);

    // emmit signal_AceptarForm with the name of the table
    emit signal_AceptarForm(lista_columnas);


}
