#include "camera2d.h"

#include <QDebug>
#include <QOpenGLFunctions>

Camera2D::Camera2D(float left, float right, float bottom, float top, QWidget *parent) :
    m_parent(parent),
    m_projectionMatrix (glm::ortho(left, right, bottom, top, -1.0f, 1.0f)),
    m_viewMatrix(1.0f),
    m_right(0.5f, 0.0f, 0.0f),
    m_up(0.0f, 0.5f, 0.0f),
    m_zoom(0.05f, 0.05f, 1.0f)
{

    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}

void Camera2D::reziseGlViewPort(const int width, const int height)
{
//    QOpenGLFunctions *f = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions>();
//    f->glViewport(0, 0, width, height);
//    m_parent->update();
}

void Camera2D::ProccessKeyBoard(CameraMovement direction)
{
    if(direction == FORWARD){
        this->m_position += this->m_up;
        m_parent->update();;
    }
    if(direction == BACKWARD){
        this->m_position -= this->m_up;
        m_parent->update();
    }
    if(direction == LEFT){
        this->m_position -= this->m_right;
        m_parent->update();
    }
    if(direction == RIGHT){
        this->m_position += this->m_right;
        m_parent->update();
    }
    RecalculateViewMatrix();
}

void Camera2D::ProccesScroll(float yoffset)
{
    if(yoffset == 120){
        this->m_scale -= m_zoom;
        this->RecalculateViewMatrix();
        m_parent->update();
    } else if(yoffset == -120){
        this->m_scale += m_zoom;
        this->RecalculateViewMatrix();
        m_parent->update();
    }

}


void Camera2D::processMouseMovement(float xoffset, float yoffset)
{
    //move camera with mouse
    m_position += xoffset;
    m_position.x -= yoffset;
    RecalculateViewMatrix();
    m_parent->update();
}

glm::vec2 Camera2D::getWorldCoordinates(int *mouseX, int *mouseY){

    glm::vec4 viewport = glm::vec4(0, 0, m_parent->width(), m_parent->height());
    glm::vec3 worldCoords = glm::unProject(glm::vec3(*mouseX, float(m_parent->height()) - *mouseY, 0.0f), m_viewMatrix, m_projectionMatrix, viewport);

    return glm::vec2(worldCoords.x, worldCoords.y);

//    const glm::vec4 view(*mouseX / (m_parent->width() / 2.f) - 1,
//                            1 - *mouseY / (m_parent->height() / 2.f), 0, 1);
//            const auto pos = inverse(m_viewMatrix) * viewport;
////            objects[0]->position = {pos.x / pos.w, pos.y / pos.w, 0};
//            float posX = pos.x / pos.w;
//            float posY = pos.y/pos.w;
//            return glm::vec2 ( posX, posY);
}

void Camera2D::RecalculateViewMatrix()
{
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_position) *
        glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation), glm::vec3(0, 0, 1)) *
            glm::scale(glm::mat4(1.0f), m_scale);

    m_viewMatrix = glm::inverse(transform);

    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}
