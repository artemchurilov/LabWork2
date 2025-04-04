/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAME_H
#define GAME_H

#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <cstdlib>
#include <string>
#include <chrono>
#include "GameMap.h"
#include "InputSystem.h"
#include "MainMenu.h"
#include "CardManager.h"
#include "GameState.h"

/**
 * @class Game
 * @brief Core class managing the game loop, input, and interactions.
 * @details Coordinates map rendering, player input, game state, and UI flows (menus, deck management).
 */
class Game
{
    GameMap gameMap;            ///< Manages the game grid and player position.
    GameState state;            ///< Tracks player stats, resources, and progression.
    bool running = true;        ///< Controls the main game loop (true = active).

    std::chrono::steady_clock::time_point lastUpdate; ///< Timestamp for update scheduling.
    bool showRules = false;     ///< Flag to toggle rules screen display.

public:
    /**
     * @brief Initializes the game and enables terminal raw mode.
     */
    Game();

    /**
     * @brief Restores terminal settings upon destruction.
     */
    ~Game();

    /**
     * @brief Displays the main menu and handles navigation.
     */
    void showMainMenu();

    /**
     * @brief Renders the game rules and controls screen.
     */
    void showRulesScreen();

    /**
     * @brief Replaces a card in the player's deck.
     * @param index Position of the card to replace (0-based).
     */
    void replaceCard(int index);

    /**
     * @brief Starts and manages the main game loop.
     */
    void run();

    /**
     * @brief Displays the player's current deck and allows card inspection.
     */
    void showDeck();

    /**
     * @brief Shows detailed information about a specific card.
     * @param card Name of the card to inspect.
     */
    void showCardDetails(const std::string& card);


    void selectDeck();

private:
    struct
    {
        bool w = false; ///< W key pressed.
        bool a = false; ///< A key pressed.
        bool s = false; ///< S key pressed.
        bool d = false; ///< D key pressed.
    } keys; ///< Tracks movement key states.

    /**
     * @brief Processes keyboard input for movement and actions.
     */
    void processInput();

    /**
     * @brief Triggers interaction with the current cell (e.g., objects/NPCs).
     */
    void interact();

    /**
     * @brief Updates game state (movement, timers, death checks).
     */
    void update();

    /**
     * @brief Handles player death (respawns at campfire, resets stats).
     */
    void handleDeath();

    /**
     * @brief Renders the game map and UI.
     */
    void render();
};

#endif