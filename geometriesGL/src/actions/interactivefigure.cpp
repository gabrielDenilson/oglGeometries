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
