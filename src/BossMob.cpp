#include "BossMob.h"
#include "InputSystem.h"
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
    disableRawMode();
    std::system("clear");
    std::cout << "=== BOSS BATTLE ===" << std::endl;

    CombatSystem battle;
    bool victory = battle.startCombat();

    if(victory)
    {
        state.inventory.gold += 1000;
        state.last_message = "BOSS DEFEATED! Got 1000 gold!";
    }
    else
    {
        state.inventory.hp = std::max(state.inventory.hp - 50, 0);
        state.last_message = "You were defeated by the boss! Lost 50 HP!";
    }

    enableRawMode();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};
