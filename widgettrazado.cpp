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
#include "geometriesGL/src/comands/drawableobject_cuadrado.h"
#include "geometriesGL/src/comands/drawableobject_grid.h"

widgetTrazado::widgetTrazado(QWidget *parent)
    : QOpenGLWidget(parent),
      weidthWdg(0),
      heigthWdg(0),
      camera(new Camera2D(0.0f, 160.0f, 0.0f, 90.0f, this))
//      camera(-this->width()/2.0f,this->width()/2.0f, -this->height()/2.0f, this->height()/2.0f, this)
{
    this->setMouseTracking(true);

    setFocusPolicy(Qt::StrongFocus);

    clickIzquierdoPress = false;

    lastX = width()/2.0f;
    lastY = height()/2.0f;
    firstMouse = true;
//    Linea prueba {-1, -1, 1, 1};
//    vectorLineas.push_back(prueba);
}

widgetTrazado::~widgetTrazado()
{
}

//´´¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨

DrawableObject_Linea *hoja;
DrawableObject_Cuadrado *hojaCuadrada;
DrawableObject_Grid *hojaGrid;
glm::mat4 ProjectionRT (1.0f);

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
                                                        //    glm::mat4 projection;
                                                        //    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
                                                        ////                    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width()),
                                                        ////                                                      static_cast<float>(this->height()),
                                                        ////                                                      0.0f, 0.1f, 1.0f);
                                                        //                    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
                                                        //                    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

                                                        //                    qDebug() << this->width();
                                                        //                    qDebug() << this->height();


    Shader myShader;
    myShader = ResourceManager::GetShader("sprite");
    ResourceManager::LoadTexture("nofile", true, "cara");
    Texture myTextura;
    myTextura = ResourceManager::GetTexture("cara");

    this->geometryTreeCompound = new CompoundGeometry;

    hoja = new DrawableObject_Linea();

    hoja->setThick(0.3);
    hoja->setColorLinea(glm::vec3(1.0, 0.0, 0.0));
    hoja->setColorThick(glm::vec3(0.0, 1.0, 0.0));

    hojaCuadrada = new DrawableObject_Cuadrado();
//    hojaCuadrada->setColor(glm::vec3(0.1f, 0.0f, 0.0f));

    hojaCuadrada->setPuntoA(new Punto(-0.5f, -0.5f), this);
    hojaCuadrada->setPuntoB(new Punto(-0.5f,  0.5f), this);
    hojaCuadrada->setPuntoC(new Punto( 0.5f,  0.5f), this);
    hojaCuadrada->setPuntoD(new Punto( 0.5f, -0.5f), this);

    hojaGrid = new DrawableObject_Grid();
//    hojaGrid->setShader(ResourceManager::GetShader("sprite"));

    geometryTreeCompound->add_Componente_Geometry(hoja);
    geometryTreeCompound->add_Componente_Geometry(hojaCuadrada);
    geometryTreeCompound->add_Componente_Geometry(hojaGrid);

    geometryTreeCompound->setShader(ResourceManager::GetShader("sprite"));
//    geometryTreeCompound->setTexture(ptrTexture);
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

    float currentFrame = getTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;


//    hoja->setMVP(myMVP);
//    hojaCuadrada->setMVP(myMVP);
//    hojaGrid->setMVP(myMVP);
    geometryTreeCompound->setCamera(camera);

//    geometryTreeCompound->setCamera(&camera);
    geometryTreeCompound->draw_Componente_Geometry();

}

// -------------- MOUSE PRUEBA ---------------

int mouseContador = 0;
float ultimaPosX;
float ultimaPosY;
Linea paraAgregar;

Punto puntoFinal;
glm::vec2 worlfPoint;

//--------------------------------------------
void widgetTrazado::mousePressEvent(QMouseEvent *event)
{
    float x = event->pos().x();
    float y = event->pos().y();
    worlfPoint = camera->getWorldCoordinates(x, y);
//    qDebug() <<"WP: "<< worlfPoint.x << " x" << worlfPoint.y <<" y";

    camera->onMousePress(x, y);

    puntoFinal.setX(worlfPoint.x);
    puntoFinal.setY(worlfPoint.y);
//    qDebug() << puntoFinal.getX() << " x" << puntoFinal.getY() <<" y";

    if(event->button() == Qt::LeftButton){
        mouseContador++;
    }

//  Bucles de renderizado dinamico
    if(event->button()==0x00000001 && mouseContador == 1){


        hoja->setPuntoInicial(&puntoFinal, this);
//        hoja->setPuntoFinal(&puntoFinal, this); // si se mueve los puntos O y P son iguales y no se renderiza nada


    } else if(event->button()==0x00000001 && mouseContador == 2){ //comprueba si se solto el raton =? Termina la linea : continua sujeta al mouse

        mouseContador = 0; // regresa el contador al valor inicial

        hoja->setPuntoFinal(&puntoFinal,this);

//        qDebug() << puntoFinal.getX() << " x" << puntoFinal.getY() <<" y";



    }


}

//-------------- MOVIMIENTO DE MOUSE -----------------
void widgetTrazado::mouseMoveEvent(QMouseEvent *event)
{
    float x = event->pos().x();
    float y = event->pos().y();

    if(event->buttons() & Qt::LeftButton){
//        float x = event->pos().x();
//        float y = event->pos().y();
//     worlfPoint = camera->getWorldCoordinates(x, y);
//     puntoFinal.setX(worlfPoint.x);
//     puntoFinal.setY(worlfPoint.y);


//        glm::vec2 xy = camera.getWorldCoordinates(event->pos().x(), event->pos().y());
//        qDebug() << "WC x: " << xy.x << " y:" <<xy.y;
    }
//    mousePosicion = normalizarMousePress(event->pos());
    //qDebug() << event->x() << event->y(); //imprime posicion del mouse

//    if(firstMouse)
//    {
//        lastX = event->x();
//        lastY = event->y();
//        firstMouse = false;
//    }

    int xoffset = event->x();
    int yoffset = event->y(); // reversed since y-coordinates go from bottom to top



    if(mouseContador == 1){
        worlfPoint = camera->getWorldCoordinates(x, y);
        puntoFinal.setX(worlfPoint.x);
        puntoFinal.setY(worlfPoint.y);

//                qDebug() << puntoFinal.getX() << " x" << puntoFinal.getY() <<" y";

        hoja->setPuntoFinal(&puntoFinal, this);

//        camera.processMouseMovement(xoffset, yoffset);
//        camera.MoveWorldWithMouse(&xoffset, &yoffset);
//        float x = event->pos().x();
//        float y = event->pos().y();
//        camera->MoveWorldWithMouse(x, y);
    }

    update();
}

void widgetTrazado::wheelEvent(QWheelEvent *event)
{

    float yoffset = event->delta();

    camera->ProccesScroll(yoffset);

    qDebug()<< event->delta();

    update();
}

void widgetTrazado::keyPressEvent(QKeyEvent *event)
{

    //recieve keys UP DOWN LEFT RIGHT
    if(event->key() == Qt::Key_Down){
        camera->ProccessKeyBoard(BACKWARD);
    }
    if(event->key() == Qt::Key_Up){
        camera->ProccessKeyBoard(FORWARD);
    }
    if(event->key() == Qt::Key_Left){
        camera->ProccessKeyBoard(LEFT);
    }
    if(event->key() == Qt::Key_Right){
        camera->ProccessKeyBoard(RIGHT);
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

float widgetTrazado::getTime()
{
    time = QTime::currentTime();
    return time.second() + time.msec()/1000.0;
}

void updateTranslate(){
//    matTranslation = glm::translate(glm::mat4 (1.0f), glm::vec3(vecTranslate, 0.0f));
}

void updateScale(const int viewWidth, const int viewHeight)
{
//    vecScale = glm::vec2(factScale, factScale / viewHeight * viewWidth);
//    matScaling = glm::scale(glm::mat4(1), glm::vec3(vecScale, 1));
//    matTransform = matTranslation * matScaling;
}

void updateViewport(const int width, const int height)
{
    glViewport(0, 0, width, height);
    updateScale(width, height);
}

//void mouse_button_callback(GLFWwindow *window, const int button, const int action, const int mods)
//{
//    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
//    {
//        double x, y;
//        int width, height;
//        glfwGetCursorPos(window, &x, &y);
//        glfwGetWindowSize(window, &width, &height);

//        const glm::vec2 view(x / (width / 2.f) - 1,
//                        1 - y / (height / 2.f));

//        objects[0]->position = vec3((view - vecTranslate) / vecScale, 0);

//        /* Or:
//        const vec4 view(x / (width / 2.f) - 1,
//                        1 - y / (height / 2.f), 0, 1);
//        const auto pos = inverse(matTransform) * view;
//        objects[0]->position = {pos.x / pos.w, pos.y / pos.w, 0};
//        */
//    }
//}

//void window_size_callback(GLFWwindow *window, const int width, const int height)
//{
//    updateViewport(width, height);
//}


//----------------------SLOTS-----------------------
void widgetTrazado::nuevaLinea()
{
    //Linea de prueba

}
