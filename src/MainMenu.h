/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"
#include <iostream>

class MainMenu
{
public:
    enum MenuResult { START, RULES, QUIT };

    MenuResult show()
    {
        enableRawMode();
        int selection = 0;
        while(true)
        {
            system("clear");
            printTitle();
            printOptions(selection);

            char c = getKey();
            if(c == 'w' && selection > 0) selection--;
            if(c == 's' && selection < 2) selection++;
            if(c == '\n') break;
        }
        disableRawMode();

        return static_cast<MainMenu::MenuResult>(selection);
    };
    void printTitle();
    void printOptions(int selected);
};

#endif