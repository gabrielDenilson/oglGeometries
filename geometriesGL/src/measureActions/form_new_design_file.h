#ifndef FORM_NEW_DESIGN_FILE_H
#define FORM_NEW_DESIGN_FILE_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class Form_New_Design_File;
}

class Form_New_Design_File : public QWidget
{
    Q_OBJECT

public:
    explicit Form_New_Design_File(QWidget *parent = nullptr);
    ~Form_New_Design_File();

    // function to store all rows of tableWidget_columnsDiseno
    QStringList storeRows();

public slots:
    
    void addRow();
    void lessRow();
    void slot_receiveSaveDiseno();

signals:

    void signal_AceptarForm(QStringList lista_rows);
    

private:
    Ui::Form_New_Design_File *ui;
    int num_rows;

    // Name of the table
    QString table_name;
    // properties of new columns in design file
    QStringList rows_measure;

};

#endif // FORM_NEW_DESIGN_FILE_H
