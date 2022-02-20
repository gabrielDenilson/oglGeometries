#ifndef FORM_ADDCLIENT_H
#define FORM_ADDCLIENT_H

#include <QWidget>
#include <QStringList>

#include "dbclient_interface.h"

namespace Ui {
class Form_addClient;
}

class Form_addClient : public QWidget
{
    Q_OBJECT

public:
    explicit Form_addClient(QWidget *parent = nullptr);
    ~Form_addClient();

    //Function to validate the data of QLineEdit is empty
    bool validateDataIsEmpty(QLineEdit *lineEdit);

    //Function to validate if QLineEdit is numeric
    bool validateDataIsNumeric(QLineEdit *lineEdit);

    QString returnFirstCharacterToUpper(QString string);

    //Function to set format of QLineEdit
    void setFormat(QLineEdit *lineEdit);

    QStringList getDataFromForm();
    void setDataToDb();

private:
    bool flag_nombre;
    bool flag_apellido;
    bool flag_contacto;

    Ui::Form_addClient *ui;

    QSharedPointer<DbClient_interface> iP_interfaceClient;

private slots:
    void closeForm();

    //slot to add client
    void addClient();
};

#endif // FORM_ADDCLIENT_H
