#ifndef CUSTOMGRIP_H
#define CUSTOMGRIP_H

#include <QWidget>

#include "mainhome.h"

class CustomGrip : public QWidget
{
public:
    CustomGrip(MainHome *self, QWidget *parent = 0, Qt::Edge = Qt::Edge::LeftEdge , bool disable_color = false);

    void resize_top(MainHome *self, QMouseEvent *event);

    void resize_bottom(MainHome *self, QMouseEvent *event);

    void resize_left(MainHome *self, QMouseEvent *event);

    void resize_right(MainHome *self, QMouseEvent *event);

};

#endif // CUSTOMGRIP_H
