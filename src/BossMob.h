/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef BOSSMOB_H
#define BOSSMOB_H
#include "GameObject.h"
#include <iostream>
#include "InputSystem.h"
#include "CombatSystem.h"
class BossMob : public GameObject {
    public:
        char getSymbol() const override { return 'B'; }
        bool isPassable() const override { return false; }
        
        void interact(GameState& state) override {
            disableRawMode();
            std::system("clear");
            std::cout << "=== BOSS BATTLE ===" << std::endl;
            
            CombatSystem battle;
            bool victory = battle.startCombat();
            
            if(victory) {
                state.inventory.gold += 1000;
                state.last_message = "BOSS DEFEATED! Got 1000 gold!";
            } else {
                state.inventory.hp = std::max(state.inventory.hp - 50, 0);
                state.last_message = "You were defeated by the boss! Lost 50 HP!";
            }
            
            enableRawMode(); // Возвращаем raw mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    };
    

#endif