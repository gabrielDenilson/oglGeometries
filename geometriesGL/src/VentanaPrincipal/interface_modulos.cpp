#include "geometriesGL/src/VentanaPrincipal/interface_modulos.h"


#include <QMouseEvent>

#include "geometriesGL/src/VentanaPrincipal/settings.h"

#include "ui_mainhome.h"

#include <QStyle>

#include <QDir>
#include <QDebug>



interface_modulos::interface_modulos()
{

}

interface_modulos::~interface_modulos()
{

}

void interface_modulos::maximize_restore(MainHome *self)
{
    bool status = GLOBAL_STATE;
    if(status == false){
        self->showMaximized();
        GLOBAL_STATE = true;
        self->ui->appMargins->setContentsMargins(0, 0, 0, 0);
        self->ui->maximizeRestoreAppBtn->setToolTip("Restore");
        self->ui->maximizeRestoreAppBtn->setIcon(QIcon(":/icons/images/icons/icon_restore.png"));
        self->ui->frame_size_grip->hide();
//        self->left_grip->hide();
//        self->right_grip->hide();
//        self->top_grip->hide();
//        self->bottom_grip->hide();
    } else {
        GLOBAL_STATE = false;
        self->showNormal();
        self->resize(self->width()+1, self->height()+1);
        self->ui->appMargins->setContentsMargins(10, 10, 10, 10);
        self->ui->maximizeRestoreAppBtn->setToolTip("Maximize");
        self->ui->maximizeRestoreAppBtn->setIcon(QIcon(":/icons/images/icons/icon_maximize.png"));
        self->ui->frame_size_grip->show();
//        self->left_grip->show();
//        self->right_grip->show();
//        self->top_grip->show();
//        self->bottom_grip->show();
    }

}

static QString MENU_SELECTED_STYLESHEET = " border-left: 22px solid qlineargradient(spread:pad, x1:0.034, y1:0, x2:0.216, y2:0, stop:0.499 rgba(255, 121, 198, 255), stop:0.5 rgba(85, 170, 255, 0)); background-color: rgb(40, 44, 52);";


QString interface_modulos::selectMenu(QString getStyle)
{
    QString select = getStyle + MENU_SELECTED_STYLESHEET;
    return select;
}

QString interface_modulos::deselectMenu(QString getStyle)
{
    QString deselect = getStyle.replace(MENU_SELECTED_STYLESHEET, "");
    return deselect;
}

void interface_modulos::selectStandardMenu(MainHome *self, QWidget *widget)
{
    QList<QPushButton *> list = self->ui->topMenu->findChildren<QPushButton *>();
    for (int i = 0; i < list.size(); i++) {
        if (list.at(i)->objectName() == widget->objectName()) {
            list.at(i)->setStyleSheet(selectMenu(list.at(i)->styleSheet()));
        }
    }
}

void interface_modulos::resetStyle(MainHome *self, QWidget *widget)
{
    QList<QPushButton *> list = self->ui->topMenu->findChildren<QPushButton *>();
    for (int i = 0; i < list.size(); i++) {
        if (list.at(i)->objectName() != widget->objectName()) {
            list.at(i)->setStyleSheet(deselectMenu(list.at(i)->styleSheet()));
        }
    }
}

void interface_modulos::dobleClickMaximizeRestore(MainHome *self, QMouseEvent *event)
{

}

void interface_modulos::uiDefinitions(MainHome)
{

}



void interface_modulos::toggleMenu(MainHome *self, bool enable)
{
    int width;
    int maxExtend;
    int standard;
    int widthExtended;

    if(enable){
        //get width
        width = self->ui->leftMenuBg->width();
        maxExtend = 240;
        standard = 60;

        //set max width
        if(width == 60){
            widthExtended = maxExtend;
        } else {
            widthExtended = standard;
        }

        //set animation
        self->animation = new QPropertyAnimation(self->ui->leftMenuBg, "minimumWidth");
        self->animation->setDuration(750);
        self->animation->setStartValue(width);
        self->animation->setEndValue(widthExtended);
        self->animation->setEasingCurve(QEasingCurve::InOutQuart);
        self->animation->start();
    }
}

void interface_modulos::toggleLeftBox(MainHome *self, bool enable)
{
    int widthRightBox = 0;
    int width = 0;
//    int maxExtende = 0;
    //if press mouse left button
    if(enable){
        //get width of Qframe
        width = self->ui->extraLeftBox->width();
        //get widht of QFrame extraRightBox
        widthRightBox = self->ui->extraRightBox->width();
//        maxExtende = 240;
        auto color = "background-color: rgb(44, 49, 58)";
        //auto standard = 0;

        //get btn style
        QString style = self->ui->toggleLeftBox->styleSheet();

        //set max width of QFrame extraLeftBox
        if(width == 0){
            //auto widthExtended = maxExtende;
            // select btn
            self->ui->toggleLeftBox->setStyleSheet(style + color);

            if(widthRightBox != 0){
                style = self->ui->settingsTopBtn->styleSheet();
                self->ui->settingsTopBtn->setStyleSheet(style.replace("background-color: rgb(44, 49, 58);", "background-color: rgb(44, 49, 58);"));
            }
            else {
                //widthExtended = standard;
                //reset btn
                self->ui->toggleLeftBox->setStyleSheet(style.replace("background-color: rgb(44, 49, 58);", "background-color: rgb(44, 49, 58);"));
            }
        }
    }
    start_box_animation(self, width, widthRightBox, "left");
}

void interface_modulos::toggleRightBox(MainHome *self, bool enable)
{
    int widthLeftBox = 0;
    int width = 0;
//    int maxExtende = 0;
    //if press mouse left button
    if(enable){
        //get width of Qframe
        width = self->ui->extraRightBox->width();
        //get widht of QFrame extraRightBox
        widthLeftBox = self->ui->extraLeftBox->width();
//        maxExtende = 240;
        auto color = "background-color: rgb(44, 49, 58)";
//        auto standard = 0;

        //get btn style
        QString style = self->ui->settingsTopBtn->styleSheet();

        //set max width of QFrame extraLeftBox
        if(width == 0){
//            auto widthExtended = maxExtende;
            // select btn
            self->ui->settingsTopBtn->setStyleSheet(style + color);

            if(widthLeftBox != 0){
                style = self->ui->toggleLeftBox->styleSheet();
                self->ui->toggleLeftBox->setStyleSheet(style.replace("background-color: rgb(44, 49, 58);", "background-color: rgb(44, 49, 58);"));
            }
            else {
//                widthExtended = standard;
                //reset btn
                self->ui->settingsTopBtn->setStyleSheet(style.replace("background-color: rgb(44, 49, 58);", "background-color: rgb(44, 49, 58);"));
            }
        }
    }
    start_box_animation(self, widthLeftBox, width, "right");
}

void interface_modulos::start_box_animation(MainHome *self, int left_box_width, int right_box_width, string direction)
{
    int right_width = 0;
    int left_width = 0;

    //check values
    if(left_box_width == 0 && direction == "left") {
        left_width = 240;
    }
    else {
        left_width = 0;
    }

    //check values
    if(right_box_width == 0 && direction == "right") {
        right_width = 240;
    }
    else {
        right_width = 0;
    }

    //animation left box
    self->left_box = new QPropertyAnimation(self->ui->extraLeftBox, "minimumWidth");
    self->left_box->setDuration(500);
    self->left_box->setStartValue(left_box_width);
    self->left_box->setEndValue(left_width);
    self->left_box->setEasingCurve(QEasingCurve::InOutQuart);

    //animation right box
    self->right_box = new QPropertyAnimation(self->ui->extraRightBox, "minimumWidth");
    self->right_box->setDuration(500);
    self->right_box->setStartValue(right_box_width);
    self->right_box->setEndValue(right_width);
    self->right_box->setEasingCurve(QEasingCurve::InOutQuart);

    //group animation
    self->group = new QParallelAnimationGroup();
    self->group->addAnimation(self->left_box);
    self->group->addAnimation(self->right_box);
    self->group->start();
}

void interface_modulos::theme(MainHome *self, QFile &file, bool use_theme)
{
    if(use_theme){
        QByteArray lineFile;
        QString styleFile;

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while(!file.atEnd()){
            lineFile = file.readLine();
            styleFile.append(lineFile);
        }


        self->ui->styleSheet->setStyleSheet(styleFile);

    }
}

void interface_modulos::set_theme(MainHome *self)
{
    self->ui->lineEdit->setStyleSheet("background-color: #6272a4;");
//    self->ui->pushButton_buscar->setStyleSheet("background-color: #6272a4;");
//    self->ui->plainTextEdit->setStyleSheet("background-color: #6272a4;");

// create QFile with direccion of file
    QFile file("../src/VentanaPrincipal/themes/widgets_dracula.qss");

    //set theme
    set_themeWidget(self->ui->widgets, file);

    // set spacing between rows in tableWidget
//    self->ui->scrollArea->setStyleSheet("QScrollBar:vertical { background: #6272a4; } QScrollBar:horizontal { background: #6272a4; }");
//    self->ui->comboBox->setStyleSheet("background-color: #6272a4;");
//    self->ui->horizontalScrollBar->setStyleSheet("background-color: #6272a4;");
//    self->ui->verticalScrollBar->setStyleSheet("background-color: #6272a4;");
//    self->ui->commandLinkButton->setStyleSheet("color: #ff79c6;");
}

void interface_modulos::set_themeWidget(QWidget *widget, QFile &file){
    QByteArray lineFile;
    QString styleFile;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while(!file.atEnd()){
        lineFile = file.readLine();
        styleFile.append(lineFile);
    }

    widget->setStyleSheet(styleFile);
}
