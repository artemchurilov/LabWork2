/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef STONE_H
#define STONE_H

#include "GameObject.h"

/**
 * @class Stone
 * @brief Represents a stone resource node on the game map.
 * @details Requires energy to mine and provides stone resources.
 */
class Stone : public GameObject
{
public:
    /**
     * @override
     * @brief Returns the stone's symbol.
     * @return 'S' (ASCII character).
     */
    char getSymbol() const override;

    /**
     * @override
     * @brief Checks if the stone can be traversed.
     * @return Always false (blocks movement).
     */
    bool isPassable() const override;

    /**
     * @override
     * @brief Mines the stone if the player has enough energy.
     * @param state GameState to modify (energy, stone count, messages).
     * @details Costs 15 energy to mine. Fails if energy < 15.
     */
    void interact(GameState& state) override;
};

#endif