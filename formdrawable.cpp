#include "formdrawable.h"
#include "ui_formdrawable.h"

#include <QDebug>

#include <QLabel>

FormDrawable::FormDrawable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDrawable)
{
    //INICIALIZAMOS EL DISEÑO
    QString styleSheet =" QPushButton {\n    "
                        "color: #555;\n    "
                        "border: 2px solid #555;\n    "
                        "border-radius: 2px;\n    "
                        "border-style: outset;\n    "
                        "background: qradialgradient(\n       "
                        " cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n        "
                        "radius: 1.35, stop: 0 #fff, stop: 1 #222\n"
                        "        );\n    "
                        "padding: 5px;\n    "
                        "}\n"
                        "\n"
                        "QPushButton:hover {\n    "
                        "background: qradialgradient(\n       "
                        " cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n        "
                        "radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n        "
                        ");\n    "
                        "}\n"
                        "\n"
                        "QPushButton:checked {\n    "
                        "border-style: inset;\n    "
                        "background: qradialgradient(\n        "
                        "cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n        "
                        "radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n        "
                        ");\n    "
                        "}";

    // CREATE LAYOUTS AND ADD TO BOXES
       ui->setupUi(this);
       QHBoxLayout *layoutCentral = new QHBoxLayout(this);

       QVBoxLayout *layoutLeft = new QVBoxLayout();

       buttonLinea = new QPushButton("/");  buttonLinea->setStyleSheet(styleSheet);
                                            buttonLinea->setMinimumSize(20, 20);
                                            buttonLinea->setMaximumSize(20, 20);

       buttonLineaPadre = new QPushButton("-");   buttonLineaPadre->setStyleSheet(styleSheet);
                                                  buttonLineaPadre->setMinimumSize(20, 20);
                                                  buttonLineaPadre->setMaximumSize(20, 20);

       buttonLineaHija = new QPushButton("/"); buttonLineaHija->setStyleSheet(styleSheet);
                                                   buttonLineaHija->setMinimumSize(20, 20);
                                                   buttonLineaHija->setMaximumSize(20, 20);

       buttonPunto = new QPushButton(".");  buttonPunto->setStyleSheet(styleSheet);
                                               buttonLineaHija->setMinimumSize(20, 20);
                                               buttonLineaHija->setMaximumSize(20, 20);
       QPushButton *button5 = new QPushButton("Five");  button5->setStyleSheet(styleSheet);

       layoutLeft->addWidget(buttonLinea);
       layoutLeft->addWidget(buttonLineaPadre);
       layoutLeft->addWidget(buttonLineaHija);
       layoutLeft->addWidget(buttonPunto);
       layoutLeft->addWidget(button5);

       QVBoxLayout *layoutRight = new QVBoxLayout();

       QPushButton *button1R = new QPushButton("One");
       QPushButton *button2R = new QPushButton("Two");
       QPushButton *button3R = new QPushButton("Three");
       QPushButton *button4R = new QPushButton("Four");
       QPushButton *button5R = new QPushButton("Five");
       layoutRight->addWidget(button1R);
       layoutRight->addWidget(button2R);
       layoutRight->addWidget(button3R);
       layoutRight->addWidget(button4R);
       layoutRight->addWidget(button5R);


       // ADD GROUP OF BUTTONS TO CENTRAL LAYOUT
       layoutCentral->addLayout(layoutLeft);
   //    layoutCentral->addLayout(layoutMiddle);
       layoutCentral->addLayout(layoutRight);

       layoutCentral->setAlignment(layoutLeft, Qt::AlignLeft);
       layoutCentral->setAlignment(layoutRight, Qt::AlignRight);

       //CONECCIONES DE LOS BOTONES
       connect(this->buttonLinea, SIGNAL(pressed()), this, SLOT(buttonLinea_click_action()));
       connect(this->buttonLineaPadre, SIGNAL(pressed()), this, SLOT(buttonLineaPadre_click_action()));
       connect(this->buttonLineaHija, SIGNAL(pressed()), this, SLOT(buttonLineaHija_click_action()));
       connect(this->buttonPunto, SIGNAL(pressed()), this, SLOT(buttonPunto_click_action()));
       connect(this, SIGNAL(draw_order(bool, TIPO)), ui->openGLWidget, SLOT(draw_object(bool, TIPO)));

       //SET CHECKABLE ALL BUTTONS OF FUNCTIONALITY
       this->buttonLinea->setCheckable(true);
       this->buttonLineaPadre->setCheckable(true);
       this->buttonLineaHija->setCheckable(true);
       this->buttonPunto->setCheckable(true);

       ui->openGLWidget->setLayout(layoutCentral);

       this->setMaximumSize(1300, 700);
       this->setMinimumSize(1300, 700);
}

void FormDrawable::resizeEvent(QResizeEvent *event)
{
    this->update();
//    button->setGeometry(this->width()-20,this->height()-20,50,20);
}

FormDrawable::~FormDrawable()
{
    delete ui;
}

void FormDrawable::buttonLinea_click_action()
{
    if   (this->buttonLinea->isChecked()){
        emit draw_order(false, TIPO::MOVE_SCENE);
    }
    else{
        this->buttonLineaPadre->setChecked(false);
        this->buttonLineaHija->setChecked(false);
        this->buttonPunto->setChecked(false);
        emit draw_order(true, TIPO::LINEA_SIMPLE);
    }
}

void FormDrawable::buttonLineaPadre_click_action()
{
    if   (this->buttonLineaPadre->isChecked()){
        emit draw_order(false, TIPO::MOVE_SCENE);
    }
    else{
        this->buttonLinea->setChecked(false);
        this->buttonLineaHija->setChecked(false);
        this->buttonPunto->setChecked(false);
        emit draw_order(true, TIPO::LINEA_PADRE);
    }
}

void FormDrawable::buttonLineaHija_click_action()
{
    if   (this->buttonLineaHija->isChecked()){
        emit draw_order(false, TIPO::MOVE_SCENE);
    }
    else{
        this->buttonLinea->setChecked(false);
        this->buttonLineaPadre->setChecked(false);
        this->buttonPunto->setChecked(false);
        emit draw_order(true, TIPO::LINEA_HIJA);
    }
}

void FormDrawable::buttonPunto_click_action()
{
    if   (this->buttonPunto->isChecked()){
        emit draw_order(false, TIPO::MOVE_SCENE);
    }
    else{
        this->buttonLinea->setChecked(false);
        this->buttonLineaPadre->setChecked(false);
        this->buttonLineaHija->setChecked(false);
        emit draw_order(true, TIPO::CUADRADO);
    }
}
