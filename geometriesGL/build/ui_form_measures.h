/********************************************************************************
** Form generated from reading UI file 'form_measures.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_MEASURES_H
#define UI_FORM_MEASURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_measures
{
public:

    void setupUi(QWidget *Form_measures)
    {
        if (Form_measures->objectName().isEmpty())
            Form_measures->setObjectName(QString::fromUtf8("Form_measures"));
        Form_measures->resize(400, 300);

        retranslateUi(Form_measures);

        QMetaObject::connectSlotsByName(Form_measures);
    } // setupUi

    void retranslateUi(QWidget *Form_measures)
    {
        Form_measures->setWindowTitle(QCoreApplication::translate("Form_measures", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_measures: public Ui_Form_measures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_MEASURES_H
