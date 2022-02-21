#ifndef FORM_VIEWWIDGET_DESIGN_H
#define FORM_VIEWWIDGET_DESIGN_H

#include <QWidget>

#include "form_itemdesign.h"
#include "form_new_design_file.h"

namespace Ui {
class Form_ViewWidget_Design;
}

class Form_ViewWidget_Design : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ViewWidget_Design(QWidget *parent = nullptr);
    ~Form_ViewWidget_Design();

public slots:
    void show_Form_AgregarDiseno();    

private:
    Ui::Form_ViewWidget_Design *ui;
    Form_New_Design_File *form_new_design_file;

    std::vector<Form_ItemDesign*> form_itemdesigns;
};

#endif // FORM_VIEWWIDGET_DESIGN_H
