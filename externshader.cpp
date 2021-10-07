#include "externshader.h"

#include <QDebug>

void ExternShader::configurarShaders()
{
    initializeOpenGLFunctions();

    vertexArchivo.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentArchivo.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertexArchivo.open(vertDireccion);
        fragmentArchivo.open(fragDireccion);

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

    //QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

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

ExternShader::ExternShader()
{

}

void ExternShader::setVertexDireccion(const char *vertexDireccion)
{
    this->vertDireccion = vertexDireccion;
}

void ExternShader::setFragmentDireccion(const char *fragmentDireccion)
{
    this->fragDireccion = fragmentDireccion;
}

void ExternShader::usar()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glUseProgram(ID);
}

void ExternShader::release()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glUseProgram(0);
}

void ExternShader::setBool(const std::string &name, bool value)
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glUniform1i(f->glGetUniformLocation(ID, name.c_str()), (int)value);
}

void ExternShader::setFloat(const std::string &name, float value)
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glUniform1f(f->glGetUniformLocation(ID, name.c_str()), value);
}

void ExternShader::setInt(const std::string &name, int value)
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glUniform1i(f->glGetUniformLocation(ID, name.c_str()), value);
}

