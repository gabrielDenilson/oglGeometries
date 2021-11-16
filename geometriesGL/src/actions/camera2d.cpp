#include "camera2d.h"

#include <QDebug>
#include <QOpenGLFunctions>
#include <math.h>

Camera2D::Camera2D(int width, int height, QWidget *parent) : m_parent(parent)
{
    cop_swidth = width;
    cop_sheight = height;
    cop_position = glm::vec3(0, 0, 1);
    cop_rotation = glm::vec3(0, 0, 0);

    cop_m_direction = glm::vec3(0, 0, -1);
    cop_m_up = glm::vec3(0, 1, 0);
    cop_m_right = glm::vec3(1, 0, 0);
    cop_m_offset = glm::vec3(-cop_swidth / 2 * cop_m_zoom, -cop_sheight / 2 * cop_m_zoom, 0);



    cop_m_viewMatrix = glm::mat4(1.0f);
    cop_m_projection = glm::ortho(0.0f * cop_m_zoom, (float)cop_swidth * cop_m_zoom, 0.0f * cop_m_zoom,
                                  (float)cop_sheight * cop_m_zoom, -1.0f, 1.0f);

}

glm::vec3 Camera2D::screenToWorldSpace(int mousex, int mousey)
{

    glm::vec4 viewport = glm::vec4(0, 0, m_parent->width(), m_parent->height());
    glm::vec3 worldCoords = glm::unProject(glm::vec3(mousex, float(m_parent->height()) - mousey, 0.0f),
                                           cop_m_viewMatrix, cop_m_projection, viewport);

    return glm::vec3(worldCoords.x, worldCoords.y, 0);
}

void Camera2D::update()
{

    glm::vec3 finalPos = cop_position + cop_m_offset;

    cop_m_up = glm::cross(cop_m_right, cop_m_direction);

    cop_m_viewMatrix = glm::lookAt(finalPos, finalPos + cop_m_direction, cop_m_up);

    cop_m_viewMatrix = glm::scale(cop_m_viewMatrix, glm::vec3(1.0f, 1.0f, 1.0f));

}

void Camera2D::processMouseMovement(float x, float y)
{
    // find the difference between new position, and last, in pixels
    int offsetX = x - g_lastX;
    int offsetY = y - g_lastY;

    // update mouse pos
    g_lastX = x;
    g_lastY = y;

    // get as ratio +/- 1
    float dx = ((float) offsetX) / cop_swidth;
    float dy = ((float) offsetY) / cop_sheight;

    // now move camera by offset (might need to multiply by 2 here?)
    cop_position.x += (cop_m_offset.x*0.5) * (dx);
    cop_position.y += (-cop_m_offset.y*0.5) * (dy);

    qDebug() << cop_position.x << " x pos" << cop_position.y <<" y pos";
    m_parent->update();
}

void Camera2D::onMousePress(float x, float y){
//    m_lastPosition = glm::vec3(getWorldCoordinates(x, y), 1.0f);
    g_lastX = x;
    g_lastY = y;
}

void Camera2D::setZoom(float zoom)
{
    if(zoom < 0.0) zoom = 0.05 ;



    cop_m_zoom = zoom;

    cop_m_offset = glm::vec3(-cop_swidth / 2 * cop_m_zoom, -cop_sheight / 2 * cop_m_zoom, 0);
    cop_m_projection = glm::ortho(0.0f * cop_m_zoom,
                                  (float)cop_swidth * cop_m_zoom,
                                  0.0f * cop_m_zoom,
                                  (float)cop_sheight * cop_m_zoom,
                                  -1.0f, 1.0f);
}

//se puede multiplicar fuera por la matriz de modelo individual para cada hijo
const glm::mat4 &Camera2D::getVPmatrix()
{
    cop_m_eyeCamera = cop_m_projection * cop_m_viewMatrix;
    return cop_m_eyeCamera;

}

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

void Camera2D::reziseGlViewPort(const int , const int )
{
//    QOpenGLFunctions *f = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions>();
//    f->glViewport(0, 0, width, height);
//    m_parent->update();
}

void Camera2D::ProccessKeyBoard(CameraMovement direction)
{
    if(direction == FORWARD){
        this->cop_position += this->cop_m_up;
        m_parent->update();
    }
    if(direction == BACKWARD){
        this->cop_position -= this->cop_m_up;
        m_parent->update();
    }
    if(direction == LEFT){
        this->cop_position -= this->cop_m_right;
        m_parent->update();
    }
    if(direction == RIGHT){
        this->cop_position += this->cop_m_right;
        m_parent->update();
    }
    update();
}

void Camera2D::ProccesScroll(float yoffset)
{
    if(yoffset == 120){
        setZoom(cop_m_zoom - 0.08);
        this->update();
        m_parent->update();
    } else if(yoffset == -120){
        setZoom(cop_m_zoom + 0.05);
        this->update();
        m_parent->update();
    }

}


glm::vec2 Camera2D::getWorldCoordinates(float mouseX, float mouseY){

    glm::vec4 viewport = glm::vec4(0, 0, m_parent->width(), m_parent->height());
    glm::vec3 worldCoords = glm::unProject(glm::vec3(mouseX, float(m_parent->height()) - mouseY, 0.0f),
                                           m_viewMatrix, m_projectionMatrix, viewport);

    return glm::vec2(worldCoords.x, worldCoords.y);

}


void Camera2D::MoveWorldWithMouse(float mouseX, float mouseY){
    //find difference between new position , and old position in world space
    glm::vec3 newPosition = glm::vec3(getWorldCoordinates(mouseX, mouseY), 1.0f);

    glm::vec3 difference =  m_lastPosition - newPosition;
    m_lastPosition = newPosition;
    //move camera
    m_position += difference;

//    qDebug() <<"POSITIO: "<< m_position.x << " :x" << m_position.y << " :y";
    qDebug() <<"MOUSE: "<< mouseX << " :x" << mouseY << " :y";

    this->RecalculateViewMatrix();
}

void Camera2D::RecalculateViewMatrix()
{
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_position) *
        glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation), glm::vec3(0, 0, 1)) *
            glm::scale(glm::mat4(1.0f), m_scale);

    m_viewMatrix = glm::inverse(transform);

    m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
}
