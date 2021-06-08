#include "trianguloprimitivo.h"

#include <vector>
#include <iterator>

trianguloPrimitivo::trianguloPrimitivo()
{
    initializeOpenGLFunctions();
    //inicializamos los buffers necesarios
    glGenBuffers(1, &VBO);

    glGenVertexArrays(1, &VAO);

    //pipeline

    //shaderProgram = glCreateProgram();

    usoDeMemorias();
}

void trianguloPrimitivo::usoDeMemorias()
{
    //unimos el VAO que utilizaremos
    glBindVertexArray(VAO);

    //unimos el VBO al pipeline actual
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //copiamos los vertices en la memoria
    calcularCoordenadas();

    glBufferData(GL_ARRAY_BUFFER, sizeof (coordEstaticas), coordEstaticas, GL_STATIC_DRAW);

    //Posible funcion para separar
    //adjuntamos los objetos de shader al Programa de triangulo

    inicializaShaderCodigo();

    shaderProgram = glCreateProgram(); //intercambio

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    //borramos datos))
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //ordenamos los datos en el buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void trianguloPrimitivo::calcularCoordenadas()
{
    //por el momento rellenamos manualmente

    float vertices[] = {
            0.0f, 0.5f, 0.0,
            0.0f, -0.5f, 0.0,
           -1.0f, -0.5f, 0.0,
        };

    //int limite = sizeof (vertices) / sizeof (vertices[0]);

    for(int i=0; i < 9; i++){
        coordEstaticas[i] = vertices [i];
    }
}

void trianguloPrimitivo::inicializaShaderCodigo()
{
    vertexCodigo = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

    fragmentCodigo = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "  FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\0";

    //creamos los vertices y fragmentos en la memoria de OGL
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //adjuntamos el codigo al objeto
    glShaderSource(vertexShader, 1, &vertexCodigo, NULL);
    //compilamos el vertexShader
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragmentCodigo, NULL);

    glCompileShader(fragmentShader);
}

void trianguloPrimitivo::renderTriangulo()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}


















