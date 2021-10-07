#include "resourcemanager.h"

#include <QDebug>
//#include <QOpenGLExtraFunctions>
//#include <QGLFunctions>

#include <iostream>
#include <sstream>
#include <fstream>

//Instanciamos las variables staticas
std::map <std::string, Shader> ResourceManager::Shaders;
std::map <std::string, Texture> ResourceManager::Textures;


//PRIVATE
Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
{
    //1 Recuperar el vertex/fragment codigo de la ruta de archivo
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try {
        //Abrir archivos
        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);

        //Declaramos variables de secuencia
        std::stringstream vShaderStream, fShaderStream;

        //Leer el buffer contenido en la secuencia
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();

        //cerrar manejadores de archivos
        vertexShaderFile.close();
        fragmentShaderFile.close();

        //convertir Stream en String
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();

        //Si existe la direccion de Geometry, tambien cargar el GeometryShader
        if(gShaderFile != nullptr){
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    } catch (std::exception e) {
        qDebug() << "ERROR PROGRAMADOR! La carga de archibos Shader fallo" ;
    }

    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    const char *gShaderCode = geometryCode.c_str();

    //2 Creamos el objeto Shader del codigo fuente
    Shader shader;
    shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
    return shader;
}

Texture ResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    //crear el objeto Textura
    Texture texture;
    if (alpha){
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }

    /*
    //cargar imagen
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);

    // generamos la textura
    texture.Generate(width, height, data);

    // y finalmente liberamos los datos de la imagen
    stbi_image_free(data);  */
    return texture;
}


//PUBLIC
Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name)
{
    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
    return Shaders[name];
}

Texture ResourceManager::LoadTexture(const char *file, bool alpha, std::string name)
{
    Textures[name] = loadTextureFromFile(file, alpha);
    return Textures[name];
}

Texture ResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}

void ResourceManager::Clear()
{
    //Borramos todos los Shaders apropiadamente
    for(auto iter : Shaders)
        glDeleteProgram(iter.second.ID);


    //Borramos todas las texturas adecuadamente
    for (auto iter : Textures)
        glDeleteTextures(1, &iter.second.ID);
}
