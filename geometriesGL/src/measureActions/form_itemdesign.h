#ifndef FORM_ITEMDESIGN_H
#define FORM_ITEMDESIGN_H

#include <QWidget>

namespace Ui {
class Form_ItemDesign;
}

class Form_ItemDesign : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ItemDesign(QWidget *parent);
    explicit Form_ItemDesign(QWidget *parent, QString table_name);
    ~Form_ItemDesign();

    //reimplemented double click event
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

private:
    Ui::Form_ItemDesign *ui;

    QString tableName; // name of the table
};

#endif // FORM_ITEMDESIGN_H
