#ifndef DRAWABLEOBJECT_GRID_H
#define DRAWABLEOBJECT_GRID_H

#include <QOpenGLExtraFunctions>

#include "geometry.h"
#include "shader.h"
#include "texture.h"
#include "cmd_renderizargrid.h"

class DrawableObject_Grid : public Geometry, protected QOpenGLExtraFunctions
{
private:
    cmd_renderizarGrid *grid;
public:
    glm::vec3 Color;
    //Estado de renderizacion
    Shader shaderProgram;
    Texture Sprite;

    bool transformar;

    DrawableObject_Grid();
    DrawableObject_Grid(Shader &shaderProgram,
                        Texture &textura,
                        glm::vec3 color);

    ~DrawableObject_Grid();

    bool isComposite() const override{ return false; }

    //DRAW FUNCTIONS
    void draw_Componente_Geometry() override;

    //RENDER FUNCTIONS
    void setColorGrid(glm::vec3 color);

    void setMVP(const glm::mat4 &model,
                const glm::mat4 &view,
                const glm::mat4 &projection);
};


#endif // DRAWABLEOBJECT_GRID_H
