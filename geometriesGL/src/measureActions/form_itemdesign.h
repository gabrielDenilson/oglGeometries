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
    explicit Form_ItemDesign(QWidget *parent = nullptr);
    ~Form_ItemDesign();

    //reimplemented double click event
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

public:
    QString tableName;

private:
    Ui::Form_ItemDesign *ui;
};

#endif // FORM_ITEMDESIGN_H
