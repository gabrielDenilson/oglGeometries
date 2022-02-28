#ifndef FORM_VIEWWIDGET_DESIGN_H
#define FORM_VIEWWIDGET_DESIGN_H

#include <QWidget>
#include <QGridLayout>

#include "form_itemdesign.h"
#include "form_new_design_file.h"

#include "dbdesign_interface.h"

namespace Ui {
class Form_ViewWidget_Design;
}

class Form_ViewWidget_Design : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ViewWidget_Design(QWidget *parent = nullptr);
    ~Form_ViewWidget_Design();

    // function to show form_new_design_file
    void show_TablesInItemDesign();

    QString query_create_table(QStringList lista_rows);

    void remove(QLayout *layout);

public slots:
    void show_Form_AgregarDiseno();
    void slot_receiveSaveDiseno(QStringList);
    void show_Form_UpdateDiseno();

private:
    Ui::Form_ViewWidget_Design *ui;
    QGridLayout *gridLayout;

    Form_New_Design_File *form_new_design_file;

    std::vector<Form_ItemDesign*> form_itemdesigns;
    QSharedPointer<DbDesign_interface> dbdesign_interface;
};

#endif // FORM_VIEWWIDGET_DESIGN_H
