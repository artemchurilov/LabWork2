/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H
#include "CardPlayer.h"
#include "Enemy.h"
#include "GameState.h"
#include <limits>

/**
 * @brief Manages the combat loop between the player and an enemy.
 * @details Handles turn-based gameplay, card selection, and battle UI rendering.
 */
class CombatSystem
{
    CardPlayer player;   ///< The player participating in combat.
    Enemy enemy;         ///< The enemy being fought.
    int turnNumber = 0;  ///< Current turn number.

    GameState& state;    ///< Reference to the game's persistent state (e.g., deck data).

public:
    /**
     * @brief Constructs a combat system with the game's current state.
     * @param s Reference to the GameState (used to initialize the player's deck).
     */
    CombatSystem(GameState& s);

    /**
     * @brief Clears invalid input from the input stream.
     * @details Used to recover from input errors during card selection.
     */
    void clearInput();

    /**
     * @brief Renders the battle UI, including player/enemy status and ASCII art.
     */
    void printBattleUI() const;

    /**
     * @brief Prints the list of cards in the player's hand with their energy costs.
     */
    void printHand(int selectedIndex);

    /**
     * @brief Starts and manages the combat loop.
     * @return true if the player wins, false if the player dies.
     * @details
     * - Alternates between player and enemy turns.
     * - Player plays cards until out of energy or ends the turn.
     * - Enemy uses up to two actions per turn.
     */
    bool startCombat();
    void playDeathAnimation();
};

#endif