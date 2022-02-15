#ifndef FORM_ADDCLIENT_H
#define FORM_ADDCLIENT_H

#include <QWidget>

namespace Ui {
class Form_addClient;
}

class Form_addClient : public QWidget
{
    Q_OBJECT

public:
    explicit Form_addClient(QWidget *parent = nullptr);
    ~Form_addClient();

private:
    Ui::Form_addClient *ui;

private slots:
    void closeForm();
};

#endif // FORM_ADDCLIENT_H
