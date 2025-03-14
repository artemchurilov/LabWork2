/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef BOSSMOB_H
#define BOSSMOB_H
#include "GameObject.h"
#include <iostream>
class BossMob : public GameObject {
    public:
        BossMob() : health(1000), base_damage(50), symbol('B') {}
        
        char getSymbol() const override { return symbol; }
        bool isPassable() const override { return false; }
        
        void interact(GameState& state) override {
            system("clear");
            std::cout << R"(
              ╔══╗
              ║  ║
              ║  ║  BOSS FIGHT!
             ╔╝  ║
            ╔╝   ║
            ╚═══╗║
                ║║
            )" << '\n';
            
            while(health > 0 && state.inventory.hp > 0) {
                // Атака игрока
                int player_damage = 10 * state.inventory.sword_level;
                health -= player_damage;
                
                // Атака босса
                int boss_damage = base_damage - (state.inventory.shield_level * 3);
                if(boss_damage < 0) boss_damage = 0;
                state.inventory.hp -= boss_damage;
                
                std::cout << "You hit boss for " << player_damage << " damage!\n";
                std::cout << "Boss hits you for " << boss_damage << " damage!\n";
                std::cout << "Your HP: " << state.inventory.hp << "\n";
                std::cout << "Boss HP: " << health << "\n\n";
                
                if(health <= 0) {
                    state.inventory.gold += 1000;
                    state.last_message = "BOSS DEFEATED! Got 1000 gold!";
                    std::cout << "Press ENTER to continue...";
                    std::string tmp;
                    std::getline(std::cin, tmp);
                    return;
                }
                
                if(state.inventory.hp <= 0) break;
                
                std::cout << "Press ENTER to continue fighting...";
                std::string tmp;
                std::getline(std::cin, tmp);
                system("clear");
            }
            
            state.last_message = "You were defeated by the boss!";
            state.inventory.hp = 1;
        }
    
    private:
        int health;
        int base_damage;
        char symbol;
    };

#endif