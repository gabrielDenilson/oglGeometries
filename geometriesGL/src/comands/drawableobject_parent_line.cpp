#include "drawableobject_parent_line.h"



DrawableObject_Parent_Line::DrawableObject_Parent_Line()
{
    renderable->setColorLinea({0.0f, 0.0f, 1.0f});
    renderable->setColorThick(COLORG::BLUE);
    model = glm::mat4(1.0f);

    //renderable = new cmd_renderizarLineas();
}
