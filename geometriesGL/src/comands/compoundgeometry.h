#ifndef COMPOUNDGEOMETRY_H
#define COMPOUNDGEOMETRY_H

#include "geometry.h"
#include "geometriesGL/src/actions/camera2d.h"


#include <string>
#include <vector>

class CompoundGeometry : public Geometry
{
private:
    vector <Geometry*> lista_Componentes_Geometry;

public:

    //METODOS DE RAMA
    CompoundGeometry();
    CompoundGeometry(string nombreCompoundGeometry);

    void update_compound();
    int get_compound_size();

    virtual ~CompoundGeometry();
    bool isComposite() const override { return true; }

    //!GESTION DE HIJO real g
    void add_Componente_Geometry(Geometry *nuevoGeometryPtr) override;
    void delete_Componente_Geometry(Geometry *eliminarGeometryPtr) override;

    Geometry *getLastChild();

    //!FUNCIONES DE DIBUJO
    void draw_Componente_Geometry(QWidget *parent) override;

    //!GETTERS AND SETTERS ATRIBUTOS DE HIJOS
    void setShader(const Shader &shaderCompound) override;
    void setTexture(Texture *textureCompound) override;
    void setCamera(Camera2D *camera)override;
    void setStartPoint(Punto *firstPoint, Geometry *child, QWidget *parent) override;
    void setEndPoint(Punto *lastPoint, Geometry *child, QWidget *parent) override;
    Geometry *getChhilGeometry(int positionChil) override;
//    vector<Punto> get_points_area() override;
    Geometry *getChildGeometry(Geometry *geometryPointer);
    void setColorPunto(glm::vec3) override;
};

#endif // COMPOUNDGEOMETRY_H
