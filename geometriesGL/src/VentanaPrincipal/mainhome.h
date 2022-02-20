#ifndef MAINHOME_H
#define MAINHOME_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QFile>
#include <string>

#include "geometriesGL/src/measureActions/dbmanager_interface.h"
#include "geometriesGL/src/measureActions/dbmanager.h"

#include "geometriesGL/src/measureActions/form_addclient.h"
#include "geometriesGL/src/measureActions/form_viewwidget_showpedidos.h"
#include "geometriesGL/src/measureActions/form_viewwidget_design.h"

using namespace std;

QT_BEGIN_NAMESPACE namespace Ui { class MainHome; } QT_END_NAMESPACE

class MainHome : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainHome(QWidget *parent = nullptr);
    ~MainHome();

    void mousePressEvent(QMouseEvent *event) override;
    QObject *btn;
    QString btnName;

    Ui::MainHome*widget;
//    interface_modulos function;

private:
    QMouseEvent *eventoMouse;

    Form_addClient *iP_form_addClient;

    Form_ViewWidget_ShowPedidos *iP_form_viewwidget_showpedidos;

    Form_ViewWidget_Design *iP_form_viewwidget_design;

    QSharedPointer<DbManager_interface> iP_interface;

public:
    Ui::MainHome *ui;

    QWidget *parent;
    QPropertyAnimation *animation;
    QPropertyAnimation *left_box;
    QPropertyAnimation *right_box;
    QParallelAnimationGroup *group;

protected:

    QAction *action_showPedidos;
    QAction *action_deleteClient;

public slots:
    void slotMenuToggle();
    void slotLeftBoxToggle();
    void slotRightBoxToggle();

    void setCurrentHome();
    void setCurrentHome2();
    void setCurrentHome3();
    void setCurrentHome4();

    void showFormAddClient();
    void setCurrentPedidosClient();

    void makePush();
    void closedDrawing();

    void slot_EmmitPedidos();
    void slot_EmmitRegistro();

    void slot_printItem(QTableWidgetItem *item);


private slots:
    void on_pushButtonStartDrawing_clicked();

};

#endif // MAINHOME_H
