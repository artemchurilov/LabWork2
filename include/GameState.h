/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>
#include <vector>

/**
 * @struct GameState
 * @brief Represents the global state of the game.
 * @details Tracks player progress, resources, inventory, and map-related data.
 */
struct GameState
{
    /**
     * @struct inventory
     * @brief Player's inventory and stats.
     */
    struct
    {
        int hp = 100;            ///< Current health points (0-100).
        int energy = 50;         ///< Current energy (used for actions).
        int gold = 0;            ///< Gold currency.
        int wood = 0;            ///< Wood resource (for crafting/upgrades).
        int stone = 0;           ///< Stone resource (for crafting/upgrades).
        int sword_level = 0;     ///< Sword upgrade level (starts at 0).
        int shield_level = 0;    ///< Shield upgrade level (starts at 0).
    } inventory;

    std::vector<std::string> deck_cards;    ///< All unlocked cards in the player's collection.
    std::vector<std::string> current_deck;  ///< Cards in the currently active deck.
    int day = 1;                            ///< Current day (progress counter).
    std::string last_message;               ///< Last game message to display (e.g., "Not enough energy!").
    int campfire_x = 3;                     ///< X-coordinate of the campfire on the map.
    int campfire_y = 1;                     ///< Y-coordinate of the campfire on the map.
};

#endif