/********************************************************************************
** Form generated from reading UI file 'dialog_createfigures.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CREATEFIGURES_H
#define UI_DIALOG_CREATEFIGURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_CreateFigures
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_CreateFigures)
    {
        if (Dialog_CreateFigures->objectName().isEmpty())
            Dialog_CreateFigures->setObjectName(QString::fromUtf8("Dialog_CreateFigures"));
        Dialog_CreateFigures->resize(548, 412);
        buttonBox = new QDialogButtonBox(Dialog_CreateFigures);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 350, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Dialog_CreateFigures);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_CreateFigures, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_CreateFigures, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_CreateFigures);
    } // setupUi

    void retranslateUi(QDialog *Dialog_CreateFigures)
    {
        Dialog_CreateFigures->setWindowTitle(QCoreApplication::translate("Dialog_CreateFigures", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_CreateFigures: public Ui_Dialog_CreateFigures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CREATEFIGURES_H
