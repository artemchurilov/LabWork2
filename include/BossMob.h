/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef BOSSMOB_H
#define BOSSMOB_H

#include "GameObject.h"
#include <iostream>

/**
 * @class BossMob
 * @brief Represents a boss enemy on the game map.
 * @details Requires a minimum sword level to engage in combat. Triggers a special battle sequence.
 */
class BossMob : public GameObject
{
public:
    /**
     * @override
     * @brief Returns the boss's symbol.
     * @return 'B' (ASCII character).
     */
    char getSymbol() const override;

    /**
     * @override
     * @brief Checks if the boss can be traversed.
     * @return Always false (blocks movement).
     */
    bool isPassable() const override;

    /**
     * @override
     * @brief Initiates boss combat if the player meets the requirements.
     * @param state GameState to modify (HP, gold, messages).
     * @details
     * - Requires sword level 3 to start the fight.
     * - On victory: awards 1000 gold.
     * - On defeat: sets player HP to 0.
     */
    void interact(GameState& state) override;
};

#endif