#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QOpenGLExtraFunctions>

#include <map>
#include <string>


#include "shader.h"
#include "texture.h"

class ResourceManager : QOpenGLFunctions
{
private:
    //Constructor privado, es decir, no queremos ningún objeto de administrador de recursos real. Sus miembros y funciones deben estar disponibles al público (estático).
    ResourceManager() { initializeOpenGLFunctions(); };
    //Carga y genera un shader desde el archivo
    static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    //Carga una sola textura del archivo
    static Texture loadTextureFromFile(const char *file, bool alpha);


public:
    // almacenamiento de recursos
    static std::map<std::string, Shader>    Shaders;
    static std::map<std::string, Texture> Textures;

    // Carga (y genera) un programa del vertex corgado, fragment (y geometry) shaders codigo fuente. Tambien carga gShaderFile si no es un nullptr
    static Shader    LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
    // recupera el shader almacenado
    static Shader    GetShader(std::string name);
    // Carga (y genera) una textura del archivo
    static Texture   LoadTexture(const char *file, bool alpha, std::string name);
    // recupera la textura almacenada
    static Texture   GetTexture(std::string name);

    // desasigna correctamente todos los recursos cargados
    void      Clear(); //Declarar funcion ESTATICA si se prensentan fallos en la eliminacion de Shaders

    void clearShader() {} ;
};

#endif // RESOURCEMANAGER_H
