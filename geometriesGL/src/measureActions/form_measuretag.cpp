#include "form_measuretag.h"
#include "ui_form_measuretag.h"

#include <QPainter>
#include <QDebug>

Form_MeasureTag::Form_MeasureTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_MeasureTag)
{
    ui->setupUi(this);
    ui->label_name->setText("Hello world and everyone  lalala lalala ");

    // set label width to size of text
        ui->label_name->setFixedWidth(ui->label_name->sizeHint().width()+10);

    qDebug() << ui->label_name->width();

    //set height of this widget to 30px
    this->setFixedHeight(35);
    // remove window border
        this->setWindowFlags(Qt::FramelessWindowHint);

    // set text of label_name "Hello World"

    setAttribute(Qt::WA_TranslucentBackground);

    // set the width of this widget the size of text of ui->label_name
    this->setFixedWidth(ui->label_name->width()+25);

    //set the height of this widget to label_name height
        this->setFixedHeight(ui->label_name->height()+1);

    qDebug() << this->width() << " - " << this->height();
}

Form_MeasureTag::Form_MeasureTag(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::Form_MeasureTag),
    name(name)
{



    // set name to ui->label_name
    ui->label_name->setText(name);

}

Form_MeasureTag::~Form_MeasureTag()
{
    delete ui;
}

void Form_MeasureTag::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // smooth borders
    painter.setBrush(QBrush(Qt::darkGray)); // visible color of background
    painter.setPen(Qt::transparent); // thin border color

    // Change border radius
    QRect rect = this->rect();
    rect.setWidth(rect.width()-1);
    rect.setHeight(rect.height()-1);
    painter.drawRoundedRect (rect, 15, 15);

    QWidget::paintEvent(event);
}
