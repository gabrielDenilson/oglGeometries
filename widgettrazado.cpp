#include "widgettrazado.h"

#include "renderfigures.h"

#include <QMouseEvent>
#include <QDebug>

//Encabezados de renderizado
#include "geometriesGL/src/comands/resourcemanager.h"
#include "geometriesGL/src/comands/spriterender.h"
#include "geometriesGL/src/comands/geometry.h"
#include "geometriesGL/src/comands/compoundgeometry.h"
#include "geometriesGL/src/comands/cmd_renderizarlineas.h"
#include "geometriesGL/src/comands/drawableobject_linea.h"

widgetTrazado::widgetTrazado(QWidget *parent)
    : QOpenGLWidget(parent),
      weidthWdg(0),
      heigthWdg(0)
{
    this->setMouseTracking(true);
    clickIzquierdoPress = false;
//    Linea prueba {-1, -1, 1, 1};
//    vectorLineas.push_back(prueba);
}

widgetTrazado::~widgetTrazado()
{
}

//´´¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨

DrawableObject_Linea *hoja;

//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨^^
void widgetTrazado::initializeGL()
{
    initializeOpenGLFunctions();

    ResourceManager::LoadShader("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/repositorios/oglGeometries/shaders/vertexShader_spriteRender.vert",
                                "C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/repositorios/oglGeometries/shaders/fragmentShader_spriteRender.frag",
                                nullptr,
                                "sprite");

//    ResourceManager::LoadShader("C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/TutorialBegin/GeometriesGL/shaders/vertexShader.vs",
//                                "C:/Users/GabrielSinn/OneDrive/Documentos/QML_all/TutorialBegin/GeometriesGL/shaders/fragmentShader.fs",
//                                nullptr,
//                                "sprite");
    //MATHS FOR TRANSFORMATION SHADER PROGRAM
                //    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width()),
                //                                      static_cast<float>(this->height()),
                //                                      0.0f, -1.0f, 1.0f);
                //    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
                //    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    Shader myShader;
    myShader = ResourceManager::GetShader("sprite");

    this->geometryTreeCompound = new CompoundGeometry;

    ResourceManager::LoadTexture("nofile", true, "cara");

    Texture myTextura;
    myTextura = ResourceManager::GetTexture("cara");

    hoja = new DrawableObject_Linea(myShader, myTextura, glm::vec3(0.0f, 1.0f, 0.0f));

    hoja->setThick(0.05);
    hoja->setColorLinea(glm::vec3(0.3, 0.0, 0.0));
    hoja->setColorThick(glm::vec3(0.0, 0.3, 0.0));

    geometryTreeCompound->add_Componente_Geometry(hoja);

}

void widgetTrazado::resizeGL(int w, int h)
{
    weidthWdg = w;
    heigthWdg = h;

}

void widgetTrazado::paintGL()
{
    glClearColor(0.3, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //Renderer->DrawSprite(ResourceManager::GetTexture("face"), glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));

    //Prueba de renderizado
//    Texture myTexture;
//    myTexture = ResourceManager::GetTexture("cara");
//    //Renderer->DrawSprite(myTexture, glm::vec2(200, 200), glm::vec2(70, 40), 40.0f, glm::vec3(1.0f, 0.5f, 0.0f));
//    arbol->draw_intern_Sprite(myTexture, glm::vec2(0, 0), glm::vec2(300, 3), 0.0f, glm::vec3(1.0f, 0.0f, 0.5f));

//    arbol->draw_Componente_Geometry(Renderer);

      geometryTreeCompound->draw_Componente_Geometry();

}

// -------------- MOUSE PRUEBA ---------------
int mouseContador = 0;
float ultimaPosX;
float ultimaPosY;
Linea paraAgregar;

Punto puntoFinal;
//--------------------------------------------
void widgetTrazado::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        puntoFinal = mousePosicion;
        mouseContador++;
    }

//  Bucles de renderizado dinamico
    if(event->button()==0x00000001 && mouseContador == 1){

        hoja->setPuntoInicial(&puntoFinal, this);
        hoja->setPuntoFinal(&puntoFinal, this); // si se mueve los puntos O y P son iguales y no se renderiza nada

    } else if(event->button()==0x00000001 && mouseContador == 2){ //comprueba si se solto el raton =? Termina la linea : continua sujeta al mouse

        mouseContador = 0; // regresa el contador al valor inicial

        puntoFinal = mousePosicion;
        hoja->setPuntoFinal(&puntoFinal,this);

    }
}

//-------------- MOVIMIENTO DE MOUSE -----------------
void widgetTrazado::mouseMoveEvent(QMouseEvent *event)
{
    mousePosicion = normalizarMousePress(event->pos());
    //qDebug() << event->x() << event->y(); //imprime posicion del mouse

    if(mouseContador == 1){
        hoja->setPuntoFinal(&mousePosicion, this);
    }
}

Punto widgetTrazado::normalizarMousePress(QPoint posicion)
{
    Punto normalizedPosicion;
    float x,y;

    x = -1.0 + 2.0 * (float)posicion.x() / weidthWdg;
    normalizedPosicion.setX(x);

    y = 1.0 - 2.0 * (float)posicion.y() / heigthWdg;
    normalizedPosicion.setY(y);

    return normalizedPosicion;
}


//----------------------SLOTS-----------------------
void widgetTrazado::nuevaLinea()
{
    //Linea de prueba

}
