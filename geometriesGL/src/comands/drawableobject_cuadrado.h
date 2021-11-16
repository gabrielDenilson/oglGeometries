#ifndef DRAWABLEOBJECT_CUADRADO_H
#define DRAWABLEOBJECT_CUADRADO_H

#include <QOpenGLExtraFunctions>

#include "geometry.h"
#include "shader.h"
#include "texture.h"
#include "linea.h"
#include "drawableobject_linea.h"
#include "cmd_renderizarlineas.h"


class DrawableObject_Cuadrado :public Geometry, protected QOpenGLExtraFunctions

{
public:
    glm::vec3 Color;
    Shader shaderProgram;
    Texture Sprite;
    bool transformation;
    glm::mat4 model = glm::mat4(1.0f);


private:
    cmd_renderizarLineas *lineaA;
    cmd_renderizarLineas *lineaB;
    cmd_renderizarLineas *lineaC;
    cmd_renderizarLineas *lineaD;

    Punto *A;
    Punto *B;
    Punto *C;
    Punto *D;

public:
    //color, shaderProgram, Sprite, transfomarBool, model matrix
    DrawableObject_Cuadrado();
    DrawableObject_Cuadrado(Shader &shaderProgram,
                            Texture & texture,
                            glm::vec3 color);

    ~DrawableObject_Cuadrado();

    bool isComposite() const override { return false; }

    //!DRAW FUNCTIONS
    void draw_Componente_Geometry(QWidget *parent) override;

    //!GETTERS AND SETTERS OF CHILD
    void setShader(const Shader &shaderCompound) override;
    void setTexture(Texture *textureCompound) override;
    void setCamera(Camera2D *viewMatrix) override;
    //DINAMIC RENDER FUNCTIONS
    void setColor(glm::vec3 color);
    void setThick(float thick);
    void setColorThick(glm::vec3 color);

    //Getters and setters of Puntos A, B, C, D
    void setPuntoA(Punto *puntoA, QWidget *parent);
    void setPuntoB(Punto *puntoB, QWidget *parent);
    void setPuntoC(Punto *puntoC, QWidget *parent);
    void setPuntoD(Punto *puntoD, QWidget *parent);

    //Getters of Puntos A, B, C, D
    Punto *getPuntoA();
    Punto *getPuntoB();
    Punto *getPuntoC();
    Punto *getPuntoD();

    glm::mat4 getMVP() const;
    void setMVP(const glm::mat4 &MVP);
};

#endif // DRAWABLEOBJECT_CUADRADO_H
