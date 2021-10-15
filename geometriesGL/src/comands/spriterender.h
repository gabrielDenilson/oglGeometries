#ifndef SPRITERENDER_H
#define SPRITERENDER_H

#include <QOpenGLExtraFunctions>

#include "geometriesGL/src/comands/shader.h"
#include "geometriesGL/src/comands/texture.h"


class SpriteRender : protected QOpenGLExtraFunctions
{
public:
    //Constructor que incia con el Shader
    SpriteRender(Shader &shader);
    //Destructor que libera la memoria para la proxima renderizacion
    ~SpriteRender();
    //Renderiza una textura cuadrada con el sprite dado
    void DrawSprite(Texture   &texture,
                    glm::vec2  position,
                    glm::vec2  size = glm::vec2(10.0f, 10.0f),
                    float      rotate = 0.0f,
                    glm::vec3  color = glm::vec3(1.0f));

private:
    //Renderizar estado
    Shader shader;
    unsigned int cuadroVAO;

    //Inicializamos y configuraos el buffer y atributos de vertices del cuadrado
    void initRenderData();
};

#endif // SPRITERENDER_H
