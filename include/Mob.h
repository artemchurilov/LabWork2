/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/


#ifndef MOB_H
#define MOB_H

#include "GameObject.h"

/**
 * @class Mob
 * @brief Represents an enemy entity on the game map.
 * @details Blocks movement and triggers combat when interacted with.
 */
class Mob : public GameObject
{
public:
    /**
     * @brief Constructs a Mob with specified properties.
     * @param s Symbol representing the mob (e.g., 'M', 'D').
     * @param dmg Base damage dealt to the player.
     * @param reward Gold awarded when defeated.
     */
    Mob(char s, int dmg, int reward);

    /**
     * @override
     * @brief Returns the mob's symbol (ASCII character).
     * @return Symbol (e.g., 'M' for generic mob).
     */
    char getSymbol() const override;

    /**
     * @override
     * @brief Checks if the mob can be traversed.
     * @return Always returns false (mobs block movement).
     */
    bool isPassable() const override;

    /**
     * @override
     * @brief Handles combat interaction with the player.
     * @param state GameState to modify (HP, gold, messages).
     * @details
     * - Damage is reduced by the player's shield level.
     * - Awards gold even if the player dies.
     */
    void interact(GameState& state) override;

private:
    char symbol;       ///< Visual representation (e.g., 'M').
    int base_damage;   ///< Base damage before shield reduction.
    int gold_reward;   ///< Gold granted on interaction.

    /**
     * @brief Resets the player's state on death.
     * @param state GameState to modify.
     * @details
     * - Resets HP to 100, energy to 50, and clears resources.
     * - Increments the day counter.
     * - Preserves sword/shield upgrades.
     */
    void handleDeath(GameState& state);
};

#endif