#ifndef DRAWABLEOBJECT_LINEA_H
#define DRAWABLEOBJECT_LINEA_H

#include <QOpenGLExtraFunctions>

#include "geometry.h"
#include "shader.h"
#include "texture.h"
#include "cmd_renderizarlineas.h"
#include "linea.h"

namespace COLORG {
    const static glm::vec3 BLUE(0.0, 0.0, 1.0);
    const static glm::vec3 LIGHT_STEEL_BLUE(0.56, 0.56, 0.73);
    const static glm::vec3 NAVY_BLUE(0.13, 0.13, 0.55);
    const static glm::vec3 BLACK(0.0, 0.0, 0.0);
    const static glm::vec3 RED(1.0, 0.0, 0.0);
}

class DrawableObject_Linea : public Geometry, protected QOpenGLExtraFunctions
{
protected:
    cmd_renderizarLineas *renderable;
public:
    glm::vec3 Color;
    //estado de renderizacion
    Shader shaderProgram;
    Texture Sprite;
//    Camera2D cameraLinea;

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
    void draw_Componente_Geometry(QWidget *parent) override;

    //!GETTERS AND SETTERS DE HIJO
    void setShader(const Shader &shaderProgram) override;
    void setTexture(Texture *textureProgram) override;
    void setCamera(Camera2D *viewMatrix) override;

    Shader getShader();
    Camera2D getCamera();

    //!Funciondes de renderizado dinamico
    void setStartPoint(Punto *firstPoint, Geometry *child, QWidget *parent) override;
    void setEndPoint(Punto *endPoint, Geometry *child, QWidget *parent) override;


    void setDirectPosition(float x1, float y1, float x2, float y2);
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
