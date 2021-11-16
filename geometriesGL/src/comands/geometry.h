#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QOpenGLWidget>

#include "shader.h"
#include "texture.h"

#include "geometriesGL/src/actions/camera2d.h"
#include "punto.h"

using namespace std;

class Geometry
{
protected:
    Geometry* ptr_parent_;

    string nombreGeometry;

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

    //!GESTION DE HIJOS
    virtual void add_Componente_Geometry(Geometry*){}
    virtual void delete_Componente_Geometry(Geometry* ){}

    //!FUNCIONES DE DIBUJO
    virtual void draw_Componente_Geometry(QWidget*){}

    //!GETTERS AND SETTERS ATRIBUTOS DE HIJOS
    virtual void setShader(const Shader &){}
    virtual void setTexture(Texture *){}
    virtual void setCamera(Camera2D *){}
    virtual void setStartPoint(Punto*, Geometry*, QWidget*){};
    virtual void setEndPoint(Punto*, Geometry*, QWidget*){};
    virtual Geometry *getChhilGeometry(int){return nullptr;};
};

#endif // GEOMETRY_H
