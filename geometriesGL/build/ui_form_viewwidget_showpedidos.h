/********************************************************************************
** Form generated from reading UI file 'form_viewwidget_showpedidos.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_VIEWWIDGET_SHOWPEDIDOS_H
#define UI_FORM_VIEWWIDGET_SHOWPEDIDOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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

class Ui_Form_ViewWidget_ShowPedidos
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QFrame *line;
    QScrollArea *scrollArea_pedidosWidget;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Form_ViewWidget_ShowPedidos)
    {
        if (Form_ViewWidget_ShowPedidos->objectName().isEmpty())
            Form_ViewWidget_ShowPedidos->setObjectName(QString::fromUtf8("Form_ViewWidget_ShowPedidos"));
        Form_ViewWidget_ShowPedidos->resize(723, 488);
        verticalLayout_3 = new QVBoxLayout(Form_ViewWidget_ShowPedidos);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(13);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(15, 12, 17, 17);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(7, 7, 7, 7);
        label = new QLabel(Form_ViewWidget_ShowPedidos);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Form_ViewWidget_ShowPedidos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/cil-highligt.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(Form_ViewWidget_ShowPedidos);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        verticalLayout_2->addLayout(verticalLayout);

        scrollArea_pedidosWidget = new QScrollArea(Form_ViewWidget_ShowPedidos);
        scrollArea_pedidosWidget->setObjectName(QString::fromUtf8("scrollArea_pedidosWidget"));
        scrollArea_pedidosWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_pedidosWidget->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 687, 377));
        scrollArea_pedidosWidget->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea_pedidosWidget);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Form_ViewWidget_ShowPedidos);

        QMetaObject::connectSlotsByName(Form_ViewWidget_ShowPedidos);
    } // setupUi

    void retranslateUi(QWidget *Form_ViewWidget_ShowPedidos)
    {
        Form_ViewWidget_ShowPedidos->setWindowTitle(QCoreApplication::translate("Form_ViewWidget_ShowPedidos", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form_ViewWidget_ShowPedidos", "Pedidos Jose Maria", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form_ViewWidget_ShowPedidos: public Ui_Form_ViewWidget_ShowPedidos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_VIEWWIDGET_SHOWPEDIDOS_H
