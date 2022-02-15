/********************************************************************************
** Form generated from reading UI file 'windowwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWWIDGET_H
#define UI_WINDOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *centralWidget;

    void setupUi(QWidget *windowWidget)
    {
        if (windowWidget->objectName().isEmpty())
            windowWidget->setObjectName(QString::fromUtf8("windowWidget"));
        windowWidget->resize(734, 469);
        gridLayout = new QGridLayout(windowWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        centralWidget = new QWidget(windowWidget);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

        gridLayout->addWidget(centralWidget, 0, 0, 1, 1);


        retranslateUi(windowWidget);

        QMetaObject::connectSlotsByName(windowWidget);
    } // setupUi

    void retranslateUi(QWidget *windowWidget)
    {
        windowWidget->setWindowTitle(QCoreApplication::translate("windowWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class windowWidget: public Ui_windowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWWIDGET_H
