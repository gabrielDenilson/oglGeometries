#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>



class Settings
{
public:
    Settings();

    static bool ENABLE_CUSTOM_TITLE_BAR;
    static int MENU_WIDTH;
    static int LEFT_BOX_WIDTH;
    static int RIGHT_BOX_WIDTH;
    static int TIME_ANIMATION;

    // BTNS LEFT AND RIGHT BOX COLORS
    static QString BTN_LEFT_BOX_COLOR;
    static QString BTN_RIGHT_BOX_COLOR;
    static QString  MENU_SELECTED_STYLESHEET ;
//    # MENU SELECTED STYLESHEET

};
#endif // SETTINGS_H

