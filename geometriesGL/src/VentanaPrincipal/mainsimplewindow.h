#ifndef MAINSIMPLEWINDOW_H
#define MAINSIMPLEWINDOW_H

#include <QMainWindow>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui{
    class SimpleMainWindow;
}

QT_END_NAMESPACE


class MainSimpleWindow : public QMainWindow
{
        Q_OBJECT
public:
    QWidget *parent;
private:
    Ui::SimpleMainWindow *ui;

public:
    MainSimpleWindow(QWidget *parent = nullptr);
    ~MainSimpleWindow();

    void toggleLeftBox(QWidget *parent, QEvent *event);
    void start_box_animation(QWidget *parent, int left_box_width, int right_box_width, string direction);

signals:
    void close();

public slots:

};

#endif // MAINSIMPLEWINDOW_H
