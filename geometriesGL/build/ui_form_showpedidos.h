/********************************************************************************
** Form generated from reading UI file 'form_showpedidos.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_SHOWPEDIDOS_H
#define UI_FORM_SHOWPEDIDOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ShowPedidos
{
public:
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_editarPedido;
    QLabel *label;
    QLineEdit *lineEdit_idPedido;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QComboBox *comboBox_estado;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QDateTimeEdit *dateTimeEdit_conclucion;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QDateTimeEdit *dateTimeEdit_verificacion;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QDateTimeEdit *dateTimeEdit_creacion;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *doubleSpinBox_saldo;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *doubleSpinBox_costoTotal;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_6;
    QDoubleSpinBox *doubleSpinBox_deuda;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QComboBox *comboBox_tipoPedido;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_observaciones;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_guardar;
    QPushButton *pushButton_cancelar;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_detalles;

    void setupUi(QWidget *Form_ShowPedidos)
    {
        if (Form_ShowPedidos->objectName().isEmpty())
            Form_ShowPedidos->setObjectName(QString::fromUtf8("Form_ShowPedidos"));
        Form_ShowPedidos->resize(847, 290);
        Form_ShowPedidos->setMinimumSize(QSize(0, 290));
        Form_ShowPedidos->setMaximumSize(QSize(16777215, 290));
        verticalLayout_9 = new QVBoxLayout(Form_ShowPedidos);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_editarPedido = new QPushButton(Form_ShowPedidos);
        pushButton_editarPedido->setObjectName(QString::fromUtf8("pushButton_editarPedido"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/cil-pen-alt.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_editarPedido->setIcon(icon);

        horizontalLayout_4->addWidget(pushButton_editarPedido);

        label = new QLabel(Form_ShowPedidos);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit_idPedido = new QLineEdit(Form_ShowPedidos);
        lineEdit_idPedido->setObjectName(QString::fromUtf8("lineEdit_idPedido"));

        horizontalLayout_4->addWidget(lineEdit_idPedido);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(29);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, 31, -1);
        label_10 = new QLabel(Form_ShowPedidos);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        comboBox_estado = new QComboBox(Form_ShowPedidos);
        comboBox_estado->addItem(QString());
        comboBox_estado->addItem(QString());
        comboBox_estado->addItem(QString());
        comboBox_estado->setObjectName(QString::fromUtf8("comboBox_estado"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_estado->sizePolicy().hasHeightForWidth());
        comboBox_estado->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(comboBox_estado);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dateTimeEdit_conclucion = new QDateTimeEdit(Form_ShowPedidos);
        dateTimeEdit_conclucion->setObjectName(QString::fromUtf8("dateTimeEdit_conclucion"));

        verticalLayout->addWidget(dateTimeEdit_conclucion);

        label_5 = new QLabel(Form_ShowPedidos);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(7);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dateTimeEdit_verificacion = new QDateTimeEdit(Form_ShowPedidos);
        dateTimeEdit_verificacion->setObjectName(QString::fromUtf8("dateTimeEdit_verificacion"));

        verticalLayout_2->addWidget(dateTimeEdit_verificacion);

        label_3 = new QLabel(Form_ShowPedidos);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        dateTimeEdit_creacion = new QDateTimeEdit(Form_ShowPedidos);
        dateTimeEdit_creacion->setObjectName(QString::fromUtf8("dateTimeEdit_creacion"));

        verticalLayout_3->addWidget(dateTimeEdit_creacion);

        label_2 = new QLabel(Form_ShowPedidos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        doubleSpinBox_saldo = new QDoubleSpinBox(Form_ShowPedidos);
        doubleSpinBox_saldo->setObjectName(QString::fromUtf8("doubleSpinBox_saldo"));
        doubleSpinBox_saldo->setMaximum(50000.989999999997963);
        doubleSpinBox_saldo->setSingleStep(10.000000000000000);

        verticalLayout_4->addWidget(doubleSpinBox_saldo);

        label_8 = new QLabel(Form_ShowPedidos);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        doubleSpinBox_costoTotal = new QDoubleSpinBox(Form_ShowPedidos);
        doubleSpinBox_costoTotal->setObjectName(QString::fromUtf8("doubleSpinBox_costoTotal"));
        doubleSpinBox_costoTotal->setMaximum(50000.989999999997963);
        doubleSpinBox_costoTotal->setSingleStep(10.000000000000000);

        verticalLayout_5->addWidget(doubleSpinBox_costoTotal);

        label_4 = new QLabel(Form_ShowPedidos);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        doubleSpinBox_deuda = new QDoubleSpinBox(Form_ShowPedidos);
        doubleSpinBox_deuda->setObjectName(QString::fromUtf8("doubleSpinBox_deuda"));
        doubleSpinBox_deuda->setMaximum(50000.989999999997963);
        doubleSpinBox_deuda->setSingleStep(10.000000000000000);

        verticalLayout_6->addWidget(doubleSpinBox_deuda);

        label_9 = new QLabel(Form_ShowPedidos);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_6->addWidget(label_9);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(Form_ShowPedidos);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        comboBox_tipoPedido = new QComboBox(Form_ShowPedidos);
        comboBox_tipoPedido->addItem(QString());
        comboBox_tipoPedido->addItem(QString());
        comboBox_tipoPedido->addItem(QString());
        comboBox_tipoPedido->setObjectName(QString::fromUtf8("comboBox_tipoPedido"));

        horizontalLayout->addWidget(comboBox_tipoPedido);


        verticalLayout_7->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_7);


        verticalLayout_9->addLayout(horizontalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(Form_ShowPedidos);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_7);

        textEdit_observaciones = new QTextEdit(Form_ShowPedidos);
        textEdit_observaciones->setObjectName(QString::fromUtf8("textEdit_observaciones"));
        textEdit_observaciones->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_8->addWidget(textEdit_observaciones);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_guardar = new QPushButton(Form_ShowPedidos);
        pushButton_guardar->setObjectName(QString::fromUtf8("pushButton_guardar"));

        horizontalLayout_8->addWidget(pushButton_guardar);

        pushButton_cancelar = new QPushButton(Form_ShowPedidos);
        pushButton_cancelar->setObjectName(QString::fromUtf8("pushButton_cancelar"));

        horizontalLayout_8->addWidget(pushButton_cancelar);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        pushButton_detalles = new QPushButton(Form_ShowPedidos);
        pushButton_detalles->setObjectName(QString::fromUtf8("pushButton_detalles"));

        horizontalLayout_9->addWidget(pushButton_detalles);


        verticalLayout_9->addLayout(horizontalLayout_9);


        retranslateUi(Form_ShowPedidos);

        QMetaObject::connectSlotsByName(Form_ShowPedidos);
    } // setupUi

    void retranslateUi(QWidget *Form_ShowPedidos)
    {
        Form_ShowPedidos->setWindowTitle(QCoreApplication::translate("Form_ShowPedidos", "Form", nullptr));
        pushButton_editarPedido->setText(QString());
        label->setText(QCoreApplication::translate("Form_ShowPedidos", "ID DE PEDIDO", nullptr));
        label_10->setText(QCoreApplication::translate("Form_ShowPedidos", "ESTADO", nullptr));
        comboBox_estado->setItemText(0, QCoreApplication::translate("Form_ShowPedidos", "Entregado", nullptr));
        comboBox_estado->setItemText(1, QCoreApplication::translate("Form_ShowPedidos", "En proceso", nullptr));
        comboBox_estado->setItemText(2, QCoreApplication::translate("Form_ShowPedidos", "Na", nullptr));

        label_5->setText(QCoreApplication::translate("Form_ShowPedidos", "CONCLUCION", nullptr));
        label_3->setText(QCoreApplication::translate("Form_ShowPedidos", "VERIFICACION", nullptr));
        label_2->setText(QCoreApplication::translate("Form_ShowPedidos", "CREACION", nullptr));
        doubleSpinBox_saldo->setSuffix(QCoreApplication::translate("Form_ShowPedidos", "Bs", nullptr));
        label_8->setText(QCoreApplication::translate("Form_ShowPedidos", "SALDO", nullptr));
        label_4->setText(QCoreApplication::translate("Form_ShowPedidos", "COSTO TOTAL", nullptr));
        label_9->setText(QCoreApplication::translate("Form_ShowPedidos", "DEUDA", nullptr));
        label_6->setText(QCoreApplication::translate("Form_ShowPedidos", "TIPO", nullptr));
        comboBox_tipoPedido->setItemText(0, QCoreApplication::translate("Form_ShowPedidos", "A medida", nullptr));
        comboBox_tipoPedido->setItemText(1, QCoreApplication::translate("Form_ShowPedidos", "Informal", nullptr));
        comboBox_tipoPedido->setItemText(2, QCoreApplication::translate("Form_ShowPedidos", "Servicio", nullptr));

        label_7->setText(QCoreApplication::translate("Form_ShowPedidos", "OBSERVACIONES", nullptr));
        textEdit_observaciones->setMarkdown(QString());
        textEdit_observaciones->setPlaceholderText(QCoreApplication::translate("Form_ShowPedidos", "Observaciones de pedido...", nullptr));
        pushButton_guardar->setText(QCoreApplication::translate("Form_ShowPedidos", "GUARDAR", nullptr));
        pushButton_cancelar->setText(QCoreApplication::translate("Form_ShowPedidos", "CANCELAR", nullptr));
        pushButton_detalles->setText(QCoreApplication::translate("Form_ShowPedidos", "DETALLES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_ShowPedidos: public Ui_Form_ShowPedidos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_SHOWPEDIDOS_H
