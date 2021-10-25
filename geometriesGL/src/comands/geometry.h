#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "texture.h"
#include "spriterender.h"

using namespace std;

class Geometry
{
public:
    //METODOS DE ARBOL
    Geometry();
    Geometry(string nombreGeometry);

    void    setParentPtr(Geometry* parent)
            { this->ptr_parent_ = parent; }

    Geometry *getParentPtr() const
            { return this->ptr_parent_; }

    virtual ~Geometry();
    virtual bool isComposite() const  { return false; }

    //GESTION DE HIJOS
    virtual void add_Componente_Geometry(Geometry* ){}
    virtual void delete_Componente_Geometry(Geometry* ){}

    //FUNCIONES DE DIBUJO
    virtual void draw_Componente_Geometry(){}

    //GETTERS AND SETTERS ATRIBUTOS DE HIJOS
    virtual Geometry *getChhilGeometry(int){return nullptr;};

protected:
    Geometry* ptr_parent_;

    string nombreGeometry;
};

#endif // GEOMETRY_H
