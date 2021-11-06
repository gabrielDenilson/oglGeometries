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

public:

    DrawableObject_Grid();
    DrawableObject_Grid(Shader &shaderProgram,
                        Texture &textura,
                        glm::vec3 color);

    ~DrawableObject_Grid();

    bool isComposite() const override{ return false; }

    //!DRAW FUNCTIONS
    void draw_Componente_Geometry() override;

    //!GETTERS AND SETTERS DE HIJO
    void setShader(const Shader &shaderProgram) override;
    void setTexture(Texture *textureProgram) override;
    void setCamera(Camera2D *viewMatrix) override;

    void setShaderNormal(const Shader *shaderProgram);
    void setTextureNormal(Texture &textureProgram);
    //RENDER FUNCTIONS
    void setColorGrid(glm::vec3 color);

    void setMVP(const glm::mat4 &MVP);
};


#endif // DRAWABLEOBJECT_GRID_H
