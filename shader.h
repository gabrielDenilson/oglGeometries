#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLExtraFunctions>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader: protected QOpenGLExtraFunctions
{
public:
    Shader(const char*, const char*);

    //usar el programa ID
    void usar();

    //Uso de los uniforms
    void setBool(const std::string& name, bool value);

    void setFloat(const std::string& name, float value);

    void setInt(const std::string& name, int value);

    unsigned int ID;
private:

    std::string vertexCodigo;
    std::string fragmentCodigo;
    std::ifstream vertexArchivo;
    std::ifstream fragmentArchivo;



};

#endif // SHADER_H
