QT       += core gui opengl

LIBS += -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


#INCLUDEPATH += "C:\Users\GabrielSinn\OneDrive\Documentos\QML_all\repositorios\libreriasExternas"

INCLUDEPATH += $$PWD/geometriesGL/res/include

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
    dialog_createfigures.cpp \
    externshader.cpp \
    form_measures.cpp \
    formdrawable.cpp \
    geometriesGL/res/focmaths.cpp \
    geometriesGL/src/VentanaPrincipal/customgrip.cpp \
    geometriesGL/src/VentanaPrincipal/interface_modulos.cpp \
    geometriesGL/src/VentanaPrincipal/mainsimplewindow.cpp \
    geometriesGL/src/VentanaPrincipal/mainwindow.cpp \
    geometriesGL/src/VentanaPrincipal/settings.cpp \
    geometriesGL/src/actions/camera2d.cpp \
    geometriesGL/src/actions/interactivefigure.cpp \
    geometriesGL/src/comands/cmd_renderizargrid.cpp \
    geometriesGL/src/comands/cmd_renderizarlineas.cpp \
    geometriesGL/src/comands/cmd_renderizarpunto.cpp \
    geometriesGL/src/comands/compoundgeometry.cpp \
    geometriesGL/src/comands/drawableobject_child_line.cpp \
    geometriesGL/src/comands/drawableobject_cuadrado.cpp \
    geometriesGL/src/comands/drawableobject_grid.cpp \
    geometriesGL/src/comands/drawableobject_linea.cpp \
    geometriesGL/src/comands/drawableobject_parent_line.cpp \
    geometriesGL/src/comands/drawableobject_punto.cpp \
    geometriesGL/src/comands/geometry.cpp \
    geometriesGL/src/comands/resourcemanager.cpp \
    geometriesGL/src/comands/shader.cpp \
    geometriesGL/src/comands/spriterender.cpp \
    geometriesGL/src/comands/texture.cpp \
    linea.cpp \
    main.cpp \
    mainwindow.cpp \
    measurewidget.cpp \
    planotrazado.cpp \
    punto.cpp \
    renderfigures.cpp \
    triangulo.cpp \
    trianguloprimitivo.cpp \
    widgettrazado.cpp \
    windowwidget.cpp

HEADERS += \
    dialog_createfigures.h \
    externshader.h \
    form_measures.h \
    formdrawable.h \
    geometriesGL/res/LineSegment.h \
    geometriesGL/res/Polyline2D.h \
    geometriesGL/res/Vec2.h \
    geometriesGL/res/focmaths.h \
    geometriesGL/res/purebaClase.h \
    geometriesGL/src/VentanaPrincipal/customgrip.h \
    geometriesGL/src/VentanaPrincipal/interface_modulos.h \
    geometriesGL/src/VentanaPrincipal/mainsimplewindow.h \
    geometriesGL/src/VentanaPrincipal/mainwindow.h \
    geometriesGL/src/VentanaPrincipal/settings.h \
    geometriesGL/src/actions/actionsPrueba.h \
    geometriesGL/src/actions/camera2d.h \
    geometriesGL/src/actions/interactivefigure.h \
    geometriesGL/src/comands/cmd_renderizargrid.h \
    geometriesGL/src/comands/cmd_renderizarlineas.h \
    geometriesGL/src/comands/cmd_renderizarpunto.h \
    geometriesGL/src/comands/compoundgeometry.h \
    geometriesGL/src/comands/drawableobject_child_line.h \
    geometriesGL/src/comands/drawableobject_cuadrado.h \
    geometriesGL/src/comands/drawableobject_grid.h \
    geometriesGL/src/comands/drawableobject_linea.h \
    geometriesGL/src/comands/drawableobject_parent_line.h \
    geometriesGL/src/comands/drawableobject_punto.h \
    geometriesGL/src/comands/geometry.h \
    geometriesGL/src/comands/resourcemanager.h \
    geometriesGL/src/comands/shader.h \
    geometriesGL/src/comands/spriterender.h \
    geometriesGL/src/comands/texture.h \
    geometriesGL/src/forms/formsPrueba.h \
    linea.h \
    mainwindow.h \
    measurewidget.h \
    planotrazado.h \
    punto.h \
    renderfigures.h \
    triangulo.h \
    trianguloprimitivo.h \
    widgettrazado.h \
    windowwidget.h

FORMS += \
    dialog_createfigures.ui \
    form_measures.ui \
    formdrawable.ui \
    geometriesGL/src/VentanaPrincipal/main.ui \
    geometriesGL/src/VentanaPrincipal/mainwindow.ui \
    mainwindow.ui \
    windowwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    geometriesGL/res/Nuevo documento de texto.txt \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-3d.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-4k.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-account-logout.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-action-redo.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-action-undo.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-airplane-mode-off.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-airplane-mode.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-alarm.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-align-center.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-align-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-align-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-bottom-2.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-bottom.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-circle-bottom.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-circle-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-circle-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-circle-top.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-arrow-top.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-at.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-av-timer.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-ban.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-battery-0.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-battery-3.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-battery-5.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-battery-alert.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-battery-slash.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-bell.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-bluetooth.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-briefcase.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-browser.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-calendar-check.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-camera-roll.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-camera.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-caret-bottom.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-caret-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-caret-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-caret-top.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cart.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cast.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chart-line.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chart-pie.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chart.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chat-bubble.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-check-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-check-circle.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-check.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-bottom.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-circle-down-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-circle-left-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-circle-right-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-circle-up-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-double-down.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-double-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-double-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-double-up-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-double-up.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-chevron-top.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-circle.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-clipboard.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-clock.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-clone.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-closed-captioning.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cloud-download.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cloud-upload.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cloudy.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-code.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-coffee.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-comment-bubble.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-comment-square.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-credit-card.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cursor-move.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cursor.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-cut.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-data-transfer-down.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-data-transfer-up.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-deaf.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-description.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-devices.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-dialpad.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-dog.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-door.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-double-quote-sans-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-double-quote-sans-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-drop.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-envelope-closed.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-envelope-letter.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-envelope-open.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-equalizer.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-ethernet.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-exit-to-app.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-expand-down.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-expand-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-expand-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-expand-up.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-exposure.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-external-link.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-face-dead.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-featured-playlist.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-file.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-find-in-page.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-fingerprint.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-fire.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-flip-to-back.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-folder-open.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-folder.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-frown.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-gamepad.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-hand-point-down.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-hand-point-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-hand-point-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-hand-point-up.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-hd.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-hdr.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-headphones.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-heart.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-highligt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-history.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-home.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-house.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-image-plus.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-image1.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-infinity.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-input-power.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-input.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-justify-center.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-justify-left.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-justify-right.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-keyboard.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-laptop.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-layers.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-level-down.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-level-up.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-library-add.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-library.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-lightbulb.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-link-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-link-broken.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-link.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-location-pin.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-lock-locked.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-lock-unlocked.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-loop-1.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-loop-circular.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-loop.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-low-vision.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-magnifying-glass.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-map.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-eject.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-pause.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-play.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-skip-backward.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-skip-forward.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-step-backward.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-step-forward.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-media-stop.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-medical-cross.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-meh.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-menu.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-microphone.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-minus.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mobile-landscape.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mobile.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mood-bad.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mood-good.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mood-very-bad.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mood-very-good.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-moon.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mouse.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-move.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-movie.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mug-tea.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-mug.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-notes.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-options-horizontal.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-options.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-paint-bucket.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-paper-plane.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-paperclip.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-paragraph.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-pen-alt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-pencil.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-people.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-phone.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-pin.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-plus.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-power-standby.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-print.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-rectangle.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-reload.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-remove.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-rss.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-satelite.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-save.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-screen-desktop.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-screen-smartphone.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-settings.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-share-boxed.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-share.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-signal-cellular-0.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-signal-cellular-3.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-size-grip.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-smile.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-speaker.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-speech.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-speedometer.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-star.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-tags.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-task.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-terminal.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-text-size.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-text-square.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-text.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-thumb-down.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-thumb-up.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-transfer.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-triangle.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-truck.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-user-female.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-user-follow.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-user-unfollow.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-user.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-vertical-align-bottom.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-view-column.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-view-module.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-view-quilt.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-view-stream.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-voice-over-record.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-volume-high.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-volume-low.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-volume-off.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-wallet.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-watch.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-wifi-signal-0.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-wifi-signal-1.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-wifi-signal-2.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-wifi-signal-4.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-wifi-signal-off.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-window-maximize.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-window-minimize.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-window-restore.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-wrap-text.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-x-circle.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-x.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-zoom-in.png \
    geometriesGL/src/VentanaPrincipal/images/icons/cil-zoom-out.png \
    geometriesGL/src/VentanaPrincipal/images/icons/icon_close.png \
    geometriesGL/src/VentanaPrincipal/images/icons/icon_maximize.png \
    geometriesGL/src/VentanaPrincipal/images/icons/icon_menu.png \
    geometriesGL/src/VentanaPrincipal/images/icons/icon_minimize.png \
    geometriesGL/src/VentanaPrincipal/images/icons/icon_restore.png \
    geometriesGL/src/VentanaPrincipal/images/icons/icon_settings.png \
    geometriesGL/src/VentanaPrincipal/images/images/PyDracula.png \
    geometriesGL/src/VentanaPrincipal/images/images/PyDracula_horizontal.png \
    geometriesGL/src/VentanaPrincipal/images/images/PyDracula_vertical.png \
    geometriesGL/src/VentanaPrincipal/themes/defaultDarkThemeGabo.qss \
    geometriesGL/src/VentanaPrincipal/themes/py_dracula_dark.qss \
    geometriesGL/src/VentanaPrincipal/themes/py_dracula_light.qss \
    shaders/fragmentShader.fs \
    shaders/fragmentShader_spriteRender.frag \
    shaders/vertexShader.vs \
    shaders/vertexShader_spriteRender.vert

SUBDIRS += \
    geometriesGL/src/VentanaPrincipal/VentanaPrincipal.pro

RESOURCES += \
    geometriesGL/src/VentanaPrincipal/resources.qrc
