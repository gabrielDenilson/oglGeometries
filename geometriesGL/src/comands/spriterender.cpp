#include "spriterender.h"
#include "resourcemanager.h"

#include <QOpenGLExtraFunctions>


SpriteRender::SpriteRender(Shader &shader)
{
    initializeOpenGLFunctions();

    this->shader = shader;
    this->initRenderData();
}

SpriteRender::~SpriteRender()
{

}

void SpriteRender::DrawSprite(Texture &texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{
    //Preparamos transformaciones
    this->shader.Use();
    glm::mat4 model = glm::mat4(1.0);
    //Transformaciones: 1.Scale 2.Rotacion 3. Traslacion
    //se aplica en orden reverso
    //......traslacion
    model = glm::translate(model, glm::vec3(position, 0.0f));

    //.......mover el origen de rotacion al centro del cuatrado
    //model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    //...... Rotacion
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    //.......mover al origen hacia atras
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
    //......ultima Escala
    model = glm::scale(model, glm::vec3(size, 0.0f));

    this->shader.SetMatrix4("model", model);

    //Renderizar Texturas del cuadrado
    this->shader.SetVector3f("spriteColor", color);

//    glActiveTexture(GL_TEXTURE0);
//    texture.Bind();

    //Renderizamos
    glBindVertexArray(this->cuadroVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRender::initRenderData()
{
    //incilizamos las funciones de openGL
    initializeOpenGLFunctions();
    //configurar VAO/VBO
    unsigned int VBO;
    float vertices[] = {
        //posicion  textura
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->cuadroVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this-> cuadroVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
