#ifndef DIALOG_CREATEFIGURES_H
#define DIALOG_CREATEFIGURES_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class Dialog_CreateFigures;
}

class Dialog_CreateFigures : public QDialog
{
    Q_OBJECT
private:
    QTableWidget *table_measures;

public:
    explicit Dialog_CreateFigures(QWidget *parent = nullptr);
    ~Dialog_CreateFigures();

private:
    Ui::Dialog_CreateFigures *ui;

public slots:
    void insertRowMeasures(int arg1);
};

#endif // DIALOG_CREATEFIGURES_H
