#ifndef FORM_VIEWINFO_DESIGN_H
#define FORM_VIEWINFO_DESIGN_H

#include <QWidget>

namespace Ui {
class Form_ViewInfo_Design;
}

class Form_ViewInfo_Design : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ViewInfo_Design(QWidget *parent = nullptr);
    Form_ViewInfo_Design(QWidget *parent = nullptr, QString nombre = "");
    ~Form_ViewInfo_Design();

    void setNameOfLabels(QStringList valuesOfTable, QString nameTable); //Funcion que realiza toda la operacion para presentar la informacion en la pantalla
    void addValuesToGridLayout(QStringList valuesOfTable); // Procdure to add item Tags to grid layout of this form

    bool checkIfExistFileDesign(QString path);
    void changueButtonInfoOfFileExistance(); // Procedure to changue "View File" or "Add File"

private:
    Ui::Form_ViewInfo_Design *ui;
    QString nombre;
};

#endif // FORM_VIEWINFO_DESIGN_H
