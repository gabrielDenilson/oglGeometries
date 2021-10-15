QT       += core gui opengl

LIBS += -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


INCLUDEPATH += "C:\Users\GabrielSinn\OneDrive\Documentos\QML_all\repositorios\libreriasExternas"

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    externshader.cpp \
    geometriesGL/src/comands/cmd_renderizarlineas.cpp \
    geometriesGL/src/comands/compoundgeometry.cpp \
    geometriesGL/src/comands/geometry.cpp \
    geometriesGL/src/comands/resourcemanager.cpp \
    geometriesGL/src/comands/shader.cpp \
    geometriesGL/src/comands/spriterender.cpp \
    geometriesGL/src/comands/texture.cpp \
    linea.cpp \
    main.cpp \
    mainwindow.cpp \
    planotrazado.cpp \
    punto.cpp \
    renderfigures.cpp \
    triangulo.cpp \
    trianguloprimitivo.cpp \
    widgettrazado.cpp

HEADERS += \
    externshader.h \
    geometriesGL/res/purebaClase.h \
    geometriesGL/src/actions/actionsPrueba.h \
    geometriesGL/src/comands/cmd_renderizarlineas.h \
    geometriesGL/src/comands/compoundgeometry.h \
    geometriesGL/src/comands/geometry.h \
    geometriesGL/src/comands/resourcemanager.h \
    geometriesGL/src/comands/shader.h \
    geometriesGL/src/comands/spriterender.h \
    geometriesGL/src/comands/texture.h \
    geometriesGL/src/forms/formsPrueba.h \
    linea.h \
    mainwindow.h \
    planotrazado.h \
    punto.h \
    renderfigures.h \
    triangulo.h \
    trianguloprimitivo.h \
    widgettrazado.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    geometriesGL/res/Nuevo documento de texto.txt \
    shaders/fragmentShader.fs \
    shaders/fragmentShader_spriteRender.frag \
    shaders/vertexShader.vs \
    shaders/vertexShader_spriteRender.vert
