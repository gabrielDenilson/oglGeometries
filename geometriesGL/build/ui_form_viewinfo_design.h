/********************************************************************************
** Form generated from reading UI file 'form_viewinfo_design.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_VIEWINFO_DESIGN_H
#define UI_FORM_VIEWINFO_DESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_ViewInfo_Design
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_4;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QPushButton *pushButton;

    void setupUi(QWidget *Form_ViewInfo_Design)
    {
        if (Form_ViewInfo_Design->objectName().isEmpty())
            Form_ViewInfo_Design->setObjectName(QString::fromUtf8("Form_ViewInfo_Design"));
        Form_ViewInfo_Design->resize(790, 373);
        verticalLayout_5 = new QVBoxLayout(Form_ViewInfo_Design);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(Form_ViewInfo_Design);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(Form_ViewInfo_Design);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(Form_ViewInfo_Design);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        verticalLayout_3->addLayout(verticalLayout);

        line = new QFrame(Form_ViewInfo_Design);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(Form_ViewInfo_Design);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(3, 1);

        horizontalLayout->addLayout(verticalLayout_3);

        line_2 = new QFrame(Form_ViewInfo_Design);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(70, 70, 70, 170);
        frame = new QFrame(Form_ViewInfo_Design);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(frame);

        pushButton = new QPushButton(Form_ViewInfo_Design);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalLayout->setStretch(0, 1);

        verticalLayout_5->addLayout(horizontalLayout);


        retranslateUi(Form_ViewInfo_Design);

        QMetaObject::connectSlotsByName(Form_ViewInfo_Design);
    } // setupUi

    void retranslateUi(QWidget *Form_ViewInfo_Design)
    {
        Form_ViewInfo_Design->setWindowTitle(QCoreApplication::translate("Form_ViewInfo_Design", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_ViewInfo_Design", "Informacion de Dies\303\261o", nullptr));
        label_2->setText(QCoreApplication::translate("Form_ViewInfo_Design", "Nombre", nullptr));
        label_4->setText(QCoreApplication::translate("Form_ViewInfo_Design", "No se seleccionado el archivo", nullptr));
        label_3->setText(QCoreApplication::translate("Form_ViewInfo_Design", "Valores", nullptr));
        pushButton->setText(QCoreApplication::translate("Form_ViewInfo_Design", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_ViewInfo_Design: public Ui_Form_ViewInfo_Design {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_VIEWINFO_DESIGN_H
