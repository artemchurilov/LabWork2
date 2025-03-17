/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Mob.h"

Mob::Mob(char s, int dmg, int reward): symbol(s), base_damage(dmg), gold_reward(reward) {}
char Mob::getSymbol() const
{
    return symbol;
};
bool Mob::isPassable() const
{
    return false;
};
void Mob::interact(GameState& state)
{
    int actual_damage = base_damage - (state.inventory.shield_level * 5);
    if(actual_damage < 0) actual_damage = 0;

    state.inventory.hp -= actual_damage;
    state.inventory.gold += gold_reward;
    state.last_message = "Fought " + std::string(1, symbol) + "! Lost " +
                         std::to_string(actual_damage) + " HP. Got " +
                         std::to_string(gold_reward) + " gold.";

    if(state.inventory.hp <= 0)
    {
        handleDeath(state);
    }
}

void Mob::handleDeath(GameState& state)
{
    state.last_message = "YOU DIED! All resources lost...";
    state.inventory = {100, 50, 0, 0, 0,
                       state.inventory.sword_level,
                       state.inventory.shield_level
                      };
    state.day++;
}