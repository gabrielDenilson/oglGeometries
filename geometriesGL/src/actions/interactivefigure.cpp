#include "interactivefigure.h"

#include <QDebug>
#include "geometriesGL/src/comands/resourcemanager.h"

InteractiveFigure::InteractiveFigure()
//    groupShapes (new CompoundGeometry)
//  , plano2D (new DrawableObject_Grid)
{
    //Constructor de clase
}

float Y2 = 100.0;

void InteractiveFigure::init_interactive_figure()
{

    ResourceManager::LoadShader("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/repositorios/oglGeometries/shaders/vertexShader_spriteRender.vert",
                                "C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/repositorios/oglGeometries/shaders/fragmentShader_spriteRender.frag",
                                nullptr,
                                "sprite");
    ResourceManager::LoadTexture("nofile", true, "cara");
    this->shaderDefault = ResourceManager::GetShader("sprite");
    this->textureDefault = ResourceManager::GetTexture("cara");

    groupShapes = new CompoundGeometry();
    //AGREGA EL SHADER AL GRUPO DE FIGURAS
    //AGREGA LA REJILLA DEL PLANO 2D

    plano2D = new DrawableObject_Grid();

    this->create_buffer_lines(10);
    this->create_buffer_parent_lines(10);
    this->create_buffer_child_lines(10);
    this->create_buffer_points(10);

    this->groupShapes->add_Componente_Geometry(this->plano2D);

    this->groupShapes->setShader(ResourceManager::GetShader("sprite"));

    qDebug() << "Elementos: " << this->groupShapes->get_compound_size();
}

void InteractiveFigure::set_camera_group(Camera2D *camaraGrupo)
{
    this->camaraDefault = camaraGrupo;
    this->groupShapes->setCamera(camaraDefault);
}

void InteractiveFigure::draw_group_Figures(QWidget *parent)
{
    //DIBUJA TODAS LAS FIGURAS EN GROUPSHAPE
    this->groupShapes->draw_Componente_Geometry(parent);
    parent->update();
}

void InteractiveFigure::DrawObject(TIPO tipoDibujo, QOpenGLWidget *parent)
{
    if(tipoDibujo == LINEA_SIMPLE){

        qDebug() << "se creo LINEA SIMPLE";
        //CREA UNA NUEVO PUNTERO LINEA;
        copy_line_pointer_to_group();
    } else
    if(tipoDibujo == LINEA_PADRE){
        //CREA UNA LINEA PADRE
        copy_parent_line_pointer_to_group();
        qDebug() << "se creo LINEA PADRE";
    } else
    if(tipoDibujo == LINEA_HIJA){
        //CREA UNA LINEA PADRE
        copy_child_line_pointer_to_group();
        qDebug() << "se creo LINEA HIJA";
    } else
    if(tipoDibujo == CUADRADO){
        copy_points_to_group();
        qDebug() << "se creo CUADRADO";
    }
    qDebug() << "Elementos: " << this->groupShapes->get_compound_size();
}

void InteractiveFigure::receiveFirstPoint(Punto *puntoInicial, QWidget *parent)
{
    qDebug() << " Se COMIENZA el dibujo";

    lastLineaSimple->setStartPoint(puntoInicial, nullptr, parent);

    parent->update();
}

void InteractiveFigure::receiveLastPoint(Punto *puntoFinal, QWidget *parent)
{
    qDebug() << " Se TERMINA el dibujo";

    lastLineaSimple->setEndPoint(puntoFinal, nullptr, parent);

    parent->update();
}

void InteractiveFigure::doSelect(Punto *P)
{
    //get vector of points from groupShapes
//    points.push_back(Punto(-10, 10));
//    points.push_back(Punto(10, 10));
//    points.push_back(Punto(10, -10));
//    points.push_back(Punto(-10, -10));

        //check if P is in any of the points
        for(int i = 1; i < this->groupShapes->get_compound_size(); i++){
            qDebug() << groupShapes->get_compound_size() <<" ELEMENTOS GRUPO vuelta : "<<i;
            lastPunto = this->groupShapes->getChhilGeometry(i);


//            points = lastPunto->get_points_area();

            int loop = 1;
//            int loop = points.size() / 4;
            int a = 0, b = 1, c = 2, d = 3;
            for(int j = 0; j < loop; j++){

                std::vector<Punto> &points = lastPunto->get_points_area();
                qDebug() << points.size() <<" TAMAÑO PUNTOS";
                if(checkSelect(P, &points[a], &points[b], &points[c], &points[d])){
                    qDebug() << "Seleccionado: " << i;
                    lastPunto->setColorPunto(COLORG::RED);
                    break;
                } /*else { qDebug() << "no seleccionado"; }*/
//                a += 4;
//                b += 4;
//                c += 4;
//                d += 4;
            }
        }
}

bool InteractiveFigure::checkSelect(Punto *P, Punto *A, Punto *B, Punto *C, Punto *D)
{
    //Given the points A, B, C, D of a quad, determine if the point P is on the quad.
    //The quad is defined by the points A, B, C, D.
    //collision x-axis
    bool CollisionX = false;
    if (P->getX() >= A->getX() && P->getX() <= B->getX()) {
        CollisionX = true;
        qDebug() << " X SELECT";
    }
    else if (P->getX() >= D->getX() && P->getX() <= C->getX()) {
        CollisionX = true;
        qDebug() << " X SELECT";
    }
    //collision y-axis
    bool CollisionY = false;
    if (P->getY() >= C->getY() && P->getY() <= A->getY()) {
        CollisionY = true;
        qDebug() << " Y SELECT";
    }
    else if (P->getY() >= D->getY() && P->getY() <= B->getY()) {
        CollisionY = true;
        qDebug() << " Y SELECT";
    }
    //return
    if (CollisionX && CollisionY) {
        return true;
    }
    else {
        return false;
    }
}

void InteractiveFigure::create_buffer_lines(int linesSize)
{
    for(int i = 0; i < linesSize; i++){
        DrawableObject_Linea* ptrLinea;
        ptrLinea = new DrawableObject_Linea();
        lineStore.push_back(ptrLinea);
    }
}






//*********************************************************************
//*********************************************************************++
//**************** BUFFER FUNCTIONS   *********************************




void InteractiveFigure::copy_line_pointer_to_group()
{
    DrawableObject_Linea *newPtr = lineStore.at(contadorLineaStore); //start in 0
    newPtr->setShader(this->shaderDefault);
    groupShapes->add_Componente_Geometry(newPtr); // add to group of figures
    contadorLineaStore ++;

    lastLineaSimple = groupShapes->getLastChild();
}

void InteractiveFigure::create_buffer_parent_lines(int linesSize)
{
    for(int i = 0; i < linesSize; i++){
        DrawableObject_Parent_Line* ptrParentLinea;
        ptrParentLinea = new DrawableObject_Parent_Line();
        parentLineStore.push_back(ptrParentLinea);
    }
}

void InteractiveFigure::copy_parent_line_pointer_to_group()
{
    DrawableObject_Parent_Line *newPtr = parentLineStore.at(contadorParentLineaStore); //start in 0
    newPtr->setShader(this->shaderDefault);
    groupShapes->add_Componente_Geometry(newPtr); // add to group of figures
    contadorParentLineaStore ++;

    lastLineaSimple = groupShapes->getLastChild(); //pointer to last child
}

void InteractiveFigure::create_buffer_child_lines(int linesSize)
{
    for(int i = 0; i < linesSize; i++){
        DrawableObject_Child_Line* ptrParentLinea;
        ptrParentLinea = new DrawableObject_Child_Line();
        childLineStore.push_back(ptrParentLinea);
    }
}

void InteractiveFigure::copy_child_line_pointer_to_group()
{
    DrawableObject_Child_Line *newPtr = childLineStore.at(contadorChildLineaStore); //start in 0
    newPtr->setShader(this->shaderDefault);
    groupShapes->add_Componente_Geometry(newPtr); // add to group of figures
    contadorChildLineaStore ++;

    lastLineaSimple = groupShapes->getLastChild(); //pointer to last child
}

void InteractiveFigure::create_buffer_points(int linesSize)
{
    for(int i = 0; i < linesSize; i++){
        DrawableObject_Punto* ptrPunto;
        ptrPunto = new DrawableObject_Punto();
        puntoStore.push_back(ptrPunto);
    }
}

void InteractiveFigure::copy_points_to_group()
{
    DrawableObject_Punto *newPtr = puntoStore.at(contadorPuntoStore); //start in 0
    newPtr->setShader(this->shaderDefault);
    groupShapes->add_Componente_Geometry(newPtr); // add to group of figures
    contadorPuntoStore++;

    lastLineaSimple = groupShapes->getLastChild(); //pointer to last child
}
