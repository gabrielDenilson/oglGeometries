#ifndef WINDOWWIDGET_H
#define WINDOWWIDGET_H

#include <QWidget>

namespace Ui {
class windowWidget;
}

class windowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit windowWidget(QWidget *parent = nullptr);
    ~windowWidget();

private:
    Ui::windowWidget *ui;
};

#endif // WINDOWWIDGET_H
