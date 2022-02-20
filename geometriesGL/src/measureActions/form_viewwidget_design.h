#ifndef FORM_VIEWWIDGET_DESIGN_H
#define FORM_VIEWWIDGET_DESIGN_H

#include <QWidget>

#include "form_itemdesign.h"

namespace Ui {
class Form_ViewWidget_Design;
}

class Form_ViewWidget_Design : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ViewWidget_Design(QWidget *parent = nullptr);
    ~Form_ViewWidget_Design();

private:
    Ui::Form_ViewWidget_Design *ui;

    std::vector<Form_ItemDesign*> form_itemdesigns;
};

#endif // FORM_VIEWWIDGET_DESIGN_H
