#ifndef INTERFACE_MODULOS_H
#define INTERFACE_MODULOS_H

#include "geometriesGL/src/VentanaPrincipal/settings.h"

#include "mainhome.h"


static bool GLOBAL_STATE = false;
static bool GLOBAL_TITLE_BAR = true;

class interface_modulos : public MainHome
{
public:
    interface_modulos();
    ~interface_modulos();

public slots:

    static void maximize_restore(MainHome *self);
    static bool returnStatus(MainHome *){ return GLOBAL_STATE; }

    static void setStatus(MainHome, bool status){ GLOBAL_STATE = status; }

    //Seleccionar-Deseleccionar Menu
    //seleccionar
    static QString selectMenu(QString getStyle);
    //deseleccionar
    static QString deselectMenu(QString getStyle);
    //start secection
    static void selectStandardMenu(MainHome *self, QWidget *widget);
    //reset selection
    static void resetStyle(MainHome *self, QWidget *widget);

    //START GUI DEFINITIONS
    void dobleClickMaximizeRestore(MainHome *self, QMouseEvent *event);
    void moveWindow(QMouseEvent *event);
    void resize_Grips(MainHome *self);
    void uiDefinitions(MainHome);


    static void toggleMenu(MainHome *self, bool enable);
    static void toggleLeftBox(MainHome *self, bool enable);
    static void toggleRightBox(MainHome *self, bool enable);
    static void start_box_animation(MainHome *self, int left_box_width, int right_box_width, string direction);
    static void theme(MainHome *self, QFile &file, bool use_theme);
    static void set_theme(MainHome *self);
    //function to set theme of a widget
    static void set_themeWidget(QWidget *widget, QFile &file);



private:

};

#endif // INTERFACE_MODULOS_H
