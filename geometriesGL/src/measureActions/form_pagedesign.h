#ifndef FORM_PAGEDESIGN_H
#define FORM_PAGEDESIGN_H

#include <QWidget>

namespace Ui {
class Form_PageDesign;
}

class Form_PageDesign : public QWidget
{
    Q_OBJECT

public:
    explicit Form_PageDesign(QWidget *parent = nullptr);
    ~Form_PageDesign();

private:
    Ui::Form_PageDesign *ui;
};

#endif // FORM_PAGEDESIGN_H
