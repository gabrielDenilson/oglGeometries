#ifndef FORM_MEASURETAG_H
#define FORM_MEASURETAG_H

#include <QWidget>

namespace Ui {
class Form_MeasureTag;
}

class Form_MeasureTag : public QWidget
{
    Q_OBJECT

public:
    explicit Form_MeasureTag(QWidget *parent = nullptr);

    // constructor with name
    Form_MeasureTag(QWidget *parent, QString name);

    ~Form_MeasureTag();

    virtual void paintEvent(QPaintEvent* event) override;


private:
    Ui::Form_MeasureTag *ui;
    QString name;
};

#endif // FORM_MEASURETAG_H
