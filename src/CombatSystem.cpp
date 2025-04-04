
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
void CombatSystem::clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CombatSystem::printHand()
{
    std::cout << "\nYour hand:\n";
    for(size_t i = 0; i < player.getHand().size(); ++i)
    {
        std::cout << i+1 << ". " << player.getHand()[i]->getName()
                  << " (Cost: " << player.getHand()[i]->getEnergyCost() << ")\n";
    }
}

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

void CombatSystem::printBattleUI()const
{
    system("clear");
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
