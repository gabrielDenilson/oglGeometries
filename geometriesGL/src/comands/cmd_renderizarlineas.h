#ifndef CMD_RENDERIZARLINEAS_H
#define CMD_RENDERIZARLINEAS_H

#include "geometry.h"
#include "shader.h"
#include "texture.h"

#include <QOpenGLExtraFunctions>

class cmd_renderizarLineas : public Geometry, protected QOpenGLExtraFunctions
{
public:
    cmd_renderizarLineas();

    cmd_renderizarLineas(string nombreLinea);

    //Constructor para inicializar los archivos
    cmd_renderizarLineas(Shader &shader);

    virtual ~cmd_renderizarLineas();

    virtual bool isComposite() const override {return false;}

    void add_Componente_Geometry(Geometry*) override;
    void delete_Componente_Geometry(Geometry *) override;

    void draw_Componente_Geometry(Geometry *) override;
    void draw_Componente_Geometry() override;
    void draw_intern_Sprite(Texture  &texture,
                            glm::vec2 position,
                            glm::vec2 size = glm :: vec2(10.0f, 10.0f),
                            float     rotate = 0.0f,
                            glm::vec3 color = glm::vec3(1.0f)) override;

private:

    Shader shader_Renderiza_Linea;
    unsigned int cuadradoVAO;

    void initRenderData();

};

#endif // CMD_RENDERIZARLINEAS_H
