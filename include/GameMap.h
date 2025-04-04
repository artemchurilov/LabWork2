/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "../include/Cell.h"
/**
 * @class GameMap
 * @brief Manages the game grid, player movement, and object interactions.
 */
class GameMap
{
public:
    /**
     * @brief Constructs a GameMap with specified dimensions.
     * @param width Number of columns.
     * @param height Number of rows.
     */
    GameMap(int width, int height);

    /**
     * @brief Moves the player by (dx, dy) if the target cell is passable.
     * @param dx X-axis delta (-1, 0, +1).
     * @param dy Y-axis delta (-1, 0, +1).
     * @param state Reference to the GameState for interaction checks.
     */
    void movePlayer(int dx, int dy, GameState& state);

    /**
     * @brief Renders the map and player status to the console.
     * @note Uses ANSI escape codes for colors. Platform-dependent (Unix only).
     */
    void render(const GameState& state) const;

    /**
     * @brief Triggers interaction at coordinates (x, y).
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @param state GameState to modify during interaction.
     */
    void interactAt(int x, int y, GameState& state);

    /**
     * @brief Returns the player's current position.
     * @param[out] x X-coordinate (column).
     * @param[out] y Y-coordinate (row).
     */
    void getPlayerPos(int& x, int& y) const;

    /**
     * @brief Sets the player's position (no passability check).
     * @param x New X-coordinate.
     * @param y New Y-coordinate.
     */
    void setPlayerPos(int x, int y);

    /**
     * @brief Toggles between default and alternate maps (e.g., boss arena).
     * @details Resets player position to (0, 0) and ensures it is passable.
     */
    void toggleMap();

    /**
     * @brief Places a GameObject at (x, y).
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @param obj GameObject to place.
     */
    void placeObject(int x, int y, std::shared_ptr<GameObject> obj);

    /**
     * @brief Prints an inventory stat line next to the map.
     * @param line Line number (0-4 for HP, Energy, Gold, Wood, Stone).
     * @param state GameState for inventory data.
     */
    void printInventoryLine(int line, const GameState& state) const;

    /**
     * @brief Initializes the map layout with objects.
     * @details Populates cells based on `alternateMap` flag:
     * - Default map: Campfire, Shop, Mobs, etc.
     * - Alternate map: BossMob and Campfire.
     */
    void initMap();

    /**
     * @brief Checks if a cell is passable.
     * @param x X-coordinate.
     * @param y Y-coordinate.
     * @return false if out of bounds, WATER, or blocked by a GameObject.
     */
    bool isPassable(int x, int y) const;

private:
    int width, height;             ///< Map dimensions.
    int playerX = 0, playerY = 0; ///< Player coordinates (column, row).
    bool alternateMap = false;     ///< Flag for alternate map layout.
    std::vector<std::vector<Cell>> grid; ///< 2D grid of cells (row-major order).
};

#endif