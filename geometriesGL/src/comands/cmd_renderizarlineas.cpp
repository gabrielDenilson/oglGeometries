#include "cmd_renderizarlineas.h"

#include <QOpenGLExtraFunctions>
#include <QWidget>
#include <QDebug>

#include <Polyline2D.h>

#include "linea.h"

using namespace crushedpixel;


cmd_renderizarLineas::cmd_renderizarLineas()
{
}

cmd_renderizarLineas::cmd_renderizarLineas(string nombreLinea)
{
    nombreCmd = nombreLinea;
}

cmd_renderizarLineas::cmd_renderizarLineas(Shader &shader, Texture& texture, glm::vec3 color) :

    lineaCords(0.0 , 0.0f, 0.0f, 0.0f),


    puntosCoord{  { 0.0f , 0.0f},
                  { 0.0f , 0.0f}
               },
    thick(0.1)
{
    initializeOpenGLFunctions();

    this->shader_Renderiza_Linea = shader;
    this->texture_Renderiza_Linea = texture;
    this->colorLinea = color;

    vertices = crushedpixel::Polyline2D::create(puntosCoord,
                                                thick,
                                                crushedpixel::Polyline2D::JointStyle::ROUND,
                                                crushedpixel::Polyline2D::EndCapStyle::ROUND);
    //Inicializa la memoria para una linea
    initBuffers();
    initOtherBuffers();
}

cmd_renderizarLineas::~cmd_renderizarLineas()
{

}

// Reescribe el objeto LineaCoords
void cmd_renderizarLineas::setLinea(Linea nuevaLinea)
{
    this->lineaCords = nuevaLinea;
}

void cmd_renderizarLineas::setColorLinea(glm::vec3 color)
{
    this->colorLinea = color;
}

void cmd_renderizarLineas::initBuffers()
{
    glGenVertexArrays(1, &this->lineaVAO);

    glBindVertexArray(lineaVAO);
        glGenBuffers(1, &lineaVBO);
        glBindBuffer(GL_ARRAY_BUFFER, lineaVBO);

            glBufferData(GL_ARRAY_BUFFER, sizeof(Linea), nullptr, GL_DYNAMIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof (float), (void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

GLsizei numPoints;
GLsizei numVertices;
void cmd_renderizarLineas::initOtherBuffers()
{
    glGenVertexArrays(1, &this->thickVAO);

    glBindVertexArray(this->thickVAO);
        glGenBuffers(1, &this->thickVBO);
        glBindBuffer(GL_ARRAY_BUFFER, this->thickVBO);

            numPoints = (GLsizei) puntosCoord.size();
            numVertices = (GLsizei) vertices.size();

            glBufferData(GL_ARRAY_BUFFER, sizeof(Vec2)*200, nullptr, GL_DYNAMIC_DRAW);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)(2 * sizeof(float)));
            glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void cmd_renderizarLineas::drawLinea()
{
    this->shader_Renderiza_Linea.Use();
    //Envia el sistema de coordenadas
    this->shader_Renderiza_Linea.SetMatrix4("model", this->model);
    //Enviamos el color
    this->shader_Renderiza_Linea.SetVector3f("spriteColor", this->colorLinea);

    glBindBuffer(GL_ARRAY_BUFFER, this->lineaVBO);
    //el tipo de memoria, offset = empieza en 0, tamaño de datos, datos
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Linea), &lineaCords );

    glBindVertexArray(this->lineaVAO);
    glDrawArrays(GL_LINES, 0, 2);

    glBindVertexArray(0);
    this->shader_Renderiza_Linea.release();
}

void cmd_renderizarLineas::drawOtherLinea(){
    this->shader_Renderiza_Linea.Use();

    this->shader_Renderiza_Linea.SetMatrix4("model", this->model);
    //Enviamos el color
    this->shader_Renderiza_Linea.SetVector3f("spriteColor", colorThick);

    glBindVertexArray(this->thickVAO);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDrawArrays(GL_TRIANGLES, 0, 200);
    glDisable(GL_BLEND);

    glBindVertexArray(0);
    this->shader_Renderiza_Linea.release();
}

void cmd_renderizarLineas::setShaderProgram(Shader &newShader)
{
    this->shader_Renderiza_Linea = newShader;
}

void cmd_renderizarLineas::setTextureProgram(Texture &newTexture)
{
    this->texture_Renderiza_Linea = newTexture;
}

void cmd_renderizarLineas::actualizarVBOlineas(QWidget* parent)
{
    glBindBuffer(GL_ARRAY_BUFFER, this->lineaVBO);
    //el tipo de memoria, offset = empieza en 0, tamaño de datos, datos
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Linea), &lineaCords );
    //Actualiza el Widget padre que instancia esta clase
    parent->update();
}

void cmd_renderizarLineas::actualizarVBOThick(QWidget *parent)
{
    glBindBuffer(GL_ARRAY_BUFFER, this->thickVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size()*sizeof(Vec2), vertices.data());

    parent->update();
}

//Setters of the render Line
void cmd_renderizarLineas::setPuntoInicial(Punto *puntoInicial, QWidget *parent)
{
    this->lineaCords.setPuntoInicial(puntoInicial);

    //actualizar padre Widget
    parent->update();
}

void cmd_renderizarLineas::setPuntoFinal(Punto *puntoFinal, QWidget *parent)
{
    this->lineaCords.setPuntoFinal(puntoFinal);
    this->actualizarVBOlineas(parent);
}


void cmd_renderizarLineas::setFirstPointThick(Punto *puntoInicial, QWidget *parent)
{
    this->puntosCoord.clear();
    this->puntosCoord.push_back({puntoInicial->getX(), puntoInicial->getY()});
    // actualizar widget padre
    parent->update();
}

void cmd_renderizarLineas::setLastPointThick(Punto *puntoFinal, QWidget *parent)
{
    //Enviamos el ultima punto a thick points
    if(puntosCoord.size() <= 1){
        this->puntosCoord.push_back({puntoFinal->getX(), puntoFinal->getY()});
    } else {
        this->puntosCoord.at(1).x = puntoFinal->getX();
        this->puntosCoord.at(1).y = puntoFinal->getY();
    }
    //Creamos los vertices de thick line
    this->vertices = crushedpixel::Polyline2D::create(puntosCoord,
                                                      thick,
                                                      crushedpixel::Polyline2D::JointStyle::ROUND,
                                                      crushedpixel::Polyline2D::EndCapStyle::ROUND);
    //Actualizamos la memoria VBO
    this->actualizarVBOThick(parent);
}

float cmd_renderizarLineas::getThick() const
{
    return thick;
}

void cmd_renderizarLineas::setThick(float value)
{
    thick = value;
}

void cmd_renderizarLineas::setColorThick(glm::vec3 color)
{
    colorThick = color;
}


void cmd_renderizarLineas::drawTransforamtions(glm::vec2 position, glm::vec2 size, float rotate)
{

    //Preparamos transformaciones
    this->shader_Renderiza_Linea.Use();
    //Transformaciones: 1.Scale 2.Rotacion 3. Traslacion
    //se aplica en orden reverso
    //......traslacion
    model = glm::translate(model, glm::vec3(position, 0.0f));

    //.......mover el origen de rotacion al centro del cuatrado
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    //...... Rotacion
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    //.......mover al origen hacia atras
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
    //......ultima Escala
    model = glm::scale(model, glm::vec3(size, 0.0f));

    this->shader_Renderiza_Linea.SetMatrix4("model", model);

    //Renderizar Texturas del cuadrado
//    this->shader_Renderiza_Linea.SetVector3f("spriteColor", color);

//    glActiveTexture(GL_TEXTURE0);
//    texture.Bind();

    //Renderizamos
    glBindVertexArray(this->lineaVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
