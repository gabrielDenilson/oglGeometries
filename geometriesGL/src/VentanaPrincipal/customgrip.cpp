#include "customgrip.h"
# include <QMouseEvent>

CustomGrip::CustomGrip(MainWindow *self, QWidget *parent, Qt::Edge, bool disable_color)
{

}

void CustomGrip::resize_top(MainWindow *self, QMouseEvent *event)
{
    int height = max(self->parent->minimumHeight(), self->parent->height() - event->y());
    QRect geo = self->geometry();
    geo.setTop(geo.bottom() - height);
    self->parent->setGeometry(geo);
    event->accept();
}

void CustomGrip::resize_bottom(MainWindow *self, QMouseEvent *event)
{
    int height = max(self->parent->minimumHeight(), self->height() - event->x());
    self->parent->resize(self->parent->width(), height);
    event->accept();
}

void CustomGrip::resize_left(MainWindow *self, QMouseEvent *event)
{
    int width = max(self->parent->minimumHeight(), self->parent->width() - event->x());
    QRect geo = self->geometry();
    geo.setLeft(geo.right() - width);
    self->parent->setGeometry(geo);
    event->accept();
}

void CustomGrip::resize_right(MainWindow *self, QMouseEvent *event)
{
    int width = max(self->parent->minimumHeight(), self->width() - event->x());
    self->parent->resize(width, self->parent->height());
    event->accept();
}