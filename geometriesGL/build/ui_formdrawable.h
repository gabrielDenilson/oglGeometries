/********************************************************************************
** Form generated from reading UI file 'formdrawable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDRAWABLE_H
#define UI_FORMDRAWABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "widgettrazado.h"

QT_BEGIN_NAMESPACE

class Ui_FormDrawable
{
public:
    QGridLayout *gridLayout;
    widgetTrazado *openGLWidget;

    void setupUi(QWidget *FormDrawable)
    {
        if (FormDrawable->objectName().isEmpty())
            FormDrawable->setObjectName(QString::fromUtf8("FormDrawable"));
        FormDrawable->resize(868, 479);
        gridLayout = new QGridLayout(FormDrawable);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new widgetTrazado(FormDrawable);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);


        retranslateUi(FormDrawable);

        QMetaObject::connectSlotsByName(FormDrawable);
    } // setupUi

    void retranslateUi(QWidget *FormDrawable)
    {
        FormDrawable->setWindowTitle(QCoreApplication::translate("FormDrawable", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormDrawable: public Ui_FormDrawable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDRAWABLE_H
