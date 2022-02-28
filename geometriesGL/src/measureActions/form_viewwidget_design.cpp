#include "form_viewwidget_design.h"
#include "ui_form_viewwidget_design.h"

#include <QDebug>

Form_ViewWidget_Design::Form_ViewWidget_Design(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_ViewWidget_Design)
{
    ui->setupUi(this);

    // set grid layout to scrollAreaWidgetContents
    gridLayout = new QGridLayout(this->ui->scrollAreaWidgetContents);


    // create dbdesign_interface
    dbdesign_interface = QSharedPointer<DbDesign_interface>(new DbDesign_interface());

    show_TablesInItemDesign();

    // connect pushButton_agregarDiseno to slot show_Form_AgregarDiseno
    connect(ui->pushButton_agregarDiseno, SIGNAL(clicked()), this, SLOT(show_Form_AgregarDiseno()));

    // connect pushButton_update to slot show_Form_UpdateDiseno
    connect(ui->pushButton_update, SIGNAL(clicked()), this, SLOT(show_Form_UpdateDiseno()));


}

Form_ViewWidget_Design::~Form_ViewWidget_Design()
{
    delete ui;
}

void Form_ViewWidget_Design::show_TablesInItemDesign()
{
    qDebug() << gridLayout->count()  << " tamaño grid";


    qDebug() << form_itemdesigns.size()  << " tamaño form Before";
    // if form_itemdesigns is not empty, delete all items
    if (!form_itemdesigns.empty())
    {
        int tamano_form = form_itemdesigns.size();
        for (int i = 0; i < tamano_form; i++)
        {
            form_itemdesigns.pop_back();
        }
    }
    qDebug() << form_itemdesigns.size()  << " tamaño form After";

    // get all tables in dbdesign_interface
    QStringList tables = dbdesign_interface->getTables();

    qDebug() << tables ;

    // create form_itemdesigns with constructor (this, table_name)
    for (int i = 0; i < tables.size(); i++)
    {
        // create form_itemdesigns
        form_itemdesigns.push_back(new Form_ItemDesign(this, tables[i]));
        qDebug() << " se agrego a form " << i ;
    }

    // if gridLayout is not empty, delete all items
    this->remove(gridLayout);

    qDebug() << " layout after " << gridLayout->count();

    // add form_itemdesigns to grid layout only four columns
    for (int i = 0; i < tables.size(); i++)
    {
        if (i % 4 == 0)
        {

            gridLayout->addWidget(form_itemdesigns[i], i / 4, 0, 1, 1);

        }
        else
        {
            gridLayout->addWidget(form_itemdesigns[i], i / 4, i % 4, 1, 1);
        }
    }

    ui->scrollAreaWidgetContents->setLayout(gridLayout);

}

QString Form_ViewWidget_Design::query_create_table(QStringList lista_rows)
{
    // create QString query_create_table to store the query to create the table
    QString query_create_table;

    // store the name of the table on query_create_table
    query_create_table.append("CREATE TABLE " + lista_rows[0] + "(");

    // create column id of table
    query_create_table.append("id INTEGER PRIMARY KEY, ");

    // create foreign key column id_Pedido from table PedidosR and add it to query_create_table
    query_create_table.append("id_Pedido INTEGER, ");

    // create columns from lista_rows
    for (int i = 1; i < lista_rows.size(); i++)
    {
        query_create_table.append(lista_rows[i] + " TEXT, ");
    }

    // define foreign key column id_Pedido from table PedidosR with constraint on delete cascade
    query_create_table.append("FOREIGN KEY (id_Pedido) REFERENCES PedidosR(id) ON UPDATE CASCADE ON DELETE CASCADE);");

    // return query_create_table
    return query_create_table;

}

void Form_ViewWidget_Design::remove(QLayout *layout)
{
    QLayoutItem* child;
        while ( layout->count() != 0 ) {
            child = layout->takeAt ( 0 );
            if ( child->layout() != 0 ) {
                remove ( child->layout() );
            } else if ( child->widget() != 0 ) {
                delete child->widget();
            }

            delete child;
        }

}

void Form_ViewWidget_Design::show_Form_AgregarDiseno()
{
    // create form_new_design_file
    form_new_design_file = new Form_New_Design_File();

    // show form_new_design_file
    form_new_design_file->show();

    // connect form_new_design_file to slot slot_receiveSaveDiseno
    connect(form_new_design_file, SIGNAL(signal_AceptarForm(QStringList)), this, SLOT(slot_receiveSaveDiseno(QStringList)));
}

// function to receive the data from form_new_design_file
void Form_ViewWidget_Design::slot_receiveSaveDiseno(QStringList dataFromForm)
{
    // print list of data from form
    qDebug() << dataFromForm;

    QString query_create_table = this->query_create_table(dataFromForm);

    // print query_create_table
    qDebug() << query_create_table;

    // create a new table in the db
    dbdesign_interface->createTable(query_create_table);
}

void Form_ViewWidget_Design::show_Form_UpdateDiseno()
{
    // show_TablesInItemDesign();
    show_TablesInItemDesign();   
}
