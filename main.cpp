
#include "geometriesGL/src/VentanaPrincipal/mainwindow.h"
#include "form_measures.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    FormDrawable drawableWidget(nullptr);

//    drawableWidget.show();

    MainWindow ventanaPrincipal(nullptr);

    ventanaPrincipal.show();

    return a.exec();
}
