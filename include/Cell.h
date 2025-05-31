/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef CELL_H
#define CELL_H

#include <memory>
#include "GameObject.h"

/**
 * @brief Represents types of terrain for a cell.
 */
enum class TerrainType
{
    GROUND, ///< Default passable terrain.
    WATER   ///< Non-passable terrain.
};

/**
 * @brief Represents a single cell in the game map.
 * @details Combines terrain type and optional game object for grid-based interactions.
 */
class Cell
{
public:
    Cell();

    /**
     * @brief Sets the terrain type of the cell.
     * @param type TerrainType to assign (GROUND/WATER).
     */
    void setTerrain(TerrainType type);

    /**
     * @brief Places a game object in the cell.
     * @param obj Shared pointer to the GameObject.
     */
    void setObject(std::shared_ptr<GameObject> obj);

    /**
     * @brief Returns the visual symbol representing the cell.
     * @return '.' for GROUND, '~' for WATER, or the object's symbol.
     */
    char getSymbol() const;

    /**
     * @brief Triggers interaction with the cell's object (if any).
     * @param state Reference to the GameState to modify.
     */
    void interact(GameState& state) const;

    /**
     * @brief Checks if the cell can be traversed.
     * @return false if WATER or object is non-passable, true otherwise.
     */
    bool isPassable() const;

private:
    TerrainType terrain = TerrainType::GROUND;
    std::shared_ptr<GameObject> object; ///< Object placed in the cell (nullable).
};

#endif