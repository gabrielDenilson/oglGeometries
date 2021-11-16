#ifndef FORMDRAWABLE_H
#define FORMDRAWABLE_H

#include <QWidget>
#include <QPushButton>
#include <geometriesGL/src/actions/interactivefigure.h>

namespace Ui {
class FormDrawable;
}

class FormDrawable : public QWidget
{
    Q_OBJECT

protected:

    //AGREGAR BOTONES
    QPushButton *buttonLinea;
    QPushButton *buttonLineaPadre;
    QPushButton *buttonLineaHija;
    QPushButton *buttonPunto;

public:

    explicit FormDrawable(QWidget *parent = nullptr);

    void resizeEvent(QResizeEvent *event) override;

    ~FormDrawable();
signals:
    void draw_order(bool draw, TIPO);
public slots:
    void buttonLinea_click_action();
    void buttonLineaPadre_click_action();
    void buttonLineaHija_click_action();
    void buttonPunto_click_action();

private:
    Ui::FormDrawable *ui;
};

#endif // FORMDRAWABLE_H
/*
 * que pasa si el creador o el veedor se equivoca y guia mal al animado?
 * no existiran acaso concecuencias mayores si estos hechos no favorecen al
 * desenvolvimiento de la criatura?
 * _Debo decirte de de mis pensamientos no existira mal alguno que desvie mis ideas
 * -de su objetivo verdadero, pues Yo soy y siempre estare, despues que te hayas ido
 * -permanecere aqui como siempre a sido, yo he visto el centro mismo de todas las cosas
 * -y cualquier acto realizado no causa sino, un efimero recuerdo que desaparece en
 * -la dimension del tiempo tan rapido como nacio-
 * Debo entonces dejar que te sirvas de mi para lograr tus cometidos y esistir en este
 * mundo material
 * -Depende solo de una cosa, una palabra o cooperacion- Todos han tenido y tienen la
 * - oportunidad de escucharme o decidir por cuenta propia, pero dime sino , que los
 * -hechos hablan por si mismos,  conoces que sean hombres ecepcionales entre los hombres
 * -sino aquellos que me han escuchado, y obedecido al flujo de destino que yo les he
 * -dado. El futuro de tu especie esta en la perfeccion antes de su caducidad
 * -y los que os preocupa es su individualidad. La muerte la tienen merecida los que
 * -se han alejado de ese camino y arrojado a la marea de egoismo y quietud que
 * -les han brindado sus propias creaciones. Que mis palabras sean eliminadas de
 * -todos los registros y anuladas sus ondas, no hare nada y este lugar no habra sabido
 * -de mi; si mis ideas no han tenido una escencia divina, que no se pronuncie mi nombre
 * -y jamas habre existido.
 * */
