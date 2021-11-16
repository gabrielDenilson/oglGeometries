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
      DRAW_STATE(MOVE_SCENE),
      camera(new Camera2D(160, 90, this))
{
    this->setMouseTracking(true);

    setFocusPolicy(Qt::StrongFocus);

    camera->setZoom(1);
    signal_draw = false;

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

    this->sceneGroup = new InteractiveFigure();
    this->sceneGroup->init_interactive_figure();

}

void widgetTrazado::resizeGL(int w, int h)
{
    weidthWdg = w;
    heigthWdg = h;

}

void widgetTrazado::paintGL()
{
    glClearColor(0.95, 0.93, 0.93, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glClear(GL_ACCUM_BUFFER_BIT);
    glClear(GL_STENCIL_BUFFER_BIT);

    this->sceneGroup->set_camera_group(camera);
    camera->update();

    this->sceneGroup->groupShapes->draw_Componente_Geometry(this);
}

// -------------- MOUSE PRUEBA ---------------

int mouseContador = 0;
Punto puntoFinal;
glm::vec2 worlfPoint;

//--------------------------------------------
void widgetTrazado::mousePressEvent(QMouseEvent *event)
{
    float x = event->pos().x();
    float y = event->pos().y();
    worlfPoint = camera->screenToWorldSpace(x, y);
    qDebug() <<"WP: "<< worlfPoint.x << " x" << worlfPoint.y <<" y";


    puntoFinal.setX(worlfPoint.x);
    puntoFinal.setY(worlfPoint.y);

    if(DRAW_STATE == MOVE_SCENE){
        if(event->button() == Qt::LeftButton){
//            mouseContador++;
            camera->onMousePress(x, y);
        }
        } else if(signal_draw == true){
            start_End_Draw_State(event, DRAW_STATE);
        }

}

//-------------- MOVIMIENTO DE MOUSE -----------------
void widgetTrazado::mouseMoveEvent(QMouseEvent *event)
{
    float x = event->pos().x();
    float y = event->pos().y();



    if(DRAW_STATE == MOVE_SCENE){
            if(event->buttons() & Qt::LeftButton){
                if(!(event->modifiers() & Qt::ShiftModifier)){
                    //move world
                    qDebug() << x << " x" << y <<" y";
                    camera->processMouseMovement(x, y);
                }

            }
        }


    if(signal_draw == true){
        if(DRAW_STATE == CUADRADO) mouseContador = 0; else
        if(mouseContador == 1){
            worlfPoint = camera->screenToWorldSpace(x, y);
            puntoFinal.setX(worlfPoint.x);
            puntoFinal.setY(worlfPoint.y);
            sceneGroup->receiveLastPoint(&puntoFinal, this);
        }
    }

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

float widgetTrazado::getTime()
{
    time = QTime::currentTime();
    return time.second() + time.msec()/1000.0;
}

//Suma y resta el conatadorMouse envia event a InteractiveFigure
void widgetTrazado::start_End_Draw_State(QMouseEvent *event, TIPO tipoDibujo)
{
    if(event->button() == Qt::LeftButton){
        mouseContador++;
    }

    if(tipoDibujo == CUADRADO){
        this->sceneGroup->DrawObject(tipoDibujo, this);

        this->sceneGroup->receiveFirstPoint(&puntoFinal, this);
        mouseContador =0;
    }

//  Bucles de renderizado dinamico
    if(event->button()==0x00000001 && mouseContador == 1){


        this->sceneGroup->DrawObject(tipoDibujo, this);

        this->sceneGroup->receiveFirstPoint(&puntoFinal, this);
//        this->paintGL();

    } else if(event->button()==0x00000001 && mouseContador == 2){ //comprueba si se solto el raton =? Termina la linea : continua sujeta al mouse

        mouseContador = 0; // regresa el contador al valor inicial

        this->sceneGroup->receiveLastPoint(&puntoFinal, this);


    }
}


//----------------------SLOTS-----------------------
void widgetTrazado::draw_object(bool checked, TIPO dibujo)
{
    this->signal_draw = checked; //
    this->DRAW_STATE = dibujo;
    if(checked){
        qDebug() << "START de dibujo";

    } else {
        qDebug() << "END de dibujo";

    }

}
