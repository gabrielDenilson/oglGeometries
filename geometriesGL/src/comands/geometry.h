#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "texture.h"

using namespace std;

class Geometry
{
public:
    Geometry();
    Geometry(string nombreGeometry);

    virtual ~Geometry();
    virtual bool isComposite() const  { return false; }

    virtual void add_Componente_Geometry(Geometry* ){}
    virtual void delete_Componente_Geometry(Geometry* ){}

    virtual void draw_Componente_Geometry(Geometry* ){}
    virtual void draw_Componente_Geometry(){}
    virtual void draw_intern_Sprite(Texture  &texture,
                            glm::vec2 position,
                            glm::vec2 size = glm :: vec2(10.0f, 10.0f),
                            float     rotate = 0.0f,
                                    glm::vec3 color = glm::vec3(1.0f)){}


    void    setParentPtr(Geometry* parent){ this->ptr_parent_ = parent; }

    Geometry *getParentPtr() const        { return this->ptr_parent_; }


protected:
    Geometry* ptr_parent_;

    string nombreGeometry;
};

#endif // GEOMETRY_H
