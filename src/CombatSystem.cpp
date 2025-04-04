
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/CombatSystem.h"
#include <algorithm>
#include "../include/AttackCard.h"
#include "../include/DefendCard.h"
#include "../include/ComboCard.h"
#include "../include/HealCard.h"
#include <random>
#include "../include/Game.h"

/**
 * @brief Initializes the player's deck based on the GameState and shuffles it.
 * @details Maps card names from `state.current_deck` to concrete card types:
 * - "Strike" → AttackCard (6 damage)
 * - "Defend" → DefendCard (5 block)
 * - "Fist Punch" → AttackCard (12 damage)
 * - ... (other cards similarly mapped)
 * - Shuffles the deck using a Mersenne Twister RNG.
 */
CombatSystem::CombatSystem(GameState& s):state(s)
{
    for(const auto& cardName : state.current_deck)
    {
        if(cardName == "Strike")
        {
            player.deck.push_back(std::make_unique<AttackCard>(1,"Strike",6));
        }
        else if(cardName == "Defend")
        {
            player.deck.push_back(std::make_unique<DefendCard>(1,"Defend",5));
        }
        else if(cardName == "Fist Punch")
        {
            player.deck.push_back(std::make_unique<AttackCard>(1,"Fist Punch",12));
        }
        else if(cardName == "Arm Block")
        {
            player.deck.push_back(std::make_unique<DefendCard>(1,"Defend",8));
        }
        else if(cardName == "Arm Heal")
        {
            player.deck.push_back(std::make_unique<HealCard>(1,"Arm Heal",9));
        }
        else if(cardName == "Leg Heal")
        {
            player.deck.push_back(std::make_unique<HealCard>(1,"Leg Heal",8));
        }
        else if(cardName == "Leg Block")
        {
            player.deck.push_back(std::make_unique<DefendCard>(1,"Defend",12));
        }
        else if(cardName == "Arm Combo")
        {
            player.deck.push_back(std::make_unique<ComboCard>(1,"Arm Combo",6,5));
        }
        else if(cardName == "Leg Combo")
        {
            player.deck.push_back(std::make_unique<ComboCard>(1,"Leg Combo",5,6));
        }
        else if(cardName == "Foot Punch")
        {
            player.deck.push_back(std::make_unique<AttackCard>(1,"Foot Punch",5));
        }
        else if(cardName == "Ultra Duper Kick")
        {
            player.deck.push_back(std::make_unique<DefendCard>(1,"Ultra Duper Kick",100));
        }
        else if(cardName == "Ultra Duper Punch")
        {
            player.deck.push_back(std::make_unique<AttackCard>(1,"Ultra Duper Punch",100));
        }
        else if(cardName == "AutoRepair")
        {
            player.deck.push_back(std::make_unique<HealCard>(3,"AutoRepair",20));
        }
        else if(cardName == "StrongestSpell")
        {
            player.deck.push_back(std::make_unique<HealCard>(1,"StrongestSpell",-100));
        }
        else if(cardName == "Clink-clock")
        {
            player.deck.push_back(std::make_unique<AttackCard>(1,"Click-clock",0));
        };
    };

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(player.deck.begin(), player.deck.end(), g);
}

/**
 * @brief Clears input buffer to handle invalid user input.
 */

void CombatSystem::clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/**
 * @brief Prints the player's current hand with indices and energy costs.
 */
void CombatSystem::printHand()
{
    std::cout << "\nYour hand:\n";
    for(size_t i = 0; i < player.getHand().size(); ++i)
    {
        std::cout << i+1 << ". " << player.getHand()[i]->getName()
                  << " (Cost: " << player.getHand()[i]->getEnergyCost() << ")\n";
    }
}
/**
 * @brief Executes the combat loop until the player or enemy dies.
 * @details
 * - Each turn:
 *   1. Player draws cards and gains energy.
 *   2. Player selects cards to play or ends the turn.
 *   3. Enemy uses up to two actions.
 * - Returns victory status for post-combat logic (e.g., rewards).
 */
bool CombatSystem::startCombat()
{
    while (player.isAlive() && enemy.isAlive())
    {
        turnNumber++;
        player.startTurn();

        while (player.getEnergy() > 0 && !player.getHand().empty())
        {
            bool endTurn = false;
            while (true)
            {
                printBattleUI();
                printHand();
                std::cout << "Choose a card (1-" << player.getHand().size()
                          << ") or 0 to end turn: ";

                int choice;
                if (!(std::cin >> choice))
                {
                    clearInput();
                    continue;
                }

                if (choice == 0)
                {
                    endTurn = true;
                    break;
                }

                if (choice < 0 || choice > static_cast<int>(player.getHand().size()))
                {
                    std::cout << "Invalid choice!\n";
                    continue;
                }

                size_t index = choice - 1;
                auto& card = player.getHand()[index];

                if (card->getEnergyCost() > player.getEnergy())
                {
                    std::cout << "Not enough energy!\n";
                    continue;
                }

                card->play(player, enemy);
                player.getHand().erase(player.getHand().begin() + index);
                break;
            }

            if (endTurn)
                break;
        }

        if (enemy.isAlive())
        {
            printBattleUI();
            enemy.executeTurn(player);
            usleep(2000000);
        }
    }
    return player.isAlive();
}
/**
 * @brief Renders the battle UI with ASCII art and statuses.
 * @note Uses `system("clear")` for console clearing (platform-dependent).
 */
void CombatSystem::printBattleUI()const
{
    std::cout << "\033c";
    std::cout << R"(
  ╔════════════════════════╗
  ║       BATTLE ARENA     ║
  ╚════════════════════════╝
)" << '\n';

std::cout << R"(
        ,     \    /      ,        
      -/_\-   )\__/(    -/_\-       
     -/   \- (_\  /_)  -/   \-     
 ____/_____\__\@  @/___/_____\____ 
|             |\../|              |
|              \VV/               |
)" << "\n";

std::cout << "\n=== Turn " << turnNumber << " ===\n";
player.printStatus();
enemy.printStatus();

std::cout << R"(
  ╔════════════════════════╗
  ║ CARDS IN HAND          ║
  ╚════════════════════════╝
)" << '\n';
}
