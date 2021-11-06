#ifndef CAMERA2D_H
#define CAMERA2D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <QOpenGLFunctions>

#include <QWidget>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const glm::vec3 POSITION{0.0f, 0.0f, 0.0f};

class Camera2D
{
private:
    QWidget *m_parent;
    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
    glm::mat4 m_viewProjectionMatrix;

    glm::vec3 m_position{0.0f, 0.0f, 0.0f};
    glm::vec3 m_scale{1.0f, 1.0f, 1.0f};
    float m_rotation = 0;

    glm::vec3 m_right;
    glm::vec3 m_up;
    glm::vec3 m_zoom;

    glm::vec3 m_lastPosition;

    int g_lastX;
    int g_lastY;
public:


    Camera2D(float left, float right, float bottom, float top, QWidget *parent);

    const glm::vec3& getPosition() const { return m_position; }
    void SetPosition(const glm::vec3& position) {this->m_position = position; RecalculateViewMatrix(); }

    const glm::vec3& getTranslate() const {return m_scale;}
    void SetScale(const glm::vec3& scale) {this->m_scale = scale; RecalculateViewMatrix(); }

    float getRotation() const { return m_rotation; }
    void SetRotation(float rotation) {this->m_rotation = rotation; RecalculateViewMatrix(); }

    const glm::mat4& getProjectionMatrix() const { return m_projectionMatrix; }
    const glm::mat4& getViewMatrix() const { return m_viewMatrix; }
    const glm::mat4& getViewProjectionMatrix() const { return m_viewProjectionMatrix; }

    void reziseGlViewPort(const int width, const int height);

    void ProccessKeyBoard(CameraMovement direcion);

    void ProccesScroll(float yoffset);

    void processMouseMovement(float xoffset, float yoffset);

    glm::vec2 getWorldCoordinates(float mouseX, float mouseY);

    void onMousePress(float mouseX, float mouseY);

    void MoveWorldWithMouse(float mouseX, float mouseY);
private:
    void RecalculateViewMatrix();
};

#endif // CAMERA2D_H
