/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/BossMob.h"
#include "../include/Game.h"
#include "../include/CombatSystem.h"

/**
 * @brief Returns the boss's visual symbol.
 * @return 'B' to represent the boss on the map.
 */
char BossMob::getSymbol() const
{
    return 'B';
}

/**
 * @brief Checks if the boss is passable.
 * @return false (boss blocks movement).
 */
bool BossMob::isPassable() const
{
    return false;
}

/**
 * @brief Handles interaction with the boss.
 * @param state GameState to modify.
 * @details
 * - Checks if the player has sword level 3. If not, blocks combat.
 * - Disables raw terminal input during combat.
 * - Starts a CombatSystem battle sequence.
 * - Updates gold or HP based on the battle outcome.
 * - Restores terminal settings after combat.
 */
void BossMob::interact(GameState& state)
{
    if (state.inventory.sword_level < 3)
    {
        state.last_message = "You need sword level 3 to fight boss!";
        return;
    }

    InputSystem::disableRawMode(); // Disable terminal raw mode for combat input

    CombatSystem battle(state);
    bool victory = battle.startCombat();

    if (victory)
    {
        state.inventory.gold += 1000;
        state.last_message = "BOSS DEFEATED! Got 1000 gold!";
    }
    else
    {
        state.inventory.hp = 0;
        state.last_message = "You were defeated by the boss!";
    }

    InputSystem::enableRawMode(); // Restore terminal settings
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}