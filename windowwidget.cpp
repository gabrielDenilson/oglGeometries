#include "windowwidget.h"
#include "ui_windowwidget.h"

#include <QGridLayout>

windowWidget::windowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windowWidget)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout(this);
    //2x2 layout
    QWidget* green = new QWidget(this);
    green->setStyleSheet("background:green;");
    QWidget* yellow = new QWidget(this);
    yellow->setStyleSheet("background:green;");
    QWidget* red = new QWidget(this);
    red->setStyleSheet("background:green;");
    QWidget* blue = new QWidget(this);
    blue->setStyleSheet("background:green;");

    layout->addWidget(green,  0, 0);
    layout->addWidget(yellow, 0, 1);
    layout->addWidget(red,    1, 0);
    layout->addWidget(blue,   1, 1);

    QWidget* mainWidget = new QWidget(this);
    mainWidget->setStyleSheet("background:black;");
    mainWidget->setLayout(layout);

    QHBoxLayout *centralLayout = new QHBoxLayout(this);
    centralLayout->addWidget(mainWidget);
    ui->centralWidget->setLayout(centralLayout);
}

windowWidget::~windowWidget()
{
    delete ui;
}
