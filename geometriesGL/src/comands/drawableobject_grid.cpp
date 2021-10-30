#include "drawableobject_grid.h"

DrawableObject_Grid::DrawableObject_Grid()
{

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

void DrawableObject_Grid::draw_Componente_Geometry()
{
    grid->drawGrid();
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
