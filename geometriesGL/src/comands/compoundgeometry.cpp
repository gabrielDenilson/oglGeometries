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


//Revisar esta linea si no funciona el get Child Geometry
Geometry *CompoundGeometry::getChhilGeometry(int positionChild)
{
    return this->lista_Componentes_Geometry.at(positionChild);
}

