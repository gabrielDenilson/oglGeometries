//#include "mainwindow.h"
#include "formdrawable.h"
//#include "widgettrazado.h"
//#include "windowwidget.h"
//#include "dialog_createfigures.h"
#include "form_measures.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w(nullptr, Qt::FramelessWindowHint);

    FormDrawable drawableWidget(nullptr);

//    widgetTrazado scene(nullptr);

//    windowWidget testWindow(nullptr);

//    Dialog_CreateFigures welcome(nullptr);

//    testWindow.show();
    drawableWidget.show();
//    w.show();
//        welcome.show();

//    Form_measures widito(nullptr);
//            widito.show();
    return a.exec();
}
