/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include "GameObject.h"

/**
 * @class Campfire
 * @brief Represents a campfire object that restores player health and energy.
 * @details Allows the player to rest and start a new day.
 */
class Campfire : public GameObject
{
public:
    /**
     * @override
     * @brief Returns the campfire's symbol.
     * @return 'C' (ASCII character).
     */
    char getSymbol() const override;

    /**
     * @override
     * @brief Restores player health/energy and advances the day if not fully rested.
     * @param state GameState to modify (HP, energy, day counter, messages).
     */
    void interact(GameState& state) override;
};

#endif