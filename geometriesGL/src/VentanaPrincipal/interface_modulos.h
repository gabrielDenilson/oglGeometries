#ifndef INTERFACE_MODULOS_H
#define INTERFACE_MODULOS_H

#include <mainwindow.h>
#include "settings.h"

static bool GLOBAL_STATE = false;
static bool GLOBAL_TITLE_BAR = true;

class interface_modulos : public MainWindow
{
public:
    interface_modulos();
    ~interface_modulos();

public slots:

    static void maximize_restore(MainWindow *self);
    static bool returnStatus(MainWindow *self){ return GLOBAL_STATE; }

    static void setStatus(MainWindow, bool status){ GLOBAL_STATE = status; }

    //Seleccionar-Deseleccionar Menu
    //seleccionar
    static QString selectMenu(QString getStyle);
    //deseleccionar
    static QString deselectMenu(QString getStyle);
    //start secection
    static void selectStandardMenu(MainWindow *self, QWidget *widget);
    //reset selection
    static void resetStyle(MainWindow *self, QWidget *widget);

    //START GUI DEFINITIONS
    void dobleClickMaximizeRestore(MainWindow *self, QMouseEvent *event);
    void moveWindow(QMouseEvent *event);
    void resize_Grips(MainWindow *self);
    void uiDefinitions(MainWindow);


    static void toggleMenu(MainWindow *self, bool enable);
    static void toggleLeftBox(MainWindow *self, bool enable);
    static void toggleRightBox(MainWindow *self, bool enable);
    static void start_box_animation(MainWindow *self, int left_box_width, int right_box_width, string direction);
    static void theme(MainWindow *self, QFile &file, bool use_theme);
    static void set_theme(MainWindow *self);

private:

};

#endif // INTERFACE_MODULOS_H
