#ifndef CMD_RENDERIZARCUADRADO_H
#define CMD_RENDERIZARCUADRADO_H

#include <QOpenGLExtraFunctions>
#include <Polyline2D.h>
#include <Vec2.h>

#include "geometry.h"
#include "shader.h"
#include "texture.h"

#include "linea.h"
#include "punto.h"

class cmd_renderizarGrid : protected QOpenGLExtraFunctions
{
public:

    cmd_renderizarGrid(); //Constructor vacio
    cmd_renderizarGrid(string nombreLinea); // Constructor vacio String Nombre
    cmd_renderizarGrid(Shader &shader, Texture &texture, glm::vec3 color);//Constructor para inicializar los archivos
    ~cmd_renderizarGrid();

    void setColorPoints(glm::vec3 color);


    void initBuffers(); //inicializa la memoria para almacenar una linea
    void setVectorPointsGrid(std::vector<glm::vec2> &points);

    void drawGrid();

    void setShaderProgram(Shader &newShader);
    void setTextureProgram(Texture &newTexture);

    void actualizarVBOGrid(QWidget *parent); //funcion vacia para actualizar la memoria en el GPU

    glm::mat4 getMVP() const;
    void setMVP(const glm::mat4 &MVP);

private:

    //!Atributos de renderizado
    unsigned int gridVAO; //!Memoria vertex GL
    unsigned int gridVBO; //!Memoria buffer GL

    //!Atributos de Grid
    glm::mat4 m_MVP = glm::mat4(1.0f);

    Shader shader_Renderiza_Grid; //!Shader Program liena GL
    Texture texture_Renderiza_Grid; //!Texture file linea GL

    glm::vec3 colorGrid; //!Color of the points of Grid

    std::vector<glm::vec2> Vertices;
    string nombreCmd; //!Nombre de comando
};

#endif // CMD_RENDERIZARCUADRADO_H
