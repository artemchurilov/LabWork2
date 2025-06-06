/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Mob.h"

/**
 * @brief Constructs a Mob with a symbol, damage, and gold reward.
 * @param s Symbol (e.g., 'M' for regular mob, 'D' for boss).
 * @param dmg Damage dealt before shield reduction.
 * @param reward Gold added to the player's inventory.
 */
Mob::Mob(char s, int dmg, int reward)
    : symbol(s), base_damage(dmg), gold_reward(reward) {}

char Mob::getSymbol() const
{
    return symbol;
}

bool Mob::isPassable() const
{
    return false; // Mobs block movement
}

void Mob::interact(GameState& state)
{
    // Calculate damage after shield reduction (3 HP per shield level)
    int actual_damage = base_damage - (state.inventory.shield_level * 3);
    if (actual_damage < 0) actual_damage = 0;

    state.inventory.hp -= actual_damage;
    state.inventory.gold += gold_reward;

    // Update combat message
    state.last_message =
        "Fought " + std::string(1, symbol) + "! Lost " +
        std::to_string(actual_damage) + " HP. Got " +
        std::to_string(gold_reward) + " gold.";

    // Check for player death
    if (state.inventory.hp <= 0)
    {
        handleDeath(state);
    }
}

void Mob::handleDeath(GameState& state)
{
    state.last_message = "YOU DIED! All resources lost...";
    // Reset inventory but keep sword/shield upgrades
    state.inventory =
    {
        100,                       // HP
        50,                        // Energy
        0,                         // Gold
        0,                         // Wood
        0,                         // Stone
        state.inventory.sword_level,
        state.inventory.shield_level
    };
    state.day++; // Advance to the next day
}