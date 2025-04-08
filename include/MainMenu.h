/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef MAINMENU_H
#define MAINMENU_H

#include "Game.h"
#include <iostream>

/**
 * @class MainMenu
 * @brief Handles the display and interaction logic for the game's main menu.
 * @details Manages menu navigation, rule screens, and delegates game state changes.
 */
class MainMenu {
public:
    /**
     * @enum MenuResult
     * @brief Possible outcomes of menu interaction.
     */
    enum MenuResult { 
        START,  ///< Start a new game.
        RULES,  ///< Show the rules screen.
        QUIT    ///< Exit the game.
    };

    /**
     * @brief Displays the main menu and processes user input.
     * @return MenuResult Selected menu option (START, RULES, or QUIT).
     * @details 
     * - Uses arrow keys (W/S) for navigation.
     * - Enter key confirms selection.
     * - Temporarily enables raw terminal input mode.
     */
    MenuResult show() {
        InputSystem::enableRawMode();
        int selection = 0;
        while(true) {
            system("clear");
            printTitle();
            printOptions(selection);

            char c = InputSystem::getKey();
            if(c == 'w' && selection > 0) selection--;
            if(c == 's' && selection < 2) selection++;
            if(c == '\n') break;
        }
        InputSystem::disableRawMode();
        return static_cast<MenuResult>(selection);
    }

    /**
     * @brief Renders the game rules and controls screen.
     * @details 
     * - Uses ANSI escape codes for colored text.
     * - Waits for any key press to return to the menu.
     */
    void showRulesScreen();

    /**
     * @brief Prints the main menu title.
     */
    void printTitle();

    /**
     * @brief Manages the main menu interaction loop.
     * @param state Reference to the game's state (modified on START).
     * @param running Flag controlling the game loop (set to false on QUIT).
     * @return bool Whether to continue running the game (false if QUIT is selected).
     */
    bool showMainMenu(GameState& state, bool& running);

    /**
     * @brief Displays menu options with highlighting for the selected item.
     * @param selected Index of the currently selected menu option.
     */
    void printOptions(int selected);
};

#endif