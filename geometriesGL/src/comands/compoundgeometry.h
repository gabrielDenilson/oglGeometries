#ifndef COMPOUNDGEOMETRY_H
#define COMPOUNDGEOMETRY_H

#include "geometry.h"

#include <string>
#include <vector>

class CompoundGeometry : public Geometry
{
private:
    vector <Geometry*> lista_Componentes_Geometry;

public:
    CompoundGeometry();
    CompoundGeometry(string nombreCompoundGeometry);

    virtual ~CompoundGeometry();

    bool isComposite() const override { return true; }

    void add_Componente_Geometry(Geometry *nuevoGeometryPtr) override;
    void delete_Componente_Geometry(Geometry *eliminarGeometryPtr) override;

    void draw_Componente_Geometry(Geometry *) override;
    void draw_Componente_Geometry() override;
    void draw_intern_Sprite(Texture  &texture,
                            glm::vec2 position,
                            glm::vec2 size = glm :: vec2(10.0f, 10.0f),
                            float     rotate = 0.0f,
                            glm::vec3 color = glm::vec3(1.0f)) override;
};

#endif // COMPOUNDGEOMETRY_H
