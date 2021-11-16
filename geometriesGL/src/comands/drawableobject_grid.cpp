#include "drawableobject_grid.h"

DrawableObject_Grid::DrawableObject_Grid() : Color(1.0f)
{
    grid = new cmd_renderizarGrid();
}

DrawableObject_Grid::DrawableObject_Grid(Shader &shaderProgram, Texture &textura, glm::vec3 color)
{
    grid = new cmd_renderizarGrid(shaderProgram, textura, color);
    //Transformacion por defecto desactivada
    this->transformar = false;
}

DrawableObject_Grid::~DrawableObject_Grid()
{

}

void DrawableObject_Grid::draw_Componente_Geometry(QWidget *parent)
{
    grid->drawGrid();
}

void DrawableObject_Grid::setShader(const Shader &shaderProgram)
{
    grid->setShaderProgram(shaderProgram);
}

void DrawableObject_Grid::setTexture(Texture *textureProgram)
{
    grid->setTextureProgram(textureProgram);
}

void DrawableObject_Grid::setCamera(Camera2D *viewMatrix)
{
    this->setMVP(viewMatrix->getVPmatrix());
//    this->setMVP(viewMatrix->getViewProjectionMatrix());
}

void DrawableObject_Grid::setShaderNormal(const Shader *shaderProgram)
{
    grid->setShaderNormal(shaderProgram);
}

void DrawableObject_Grid::setColorGrid(glm::vec3 color)
{
    this->Color = color;
    grid->setColorPoints(this->Color);
}

void DrawableObject_Grid::setMVP(const glm::mat4 &MVP)
{
    grid->setMVP(MVP);
}
