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
        InputSystem::enableRawMode();
        int selection = 0;
        while(true)
        {
            system("clear");
            printTitle();
            printOptions(selection);

            char c = InputSystem::getKey();
            if(c == 'w' && selection > 0) selection--;
            if(c == 's' && selection < 2) selection++;
            if(c == '\n') break;
        }
        InputSystem::disableRawMode();

        return static_cast<MainMenu::MenuResult>(selection);
    };
/**
 * @brief Renders the game rules and controls screen.
 * @details Uses ANSI codes for colored text.
 * Waits for any key press to return to the menu.
 */
    void showRulesScreen();
    void printTitle();

    bool showMainMenu(GameState& state, bool& running);
    void printOptions(int selected);
};

#endif