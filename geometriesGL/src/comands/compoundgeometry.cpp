#include "compoundgeometry.h"

#include <algorithm>

CompoundGeometry::CompoundGeometry()
{
    this->nombreGeometry = "Name_G_Compound";
}

CompoundGeometry::CompoundGeometry(string nombreCompoundGeometry)
{
    this->nombreGeometry = nombreCompoundGeometry;
}

CompoundGeometry::~CompoundGeometry()
{

}

void CompoundGeometry::add_Componente_Geometry(Geometry *nuevoGeometryPtr)
{
    lista_Componentes_Geometry.push_back(nuevoGeometryPtr);

    nuevoGeometryPtr->setParentPtr(this);
}

void CompoundGeometry::delete_Componente_Geometry(Geometry *eliminarGeometryPtr)
{
    lista_Componentes_Geometry.erase(std::remove(lista_Componentes_Geometry.begin(), lista_Componentes_Geometry.end(), eliminarGeometryPtr), lista_Componentes_Geometry.end());

    eliminarGeometryPtr ->setParentPtr(nullptr);
}

void CompoundGeometry::draw_Componente_Geometry(Geometry *renderer)
{
    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
        iterador != lista_Componentes_Geometry.end();
        ++iterador)
    {
        if(*iterador != 0){
            (*iterador) -> draw_Componente_Geometry(renderer);
        }
    }
}

void CompoundGeometry::draw_Componente_Geometry()
{
    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
        iterador != lista_Componentes_Geometry.end();
        ++iterador)
    {
        if(*iterador != 0){
            (*iterador) -> draw_Componente_Geometry();
        }
    }
}

void CompoundGeometry::draw_intern_Sprite(Texture &texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{
    for(vector<Geometry*>::const_iterator iterador = lista_Componentes_Geometry.begin();
        iterador != lista_Componentes_Geometry.end();
        ++iterador)
    {
        if(*iterador != 0){
            (*iterador) -> draw_intern_Sprite(texture,
                                              position,
                                              size,
                                              rotate,
                                              color);
        }
    }
}

