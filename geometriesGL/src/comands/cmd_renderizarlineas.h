#ifndef CMD_RENDERIZARLINEAS_H
#define CMD_RENDERIZARLINEAS_H

#include <QOpenGLExtraFunctions>
#include <geometriesGL/res/Polyline2D.h>
#include <geometriesGL/res/Vec2.h>

#include "geometry.h"
#include "shader.h"
#include "texture.h"

#include "linea.h"
#include "punto.h"

using namespace crushedpixel;

class cmd_renderizarLineas : protected QOpenGLExtraFunctions
{
public:
    Linea lineaCords; //atributo publico para usar con los eventos y hacer el rendrizado mas facil.

private:
    //!Atributos de renderizado
    unsigned int lineaVAO; //!Memoria vertex GL
    unsigned int lineaVBO; //!Memoria buffer GL

    unsigned int thickVAO; //!Memoria vertex GL
    unsigned int thickVBO; //!Memoria buffer GL


    //!Atributos de linea
    glm::mat4 m_MVP         = glm::mat4(1.0f);


    Shader shader_Renderiza_Linea; //!Shader Program liena GL
    Texture *texture_Renderiza_Linea; //!Texture file linea GL

    glm::vec3 colorLinea; //! Color vertex Linea
    glm::vec3 colorThick; //! Color vertex Linea


    std::vector<crushedpixel::Vec2> vertices; //!Coordenada de Grosor
    std::vector<crushedpixel::Vec2> puntosCoord; //!Coordenadas de Linea
    crushedpixel::Polyline2D::EndCapStyle END_LINE;

    float thick; //!Tamaño de grosor Linea
    string nombreCmd; //!Nombre de comando

public:
    cmd_renderizarLineas(); //Constructor vacio
    cmd_renderizarLineas(string nombreLinea); // Constructor vacio String Nombre
    cmd_renderizarLineas(Shader &shader, Texture &texture, glm::vec3 color);//Constructor para inicializar los archivos
    ~cmd_renderizarLineas();

    void setShaderProgram(const Shader &newShader);
    Shader getShaderProgram();

    void setTextureProgram(Texture *newTexture);
    void setColorLinea(glm::vec3 color);

    void setLinea(Linea nuevaLinea); //asignar una linea a la instancia de la clase <solo se usa para reescribir el objeto>

    void initBuffers(); //inicializa la memoria para almacenar una linea
    void initOtherBuffers();

    void drawLinea(QWidget *parent);
    void drawOtherLinea(QWidget *parent);


    void actualizarVBOlineas(QWidget *parent); //funcion vacia para actualizar la memoria en el GPU
    void actualizarVBOlineas();

    void actualizarVBOThick(QWidget *parent);

    void receiveDirectPostion(float x1, float y1, float x2, float y2);

    void setEndLine(crushedpixel::Polyline2D::EndCapStyle end_line);

    void setPuntoInicial(Punto *puntoInicial, QWidget *parent);
    void setPuntoFinal(Punto *puntoFinal, QWidget *parent);

    void setFirstPointThick(Punto* puntoInicial, QWidget *parent);
    void setLastPointThick(Punto* puntoFinal, QWidget *parent);

    float getThick() const;
    void setThick(float value);
    void setColorThick(glm::vec3 color);

    void drawTransforamtions(glm::vec2 position,
                             glm::vec2 size,
                             float     rotate = 0.0f);


    glm::mat4 getMVP() const;
    void setMVP(const glm::mat4 &MVP);

};

#endif // CMD_RENDERIZARLINEAS_H
