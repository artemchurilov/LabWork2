/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameState.h"

/**
 * @class GameObject
 * @brief Base class for interactive objects on the game map.
 * @details Inherited by objects like trees, mobs, and shops.
 */
class GameObject
{
public:
    virtual ~GameObject() = default;

    /**
     * @brief Returns the symbol representing the object (ASCII character).
     * @pure Must be implemented by derived classes.
     */
    virtual char getSymbol() const = 0;

    /**
     * @brief Checks if the object allows movement through its cell.
     * @return true by default (override for non-passable objects).
     */
    virtual bool isPassable() const;

    /**
     * @brief Triggers interaction with the object (e.g., combat, trading).
     * @param state GameState to modify during interaction.
     * @note Default implementation does nothing (override for functionality).
     */
    virtual void interact(GameState&) {};
};

#endif