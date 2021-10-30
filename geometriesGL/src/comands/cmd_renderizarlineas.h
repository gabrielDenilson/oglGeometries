#ifndef CMD_RENDERIZARLINEAS_H
#define CMD_RENDERIZARLINEAS_H

#include <QOpenGLExtraFunctions>
#include <Polyline2D.h>
#include <Vec2.h>

#include "geometry.h"
#include "shader.h"
#include "texture.h"

#include "linea.h"
#include "punto.h"


class cmd_renderizarLineas : protected QOpenGLExtraFunctions
{
public:
    Linea lineaCords; //atributo publico para usar con los eventos y hacer el rendrizado mas facil.

    cmd_renderizarLineas(); //Constructor vacio
    cmd_renderizarLineas(string nombreLinea); // Constructor vacio String Nombre
    cmd_renderizarLineas(Shader &shader, Texture &texture, glm::vec3 color);//Constructor para inicializar los archivos
    ~cmd_renderizarLineas();

    void setLinea(Linea nuevaLinea); //asignar una linea a la instancia de la clase <solo se usa para reescribir el objeto>
    void setColorLinea(glm::vec3 color);


    void initBuffers(); //inicializa la memoria para almacenar una linea
    void initOtherBuffers();

    void drawLinea();
    void drawOtherLinea();

    void setShaderProgram(Shader &newShader);
    void setTextureProgram(Texture &newTexture);

    void actualizarVBOlineas(QWidget *parent); //funcion vacia para actualizar la memoria en el GPU
    void actualizarVBOThick(QWidget *parent);

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

private:

    //!Atributos de renderizado
    unsigned int lineaVAO; //!Memoria vertex GL
    unsigned int lineaVBO; //!Memoria buffer GL

    unsigned int thickVAO; //!Memoria vertex GL
    unsigned int thickVBO; //!Memoria buffer GL


    //!Atributos de linea
    glm::mat4 m_MVP         = glm::mat4(1.0f);


    Shader shader_Renderiza_Linea; //!Shader Program liena GL
    Texture texture_Renderiza_Linea; //!Texture file linea GL

    glm::vec3 colorLinea; //! Color vertex Linea
    glm::vec3 colorThick; //! Color vertex Linea


    std::vector<crushedpixel::Vec2> vertices; //!Coordenada de Grosor
    std::vector<crushedpixel::Vec2> puntosCoord; //!Coordenadas de Linea

    float thick; //!Tamaño de grosor Linea
    string nombreCmd; //!Nombre de comando
};

#endif // CMD_RENDERIZARLINEAS_H
