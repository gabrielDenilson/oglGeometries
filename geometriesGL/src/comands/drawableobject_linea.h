#ifndef DRAWABLEOBJECT_LINEA_H
#define DRAWABLEOBJECT_LINEA_H

#include <QOpenGLExtraFunctions>

#include "geometry.h"
#include "shader.h"
#include "texture.h"
#include "cmd_renderizarlineas.h"
#include "linea.h"

class DrawableObject_Linea : public Geometry, protected QOpenGLExtraFunctions
{
private:
    cmd_renderizarLineas *renderable;
public:
    glm::vec3 Color;
    //estado de renderizacion
    Shader shaderProgram;
    Texture Sprite;

    bool transformar;
    glm::mat4 model = glm::mat4(1.0); //inicializacion no afecta a la figura

    crushedpixel::Vec2 roundPoint; //!Coordenada de Grosor

public:
    //FUNCIONES DE HOJA
    DrawableObject_Linea();
    DrawableObject_Linea(Shader &shaderProgram,  //Constructor principal para reservar memoria:
                         Texture &textura,      //  la dinamica de dibujo se implementa mediante sus metodos
                         glm::vec3 color);     //  a travez de la clase Cliente (WidgetTrazado)

    ~DrawableObject_Linea();
    bool isComposite() const override { return false; }

    //!FUNCIONES DE DIBUJO
    void draw_Componente_Geometry() override;

    //!GETTERS AND SETTERS DE HIJO
    void setShader(const Shader &shaderProgram) override;
    void setTexture(Texture *textureProgram) override;
    void setCamera(Camera2D *viewMatrix) override;
    //Funciondes de renderizado dinamico

    void setColorLinea(glm::vec3 color);
    void setThick(float thick);
    void setColorThick(glm::vec3 color);

    Punto getPuntoInicial();
    void setPuntoInicial(Punto *puntoIncial, QWidget *parent);

    Punto getPuntoFinal();
    void setPuntoFinal(Punto *puntoFinal, QWidget *parent);

    void drawLine();

    void setMVP(const glm::mat4 &MVP);
    glm::mat4 getMVP();

};

#endif // DRAWABLEOBJECT_LINEA_H
