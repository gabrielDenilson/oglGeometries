#ifndef DRAWABLEOBJECT_PUNTO_H
#define DRAWABLEOBJECT_PUNTO_H

#include "geometry.h"
#include "cmd_renderizarpunto.h"

class DrawableObject_Punto : public Geometry
{
protected:
public:
    cmd_renderizarPunto *renderable;

    glm::vec3 Color;
    //estado de renderizacion
    Shader shaderProgram;
    Texture Sprite;

    bool transformar;
    glm::mat4 model = glm::mat4(1.0); //inicializacion no afecta a la figura

public:
    //FUNCIONES DE HOJA
    DrawableObject_Punto();
    DrawableObject_Punto(Shader &shaderProgram,  //Constructor principal para reservar memoria:
                         Texture &textura,      //  la dinamica de dibujo se implementa mediante sus metodos
                         glm::vec3 color);     //  a travez de la clase Cliente (WidgetTrazado)

    ~DrawableObject_Punto();
    bool isComposite() const override { return false; }

    //!FUNCIONES DE DIBUJO
    void draw_Componente_Geometry(QWidget *parent) override;

    //!GETTERS AND SETTERS DE HIJO
    void setShader(const Shader &shaderProgram) override;
    void setTexture(Texture *textureProgram) override;
    void setCamera(Camera2D *viewMatrix) override;

    vector<Punto> &get_points_area() override;
    void setColorPunto(glm::vec3 colorSet) override;

    //!Funciondes de renderizado dinamico
    void setStartPoint(Punto *firstPoint, Geometry *child, QWidget *parent) override;
    void setEndPoint(Punto *endPoint, Geometry *child, QWidget *parent) override;



    void setDirectPosition(float x, float y);
//    void setColorPunto(glm::vec3 color);
    void setThick(float thick);
    void setColorThick(glm::vec3 color);

    void drawPunto(QWidget *parent);

    void setMVP(const glm::mat4 &MVP);
    glm::mat4 getMVP();

};

#endif // DRAWABLEOBJECT_PUNTO_H
