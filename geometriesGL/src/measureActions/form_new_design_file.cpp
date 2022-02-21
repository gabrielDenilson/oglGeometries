#include "form_new_design_file.h"
#include "ui_form_new_design_file.h"

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
}

Form_New_Design_File::~Form_New_Design_File()
{
    delete ui;
}


void Form_New_Design_File::addRow()
{
    // add row to tableWidget_columnsDiseno
    // check if exist a row selected
    if(ui->tableWidget_columnsDiseno->currentRow() != -1)
    {
        // add row
        ui->tableWidget_columnsDiseno->insertRow(ui->tableWidget_columnsDiseno->currentRow() + 1);

        // increase num_rows
        num_rows++;
    }
    else
    {
        // add row
        ui->tableWidget_columnsDiseno->insertRow(num_rows);

        // increase num_rows
        num_rows++;
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
