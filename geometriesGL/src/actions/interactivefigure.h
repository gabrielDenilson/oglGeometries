#ifndef INTERACTIVEFIGURE_H
#define INTERACTIVEFIGURE_H

#include <QOpenGLWidget>

#include "geometriesGL/src/comands/geometry.h"
#include "geometriesGL/src/comands/compoundgeometry.h"
#include "geometriesGL/src/comands/drawableobject_linea.h"
#include "geometriesGL/src/comands/drawableobject_parent_line.h"
#include "geometriesGL/src/comands/drawableobject_child_line.h"
#include "geometriesGL/src/comands/drawableobject_punto.h"
#include "geometriesGL/src/comands/drawableobject_grid.h"

//#include "widgettrazado.h"

enum TIPO{
    LINEA_SIMPLE,
    LINEA_PADRE,
    LINEA_HIJA,
    CUADRADO,
    MOVE_SCENE
};


class InteractiveFigure
{
public:
    CompoundGeometry *groupShapes;

private:

    vector <DrawableObject_Linea*> lineStore;
    vector <DrawableObject_Parent_Line*> parentLineStore;
    vector <DrawableObject_Child_Line*> childLineStore;
    vector <DrawableObject_Punto*> puntoStore;
    int contadorLineaStore = 0;
    int contadorParentLineaStore = 0;
    int contadorChildLineaStore = 0;
    int contadorPuntoStore = 0;

    Shader shaderDefault;
    Texture textureDefault;
    Camera2D *camaraDefault;

    DrawableObject_Grid *plano2D;
    Geometry *lastLineaSimple;
    Geometry *lastLineaPadre;
    Geometry *lastLineaHija;

public:
    InteractiveFigure();

    void init_interactive_figure();

    void set_camera_group(Camera2D *camaraGrupo);

    void draw_group_Figures(QWidget *parent);

    void DrawObject(TIPO tipoDibujo, QOpenGLWidget *parent);

    void receiveFirstPoint(Punto *puntoInicial, QWidget *parent);
    void receiveLastPoint(Punto *puntoFinal, QWidget *parent);

    //ALMACENAMIENTO DE MEMORIA
    void create_buffer_lines(int linesSize);
    void copy_line_pointer_to_group();//se copia del almacen al grupo figuras, se aumenta el contador a 1

    void create_buffer_parent_lines(int linesSize);
    void copy_parent_line_pointer_to_group();

    void create_buffer_child_lines(int linesSize);
    void copy_child_line_pointer_to_group();

    void create_buffer_points(int linesSize);
    void copy_points_to_group();
};

#endif // INTERACTIVEFIGURE_H
