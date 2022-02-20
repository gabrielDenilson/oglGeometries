/********************************************************************************
** Form generated from reading UI file 'form_itemdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_ITEMDESIGN_H
#define UI_FORM_ITEMDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ItemDesign
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QLabel *label;

    void setupUi(QWidget *Form_ItemDesign)
    {
        if (Form_ItemDesign->objectName().isEmpty())
            Form_ItemDesign->setObjectName(QString::fromUtf8("Form_ItemDesign"));
        Form_ItemDesign->resize(135, 182);
        Form_ItemDesign->setMinimumSize(QSize(135, 182));
        Form_ItemDesign->setMaximumSize(QSize(135, 182));
        Form_ItemDesign->setSizeIncrement(QSize(135, 182));
        verticalLayout = new QVBoxLayout(Form_ItemDesign);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Form_ItemDesign);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-image: url(:images/images/images/document-128.png);\n"
"background-position: center;\n"
"background-repeat: no-repeat;"));

        verticalLayout->addWidget(widget);

        label = new QLabel(Form_ItemDesign);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        verticalLayout->setStretch(0, 1);

        retranslateUi(Form_ItemDesign);

        QMetaObject::connectSlotsByName(Form_ItemDesign);
    } // setupUi

    void retranslateUi(QWidget *Form_ItemDesign)
    {
        Form_ItemDesign->setWindowTitle(QCoreApplication::translate("Form_ItemDesign", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_ItemDesign", "Title unsaved_file.gl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_ItemDesign: public Ui_Form_ItemDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_ITEMDESIGN_H
