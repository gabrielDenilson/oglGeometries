#ifndef CMD_RENDERIZARPUNTO_H
#define CMD_RENDERIZARPUNTO_H

#include <QOpenGLExtraFunctions>
#include <geometriesGL/res/Polyline2D.h>
#include <geometriesGL/res/Vec2.h>

#include "geometry.h"
#include "shader.h"
#include "texture.h"

#include "punto.h"

class cmd_renderizarPunto : protected QOpenGLExtraFunctions
{
public:
    Punto puntoCords; //atributo publico para usar con los eventos y hacer el rendrizado mas facil.

private:
    //!Atributos de renderizado
    unsigned int PuntoVAO; //!Memoria vertex GL
    unsigned int PuntoVBO; //!Memoria buffer GL

    unsigned int thickVAO; //!Memoria vertex GL
    unsigned int thickVBO; //!Memoria buffer GL
    unsigned int thickEBO; //!Memoria buffer GL


    //!Atributos de Punto
    glm::mat4 m_MVP         = glm::mat4(1.0f);

    std::vector<float> verticesRectangle;
    std::vector<Punto> puntoRectangle;

    Shader shader_Renderiza_Punto; //!Shader Program liena GL
    Texture *texture_Renderiza_Punto; //!Texture file linea GL

    glm::vec3 colorPunto; //! Color vertex Linea
    glm::vec3 colorThick; //! Color vertex Linea

    float thick; //!Tamaño de grosor Linea
    string nombreCmd; //!Nombre de comando

public:
    cmd_renderizarPunto(); //Constructor vacio
    ~cmd_renderizarPunto();

    void setShaderProgram(const Shader &newShader);
    void setTextureProgram(Texture *newTexture);
    void setColorLinea(glm::vec3 color);

    void setPunto(Punto nuevoPunto); //asignar una linea a la instancia de la clase <solo se usa para reescribir el objeto>

    void initBuffers(); //inicializa la memoria para almacenar una linea
    void initOtherBuffers();

    void drawPunto(QWidget *parent);
    void drawOtherPunto(QWidget *parent);


    void actualizarVBOPunto(QWidget *parent); //funcion vacia para actualizar la memoria en el GPU

    void receiveDirectPostion(float x1, float y1);

    void setPuntoPosition(Punto *puntoInicial, QWidget *parent);

    float getThick() const;
    void setThick(float value);
    void setGenerateCordsThick();
    void setColorThick(glm::vec3 color);

    glm::mat4 getMVP() const;
    void setMVP(const glm::mat4 &MVP);

    vector<Punto> &getPuntosArea();
};

#endif // CMD_RENDERIZARPUNTO_H
