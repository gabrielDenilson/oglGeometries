#ifndef FORM_NEW_DESIGN_FILE_H
#define FORM_NEW_DESIGN_FILE_H

#include <QWidget>

namespace Ui {
class Form_New_Design_File;
}

class Form_New_Design_File : public QWidget
{
    Q_OBJECT

public:
    explicit Form_New_Design_File(QWidget *parent = nullptr);
    ~Form_New_Design_File();

public slots:
    
    void addRow();
    void lessRow();
    

private:
    Ui::Form_New_Design_File *ui;
    int num_rows;

    // Name of the table
    QString table_name;
    QString table_id;
    // properties of new design file
    QString table_description;
    
    // properties of new columns in design file
    std::vector<QString> column_measures;

};

#endif // FORM_NEW_DESIGN_FILE_H
