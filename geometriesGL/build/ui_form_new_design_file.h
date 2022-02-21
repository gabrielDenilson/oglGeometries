/********************************************************************************
** Form generated from reading UI file 'form_new_design_file.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_NEW_DESIGN_FILE_H
#define UI_FORM_NEW_DESIGN_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_New_Design_File
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_nombreDiseno;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_unidadMedida;
    QTableWidget *tableWidget_columnsDiseno;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_lessRow;
    QPushButton *pushButton_addRow;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_crearDiseno;
    QPushButton *pushButton_cancelarDiseno;

    void setupUi(QWidget *Form_New_Design_File)
    {
        if (Form_New_Design_File->objectName().isEmpty())
            Form_New_Design_File->setObjectName(QString::fromUtf8("Form_New_Design_File"));
        Form_New_Design_File->resize(310, 453);
        verticalLayout_2 = new QVBoxLayout(Form_New_Design_File);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Form_New_Design_File);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_nombreDiseno = new QLineEdit(Form_New_Design_File);
        lineEdit_nombreDiseno->setObjectName(QString::fromUtf8("lineEdit_nombreDiseno"));

        horizontalLayout->addWidget(lineEdit_nombreDiseno);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Form_New_Design_File);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_unidadMedida = new QComboBox(Form_New_Design_File);
        comboBox_unidadMedida->setObjectName(QString::fromUtf8("comboBox_unidadMedida"));

        horizontalLayout_2->addWidget(comboBox_unidadMedida);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget_columnsDiseno = new QTableWidget(Form_New_Design_File);
        tableWidget_columnsDiseno->setObjectName(QString::fromUtf8("tableWidget_columnsDiseno"));

        verticalLayout->addWidget(tableWidget_columnsDiseno);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_lessRow = new QPushButton(Form_New_Design_File);
        pushButton_lessRow->setObjectName(QString::fromUtf8("pushButton_lessRow"));

        horizontalLayout_3->addWidget(pushButton_lessRow);

        pushButton_addRow = new QPushButton(Form_New_Design_File);
        pushButton_addRow->setObjectName(QString::fromUtf8("pushButton_addRow"));

        horizontalLayout_3->addWidget(pushButton_addRow);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(Form_New_Design_File);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_crearDiseno = new QPushButton(Form_New_Design_File);
        pushButton_crearDiseno->setObjectName(QString::fromUtf8("pushButton_crearDiseno"));

        horizontalLayout_4->addWidget(pushButton_crearDiseno);

        pushButton_cancelarDiseno = new QPushButton(Form_New_Design_File);
        pushButton_cancelarDiseno->setObjectName(QString::fromUtf8("pushButton_cancelarDiseno"));

        horizontalLayout_4->addWidget(pushButton_cancelarDiseno);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Form_New_Design_File);

        QMetaObject::connectSlotsByName(Form_New_Design_File);
    } // setupUi

    void retranslateUi(QWidget *Form_New_Design_File)
    {
        Form_New_Design_File->setWindowTitle(QCoreApplication::translate("Form_New_Design_File", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_New_Design_File", "Nombre de dise\303\261o", nullptr));
        label_2->setText(QCoreApplication::translate("Form_New_Design_File", "Unidad de medida", nullptr));
        pushButton_lessRow->setText(QCoreApplication::translate("Form_New_Design_File", "-", nullptr));
        pushButton_addRow->setText(QCoreApplication::translate("Form_New_Design_File", "+", nullptr));
        pushButton_crearDiseno->setText(QCoreApplication::translate("Form_New_Design_File", "CREAR", nullptr));
        pushButton_cancelarDiseno->setText(QCoreApplication::translate("Form_New_Design_File", "CANCELAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_New_Design_File: public Ui_Form_New_Design_File {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_NEW_DESIGN_FILE_H
