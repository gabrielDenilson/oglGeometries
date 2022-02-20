/********************************************************************************
** Form generated from reading UI file 'form_viewwidget_design.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_VIEWWIDGET_DESIGN_H
#define UI_FORM_VIEWWIDGET_DESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ViewWidget_Design
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Form_ViewWidget_Design)
    {
        if (Form_ViewWidget_Design->objectName().isEmpty())
            Form_ViewWidget_Design->setObjectName(QString::fromUtf8("Form_ViewWidget_Design"));
        Form_ViewWidget_Design->resize(838, 590);
        verticalLayout = new QVBoxLayout(Form_ViewWidget_Design);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Form_ViewWidget_Design);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Form_ViewWidget_Design);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(Form_ViewWidget_Design);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        scrollArea = new QScrollArea(Form_ViewWidget_Design);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 818, 531));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Form_ViewWidget_Design);

        QMetaObject::connectSlotsByName(Form_ViewWidget_Design);
    } // setupUi

    void retranslateUi(QWidget *Form_ViewWidget_Design)
    {
        Form_ViewWidget_Design->setWindowTitle(QCoreApplication::translate("Form_ViewWidget_Design", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_ViewWidget_Design", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Form_ViewWidget_Design", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_ViewWidget_Design: public Ui_Form_ViewWidget_Design {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_VIEWWIDGET_DESIGN_H
