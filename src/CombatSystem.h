/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H
#include "CardPlayer.h"
#include "Enemy.h"
#include <limits>
class CombatSystem {
    CardPlayer player;
    Enemy enemy;
    int turnNumber = 0;

    void clearInput() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void printHand() {
        std::cout << "\nYour hand:\n";
        for(size_t i = 0; i < player.getHand().size(); ++i) {
            std::cout << i+1 << ". " << player.getHand()[i]->getName()
                 << " (Cost: " << player.getHand()[i]->getEnergyCost() << ")\n";
        }
    }

public:
    bool startCombat() {
        while(player.isAlive() && enemy.isAlive()) {
            turnNumber++;
            player.startTurn();
            
            std::cout << "\n=== Turn " << turnNumber << " ===\n";
            player.printStatus();
            enemy.printStatus();

            while(player.getEnergy() > 0 && !player.getHand().empty()) {
                printHand();
                std::cout << "Choose a card (1-" << player.getHand().size() 
                     << ") or 0 to end turn: ";
                
                int choice;
                if(!(std::cin >> choice)) {
                    clearInput();
                    continue;
                }

                if(choice == 0) break;
                if(choice < 0 || choice > static_cast<int>(player.getHand().size())) {
                    std::cout << "Invalid choice!\n";
                    continue;
                }

                std::size_t index = choice - 1;
                auto& card = player.getHand()[index];
                
                if(card->getEnergyCost() > player.getEnergy()) {
                    std::cout << "Not enough energy!\n";
                    continue;
                }

                card->play(player, enemy);
                player.getHand().erase(player.getHand().begin() + index);
            }

            if(enemy.isAlive()) {
                enemy.executeTurn(player);
            }
        }
        return player.isAlive();
    }
};
#endif