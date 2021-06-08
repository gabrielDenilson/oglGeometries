#include "shader.h"

#include <QDebug>

Shader::Shader(const char*vertexDireccion, const char*fragmentDireccion)
{
    initializeOpenGLFunctions();

    vertexArchivo.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentArchivo.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertexArchivo.open(vertexDireccion);
        fragmentArchivo.open(fragmentDireccion);

        std::stringstream vertexShaderStream, fragmentShaderStream;

        vertexShaderStream << vertexArchivo.rdbuf();
        fragmentShaderStream << fragmentArchivo.rdbuf();

        vertexArchivo.close();
        fragmentArchivo.close();

        vertexCodigo = vertexShaderStream.str();
        fragmentCodigo = fragmentShaderStream.str();
    }
    catch (std::ifstream::failure e){
        qDebug() << "NO se vinculo uno de los shaders" ;
    }

    const char* vShaderCodigo = vertexCodigo.c_str();
    const char* fShaderCodigo = fragmentCodigo.c_str();

    //Compilamos y linkamos los shaders
    unsigned int vertex, fragment;
    int exito;
    char infoLog[512];



    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCodigo, NULL);
    glCompileShader(vertex);
    //errorssss
                glGetShaderiv(vertex, GL_COMPILE_STATUS, &exito);
                if (!exito) {
                    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
                    std::cout << "Error COMPILACION VERTEX\n" << infoLog << std::endl;
                }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCodigo, NULL);
    glCompileShader(fragment);
    //errorsss
                glGetShaderiv(fragment, GL_COMPILE_STATUS, &exito);
                if (!exito) {
                    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
                    std::cout << "Error COMPILACION FRAGMENT\n" << infoLog << std::endl;
                }

    //GLuint programa = glCreateProgram();
    //GLint uniform;
    //glUniform1i(uniform, 32);


    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    //Revisamos errores
    glGetProgramiv(ID, GL_COMPILE_STATUS, &exito);
    if(!exito){
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        qDebug() << "Error al compilar el programa Shader" ;
    }

    //Liberamos la memoria
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::usar()
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setFloat(const std::string &name, float value)
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setInt(const std::string &name, int value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

