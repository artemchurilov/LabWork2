/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Campfire.h"

/**
 * @brief Returns the campfire's visual symbol.
 * @return 'C' to represent the campfire on the map.
 */
char Campfire::getSymbol() const
{
    return 'C';
}

/**
 * @brief Handles interaction with the campfire.
 * @details
 * - Restores HP to 100 and energy to 50 if either is not at maximum.
 * - Advances the day counter (`state.day++`).
 * - Displays appropriate messages in `state.last_message`.
 * @param state GameState to modify.
 */
void Campfire::interact(GameState& state)
{
    if (state.inventory.hp < 100 || state.inventory.energy < 50)
    {
        state.inventory.hp = 100;
        state.inventory.energy = 50;
        state.day++;
        state.last_message =
            "Restored health and energy! New day: " +
            std::to_string(state.day);
    }
    else
    {
        state.last_message = "Already fully rested!";
    }
}