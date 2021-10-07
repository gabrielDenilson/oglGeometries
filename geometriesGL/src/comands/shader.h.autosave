#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLExtraFunctions>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class Shader :protected QOpenGLFunctions
{
public:
    // Estado
    unsigned int ID;
    // constructor
    Shader() { };
    // configurar el shader actual como activo
    Shader  &Use();
    // compilar el shader del codigo existente
    void    Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr); // note: geometry source code is optional
    // funciones de utilidad
    void    SetFloat    (const char *name, float value, bool useShader = false);
    void    SetInteger  (const char *name, int value, bool useShader = false);
    void    SetVector2f (const char *name, float x, float y, bool useShader = false);
    void    SetVector2f (const char *name, const glm::vec2 &value, bool useShader = false);
    void    SetVector3f (const char *name, float x, float y, float z, bool useShader = false);
    void    SetVector3f (const char *name, const glm::vec3 &value, bool useShader = false);
    void    SetVector4f (const char *name, float x, float y, float z, float w, bool useShader = false);
    void    SetVector4f (const char *name, const glm::vec4 &value, bool useShader = false);
    void    SetMatrix4  (const char *name, const glm::mat4 &matrix, bool useShader = false);
private:
    // revisar si la vinculacion de archivos falla, imprimir el error por verdad
    void    checkCompileErrors(unsigned int object, std::string type);
};

#endif // SHADER_H
