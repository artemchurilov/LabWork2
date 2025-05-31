/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Game.h"
#include "../include/const.h"
#include "../include/DeckSelector.h"
#include "../include/DeckManager.h"

/**
 * @brief Game constructor. Initializes the map and enables terminal raw mode.
 * @details
 * - Creates a map of size MAP_WIDTH x MAP_HEIGHT.
 * - Activates raw mode for input handling without waiting for Enter.
 */
Game::Game() : gameMap(MAP_WIDTH, MAP_HEIGHT)
{
    InputSystem::enableRawMode();
}
/**
 * @brief Restores terminal settings when the game exits.
 */
Game::~Game()
{
    InputSystem::disableRawMode();
}

/**
 * @brief Manages the main menu interaction loop.
 * @post Updates `running` flag based on user choice.
 */
void Game::showMainMenu()
{
    MainMenu menu;
    bool shouldContinue = menu.showMainMenu(state, running);
    if (!shouldContinue)
    {
        running = false; // Propagate quit decision to game loop
    }
}

/**
 * @brief Initializes deck selection process.
 * @post Modifies `state.current_deck` with selected cards.
 */
void Game::selectDeck()
{
    DeckSelector selector;
    selector.selectDeck(state); // Delegate to DeckSelector
}

/**
 * @brief Triggers display of game rules.
 * @details Uses ANSI escape codes for formatted output.
 */
void Game::showRulesScreen()
{
    MainMenu menu;
    menu.showRulesScreen(); // Delegate to MainMenu
}

/**
 * @brief Replaces a card in the player's deck.
 * @param index Position of the card to replace (0-based).
 * @post Modifies `state.current_deck`.
 */
void Game::replaceCard(int index)
{
    DeckManager::replaceCard(state, index); // Delegate to DeckManager
}

/**
 * @brief Renders the player's deck with colored card names.
 * @details Temporarily disables raw input mode for text interaction.
 */
void Game::showDeck()
{
    DeckManager::showDeck(state); // Delegate to DeckManager
}

/**
 * @brief Displays card metadata (color-coded name and description).
 * @param card Name of the card to display.
 * @note Returns to deck view after key press.
 */
void Game::showCardDetails(const std::string& card)
{
    DeckManager::showCardDetails(card); // Delegate to DeckManager
}

/**
 * @brief Starts the main game loop.
 * @details The loop runs every 100 ms:
 * 1. Process input
 * 2. Update state
 * 3. Render
 */
void Game::run()
{
    showMainMenu();
    while(running)
    {
        processInput();
        update();
        render();
        usleep(100000);
    }
}

/**
 * @brief Processes keyboard input.
 * @details Supported keys:
 * - WASD: Movement
 * - B: Toggle map
 * - Q: Quit
 * - C: View deck
 */
void Game::processInput()
{
    while(InputSystem::keyPressed())
    {
        char c = InputSystem::getKey();
        int dx = 0, dy = 0;

        switch(c)
        {
        case 'w':
        case 'W':
            dy = -1;
            break;

        case 's':
        case 'S':
            dy = 1;
            break;

        case 'a':
        case 'A':
            dx = -1;
            break;

        case 'd':
        case 'D':
            dx = 1;
            break;

        case 'b':
        case 'B':
            gameMap.toggleMap();
            break;

        case 'q':
        case 'Q':
            InputSystem::enableRawMode();
            usleep(500000);
            running = false;
            break;
        case 'c':
        case 'C':
            showDeck();
            break;
        }

        if(dx != 0 || dy != 0)
        {
            gameMap.movePlayer(dx, dy, state);
        }
    }
}

void Game::interact()
{
    int px, py;
    gameMap.getPlayerPos(px, py);
    gameMap.interactAt(px, py, state);
}
/**
 * @brief Updates game state: movement, death, time.
 */
void Game::update()
{
    auto now = std::chrono::steady_clock::now();
    lastUpdate = now;

    int dx = 0, dy = 0;
    if(keys.w) dy -= 1;
    if(keys.s) dy += 1;
    if(keys.a) dx -= 1;
    if(keys.d) dx += 1;

    gameMap.movePlayer(dx, dy, state);

    keys = {false, false, false, false};

    if(state.inventory.hp <= 0) handleDeath();
}
/**
 * @brief Handles player death.
 * @details:
 * - Restores HP and energy
 * - Teleports to campfire
 * - Increments day counter
 */
void Game::handleDeath()
{
    state.inventory.hp = 100;
    state.inventory.energy = 50;
    state.day++;
    gameMap.setPlayerPos(state.campfire_x, state.campfire_y);
    state.last_message = "Respawned at campfire! Day " + std::to_string(state.day);
}
/**
 * @brief Renders the game interface.
 * @details Delegates map rendering to the `gameMap` object.
 */
void Game::render()
{
    gameMap.render(state);
};