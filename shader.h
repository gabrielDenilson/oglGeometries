#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLExtraFunctions>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader : QOpenGLFunctions
{
public:
    Shader();

    void configurarShaders();
    //usar el programa ID
    void setVertexDireccion(const char* vertexDireccion);
    void setFragmentDireccion(const char* fragmentDireccion);

    void usar();

    void release();

    //Uso de los uniforms
    void setBool(const std::string& name, bool value);

    void setFloat(const std::string& name, float value);

    void setInt(const std::string& name, int value);

    unsigned int ID;
private:
    const char* vertDireccion;
    const char*fragDireccion;

    std::string vertexCodigo;
    std::string fragmentCodigo;
    std::ifstream vertexArchivo;
    std::ifstream fragmentArchivo;
};

#endif // SHADER_H
