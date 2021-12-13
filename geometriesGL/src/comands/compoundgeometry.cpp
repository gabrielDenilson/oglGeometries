#include "compoundgeometry.h"

#include <algorithm>

CompoundGeometry::CompoundGeometry()
{
    this->nombreGeometry = "Name_G_Compound";
//    lista_Componentes_Geometry.reserve(100);
}

CompoundGeometry::CompoundGeometry(string nombreCompoundGeometry)
{
    this->nombreGeometry = nombreCompoundGeometry;
//    lista_Componentes_Geometry.reserve(100);
}

void CompoundGeometry::update_compound()
{

}

int CompoundGeometry::get_compound_size()
{
    return lista_Componentes_Geometry.size();
}

CompoundGeometry::~CompoundGeometry()
{

}

void CompoundGeometry::add_Componente_Geometry(Geometry *nuevoGeometryPtr)
{
//    Geometry *ptrNuevo;
    lista_Componentes_Geometry.push_back(nuevoGeometryPtr);
//    lista_Componentes_Geometry.insert();
    nuevoGeometryPtr->setParentPtr(this);
//    this->draw_Componente_Geometry(parent);
//    parent->pain
}

void CompoundGeometry::delete_Componente_Geometry(Geometry *eliminarGeometryPtr)
{
    lista_Componentes_Geometry.erase(std::remove(lista_Componentes_Geometry.begin(), lista_Componentes_Geometry.end(), eliminarGeometryPtr), lista_Componentes_Geometry.end());

    eliminarGeometryPtr ->setParentPtr(nullptr);
}

Geometry *CompoundGeometry::getLastChild()
{
    return lista_Componentes_Geometry.back();
}

void CompoundGeometry::draw_Componente_Geometry(QWidget *parent)
{
    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
        iterador != lista_Componentes_Geometry.end();
        ++iterador)
    {
        if(*iterador != 0){
            (*iterador) -> draw_Componente_Geometry(parent);
        }
    }
}

void CompoundGeometry::setShader(const Shader &shaderCompound){
    //set The Shader to all childs of lista_Componentes_Geometry
    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
        iterador != lista_Componentes_Geometry.end();
        ++iterador)
    {
        if(*iterador != 0){
            (*iterador) -> setShader(shaderCompound);
        }
    }
}


void CompoundGeometry::setTexture(Texture *textureCompound){
    //set The Texture to all childs of lista_Componentes_Geometry
    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
        iterador != lista_Componentes_Geometry.end();
        ++iterador)
    {
        if(*iterador != 0){
            (*iterador) -> setTexture(textureCompound);
        }
    }
}

void CompoundGeometry::setCamera(Camera2D *camera)
{
    //set The Camera to all childs of lista_Componentes_Geometry
        for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
            iterador != lista_Componentes_Geometry.end();
            ++iterador)
        {
            if(*iterador != 0){
                (*iterador) -> setCamera(camera);
            }
        }
}

void CompoundGeometry::setStartPoint(Punto *firstPoint, Geometry *child, QWidget *parent)
{
    //find in the vector lista_Componentes_Geometry the child
//    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
//        iterador != lista_Componentes_Geometry.end();
//        ++iterador)
//    {
//        if(*iterador == child){
//            child->setEndPoint(lastPoint, nullptr, parent);
//        }
//    }
}

void CompoundGeometry::setEndPoint(Punto *lastPoint, Geometry *child,  QWidget *parent)
{

}


//Revisar esta linea si no funciona el get Child Geometry
Geometry *CompoundGeometry::getChhilGeometry(int positionChild)
{
    return this->lista_Componentes_Geometry.at(positionChild);
}

void CompoundGeometry::setColorPunto(glm::vec3)
{

}

//Geometry *CompoundGeometry::getChildGeometry(Geometry *geometryPointer)
//{
//    Geometry
//    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
//        iterador != lista_Componentes_Geometry.end();
//        ++iterador)
//    {
//        if(*iterador == geometryPointer){
//            child->setEndPoint(lastPoint, nullptr, parent);
//        }
//    }

//    return
//}

