#ifndef CUSTOMGRIP_H
#define CUSTOMGRIP_H

#include <QWidget>
#include "mainwindow.h"

class CustomGrip : public QWidget
{
public:
    CustomGrip(MainWindow *self, QWidget *parent = 0, Qt::Edge = Qt::Edge::LeftEdge , bool disable_color = false);

    void resize_top(MainWindow *self, QMouseEvent *event);

    void resize_bottom(MainWindow *self, QMouseEvent *event);

    void resize_left(MainWindow *self, QMouseEvent *event);

    void resize_right(MainWindow *self, QMouseEvent *event);

};

#endif // CUSTOMGRIP_H
