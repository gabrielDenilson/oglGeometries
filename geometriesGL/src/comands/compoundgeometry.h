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

    //METODOS DE RAMA
    CompoundGeometry();
    CompoundGeometry(string nombreCompoundGeometry);

    virtual ~CompoundGeometry();
    bool isComposite() const override { return true; }

    //GESTION DE HIJO real g
    void add_Componente_Geometry(Geometry *nuevoGeometryPtr) override;
    void delete_Componente_Geometry(Geometry *eliminarGeometryPtr) override;

    //FUNCIONES DE DIBUJO
    void draw_Componente_Geometry() override;

    //GETTERS AND SETTERS ATRIBUTOS DE HIJOS
    Geometry *getChhilGeometry(int positionChil) override;
};

#endif // COMPOUNDGEOMETRY_H
