/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Mob.h"

Mob::Mob(char s, int dmg, int reward): symbol(s), damage(dmg), gold_reward(reward) {}
char Mob::getSymbol() const
{
    return symbol;
};
bool Mob::isPassable() const
{
    return false;
};
void Mob::interact(GameState& state) const
{
    state.inventory.hp -= damage;
    state.inventory.energy -= 20;
    state.inventory.gold += gold_reward;
}