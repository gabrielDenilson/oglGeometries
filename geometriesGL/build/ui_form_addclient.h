/********************************************************************************
** Form generated from reading UI file 'form_addclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_ADDCLIENT_H
#define UI_FORM_ADDCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_addClient
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_AddClient;
    QSpacerItem *horizontalSpacer_11;
    QDateTimeEdit *dateTimeEdit_Client;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_id;
    QLineEdit *lineEdit_idClient;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_nombreCliente;
    QComboBox *comboBox_3;
    QLabel *label_nombre;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_apellidoCliente;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_ContactoCliente;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *btn_agregar;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *btn_cancelar;
    QSpacerItem *horizontalSpacer_13;

    void setupUi(QWidget *Form_addClient)
    {
        if (Form_addClient->objectName().isEmpty())
            Form_addClient->setObjectName(QString::fromUtf8("Form_addClient"));
        Form_addClient->resize(433, 545);
        verticalLayout_4 = new QVBoxLayout(Form_addClient);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, 12, 5, 9);
        label_AddClient = new QLabel(Form_addClient);
        label_AddClient->setObjectName(QString::fromUtf8("label_AddClient"));

        horizontalLayout_7->addWidget(label_AddClient);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        dateTimeEdit_Client = new QDateTimeEdit(Form_addClient);
        dateTimeEdit_Client->setObjectName(QString::fromUtf8("dateTimeEdit_Client"));

        horizontalLayout_7->addWidget(dateTimeEdit_Client);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 8, -1, 9);
        horizontalSpacer_10 = new QSpacerItem(298, 23, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        label_id = new QLabel(Form_addClient);
        label_id->setObjectName(QString::fromUtf8("label_id"));

        horizontalLayout_6->addWidget(label_id);

        lineEdit_idClient = new QLineEdit(Form_addClient);
        lineEdit_idClient->setObjectName(QString::fromUtf8("lineEdit_idClient"));

        horizontalLayout_6->addWidget(lineEdit_idClient);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 11, -1, 11);
        lineEdit_nombreCliente = new QLineEdit(Form_addClient);
        lineEdit_nombreCliente->setObjectName(QString::fromUtf8("lineEdit_nombreCliente"));

        horizontalLayout->addWidget(lineEdit_nombreCliente);

        comboBox_3 = new QComboBox(Form_addClient);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        comboBox_3->setFont(font);
        comboBox_3->setAutoFillBackground(false);
        comboBox_3->setIconSize(QSize(16, 16));
        comboBox_3->setFrame(true);

        horizontalLayout->addWidget(comboBox_3);


        verticalLayout->addLayout(horizontalLayout);

        label_nombre = new QLabel(Form_addClient);
        label_nombre->setObjectName(QString::fromUtf8("label_nombre"));
        label_nombre->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_nombre);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(47, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 7, 0, 7);
        lineEdit_apellidoCliente = new QLineEdit(Form_addClient);
        lineEdit_apellidoCliente->setObjectName(QString::fromUtf8("lineEdit_apellidoCliente"));

        verticalLayout_2->addWidget(lineEdit_apellidoCliente);

        label_4 = new QLabel(Form_addClient);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 7, -1, 7);
        lineEdit_ContactoCliente = new QLineEdit(Form_addClient);
        lineEdit_ContactoCliente->setObjectName(QString::fromUtf8("lineEdit_ContactoCliente"));

        verticalLayout_3->addWidget(lineEdit_ContactoCliente);

        label_5 = new QLabel(Form_addClient);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(16);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 22, -1, 18);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        label_2 = new QLabel(Form_addClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        comboBox_2 = new QComboBox(Form_addClient);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        comboBox_2->setFont(font1);
        comboBox_2->setAutoFillBackground(false);
        comboBox_2->setIconSize(QSize(16, 16));
        comboBox_2->setFrame(true);

        horizontalLayout_5->addWidget(comboBox_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);


        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_8->setContentsMargins(0, 12, -1, 18);
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);

        btn_agregar = new QPushButton(Form_addClient);
        btn_agregar->setObjectName(QString::fromUtf8("btn_agregar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(5);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(btn_agregar->sizePolicy().hasHeightForWidth());
        btn_agregar->setSizePolicy(sizePolicy2);
        btn_agregar->setMinimumSize(QSize(0, 30));
        btn_agregar->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_8->addWidget(btn_agregar);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);

        btn_cancelar = new QPushButton(Form_addClient);
        btn_cancelar->setObjectName(QString::fromUtf8("btn_cancelar"));
        sizePolicy2.setHeightForWidth(btn_cancelar->sizePolicy().hasHeightForWidth());
        btn_cancelar->setSizePolicy(sizePolicy2);
        btn_cancelar->setMinimumSize(QSize(0, 30));
        btn_cancelar->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_8->addWidget(btn_cancelar);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);


        verticalLayout_4->addLayout(horizontalLayout_8);

        QWidget::setTabOrder(dateTimeEdit_Client, lineEdit_idClient);
        QWidget::setTabOrder(lineEdit_idClient, comboBox_3);
        QWidget::setTabOrder(comboBox_3, lineEdit_apellidoCliente);
        QWidget::setTabOrder(lineEdit_apellidoCliente, lineEdit_ContactoCliente);
        QWidget::setTabOrder(lineEdit_ContactoCliente, comboBox_2);
        QWidget::setTabOrder(comboBox_2, btn_agregar);

        retranslateUi(Form_addClient);

        QMetaObject::connectSlotsByName(Form_addClient);
    } // setupUi

    void retranslateUi(QWidget *Form_addClient)
    {
        Form_addClient->setWindowTitle(QCoreApplication::translate("Form_addClient", "Form", nullptr));
        label_AddClient->setText(QCoreApplication::translate("Form_addClient", "Agregar Cliente", nullptr));
        dateTimeEdit_Client->setDisplayFormat(QCoreApplication::translate("Form_addClient", "d-M-yyyy HH-mm", nullptr));
        label_id->setText(QCoreApplication::translate("Form_addClient", "Id", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Form_addClient", "M", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Form_addClient", "F", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("Form_addClient", "NN", nullptr));

        label_nombre->setText(QCoreApplication::translate("Form_addClient", "Nombre", nullptr));
        label_4->setText(QCoreApplication::translate("Form_addClient", "Apellido", nullptr));
        label_5->setText(QCoreApplication::translate("Form_addClient", "Contacto", nullptr));
        label_2->setText(QCoreApplication::translate("Form_addClient", "Tipo", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Form_addClient", "A medida", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Form_addClient", "Informal", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Form_addClient", "Servicio de arreglo", nullptr));

        btn_agregar->setText(QCoreApplication::translate("Form_addClient", "AGREGAR", nullptr));
        btn_cancelar->setText(QCoreApplication::translate("Form_addClient", "CANCELAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_addClient: public Ui_Form_addClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_ADDCLIENT_H
