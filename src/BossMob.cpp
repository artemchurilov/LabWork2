/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "BossMob.h"
#include "Game.h"
#include "CombatSystem.h"

char BossMob::getSymbol() const
{
    return 'B';
}
bool BossMob::isPassable() const
{
    return false;
}

void BossMob::interact(GameState& state)
{
    if(state.inventory.sword_level < 3)
    {
        state.last_message = "You need sword level 3 to fight boss!";
        return;
    }

    disableRawMode();

    CombatSystem battle(state);
    bool victory = battle.startCombat();

    if(victory)
    {
        state.inventory.gold += 1000;
        state.last_message = "BOSS DEFEATED! Got 1000 gold!";
    }
    else
    {
        state.inventory.hp = 0;
        state.last_message = "You were defeated by the boss!";
    }

    enableRawMode();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};