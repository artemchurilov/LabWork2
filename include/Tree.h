/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef TREE_H
#define TREE_H

#include "GameObject.h"

/**
 * @class Tree
 * @brief Represents a tree resource node on the game map.
 * @details Requires energy to chop and provides wood resources.
 */
class Tree : public GameObject
{
public:
    /**
     * @override
     * @brief Returns the tree's symbol.
     * @return 'T' (ASCII character).
     */
    char getSymbol() const override;

    /**
     * @override
     * @brief Checks if the tree can be traversed.
     * @return Always false (blocks movement).
     */
    bool isPassable() const override;

    /**
     * @override
     * @brief Chops the tree if the player has enough energy.
     * @param state GameState to modify (energy, wood count, messages).
     * @details Costs 10 energy to chop. Fails if energy < 10.
     */
    void interact(GameState& state) override;
};

#endif