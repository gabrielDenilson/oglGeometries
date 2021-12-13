#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class interface_modulos;

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#include "mainsimplewindow.h"
//#include "interface_modulos.h"

#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {

class MainWindow;

}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMouseEvent *eventoMouse;
     MainSimpleWindow *simpleWindow;

public:
     QWidget *parent;

     QPropertyAnimation *animation;
     QPropertyAnimation *left_box;
     QPropertyAnimation *right_box;
     QParallelAnimationGroup *group;
     Ui::MainWindow *ui;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event) override;
    

    QObject *btn;
    QString btnName;

    Ui::MainWindow *widget;

//    interface_modulos function;

public slots:
    void slotMenuToggle();
    void slotLeftBoxToggle();
    void slotRightBoxToggle();

    void setCurrentHome();
    void setCurrentHome2();
    void setCurrentHome3();

    void makePush();
    void closedDrawing();


private slots:
    void on_pushButtonStartDrawing_clicked();
};
#endif // MAINWINDOW_H
