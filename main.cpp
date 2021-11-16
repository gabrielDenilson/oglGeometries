#include "mainwindow.h"
#include "formdrawable.h"
#include "widgettrazado.h"
#include "windowwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w(nullptr, Qt::FramelessWindowHint);

    FormDrawable drawableWidget(nullptr);

//    widgetTrazado scene(nullptr);

//    windowWidget testWindow(nullptr);


//    testWindow.show();
    drawableWidget.show();
//    w.show();
    return a.exec();
}
