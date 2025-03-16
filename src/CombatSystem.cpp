
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "CombatSystem.h"
#include <algorithm>

CombatSystem::CombatSystem(GameState& s):state(s){};

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
    while(player.isAlive() && enemy.isAlive())
    {
        turnNumber++;
        player.startTurn();

        std::cout << "\n=== Turn " << turnNumber << " ===\n";
        player.printStatus();
        enemy.printStatus();

        while(player.getEnergy() > 0 && !player.getHand().empty())
        {
            printHand();
            std::cout << "Choose a card (1-" << player.getHand().size()
                      << ") or 0 to end turn: ";

            int choice;
            if(!(std::cin >> choice))
            {
                clearInput();
                continue;
            }

            if(choice == 0) break;
            if(choice < 0 || choice > static_cast<int>(player.getHand().size()))
            {
                std::cout << "Invalid choice!\n";
                continue;
            }

            std::size_t index = choice - 1;
            auto& card = player.getHand()[index];

            if(card->getEnergyCost() > player.getEnergy())
            {
                std::cout << "Not enough energy!\n";
                continue;
            }

            card->play(player, enemy);
            player.getHand().erase(player.getHand().begin() + index);
        }

        if(enemy.isAlive())
        {
            enemy.executeTurn(player);
        }
    }
    return player.isAlive();
}

void CombatSystem::applyCardEffects(CardPlayer& player, const std::string& cardName) {
    auto it = find(state.deck_cards.begin(), state.deck_cards.end(), cardName);
    if(it == state.deck_cards.end()) return;

    
    if(cardName == "Fist Punch") {
        std::cout<<"You used Punch";
        player.addBlock(105);
    }
}