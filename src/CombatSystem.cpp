
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
#include "../include/const.h"
#include "../include/Game.h"

#include <thread>


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


/**
 * @brief Prints the player's current hand with indices and energy costs.
 */
void CombatSystem::printHand(int selectedIndex) {
    std::cout << YELLOW << "\n=== YOUR HAND ===\n" << RESET
              << "Use W/S to navigate, ENTER to play, Q to end turn\n\n";
    
    for(size_t i = 0; i < player.getHand().size(); ++i) {
        if(static_cast<int>(i) == selectedIndex) 
            std::cout << YELLOW << " > ";
        else 
            std::cout << "   "<<RESET;
            
        const auto& card = player.getHand()[i];
        std::cout << card->getName() << " (Cost: " << card->getEnergyCost() << ")";
        
        if(card->getEnergyCost() > player.getEnergy()) 
            std::cout << RED << " [Not enough energy]" << RESET;
            
        std::cout << "\n";
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
bool CombatSystem::startCombat() {
    InputSystem::enableRawMode();
    while(player.isAlive() && enemy.isAlive()) {
        turnNumber++;
        player.startTurn();
        int selectedIndex = 0;
        bool endTurn = false;

        while(player.getEnergy() > 0 && !player.getHand().empty() && !endTurn) {
            printBattleUI();
            printHand(selectedIndex);
            
            char input = InputSystem::getKey();
            switch(input) {
                case 'w':
                    if(selectedIndex > 0) selectedIndex--;
                    break;
                    
                case 's': 
                    if(selectedIndex < static_cast<int>(player.getHand().size()) - 1)
                        selectedIndex++;
                    break;
                    
                case '\n':
                    if(selectedIndex >= 0 && selectedIndex < static_cast<int>(player.getHand().size())) {
                        auto& card = player.getHand()[selectedIndex];
                        
                        if(card->getEnergyCost() <= player.getEnergy()) {
                            card->play(player, enemy);
                            
                            player.getHand().erase(player.getHand().begin() + selectedIndex);
                            
                            if(selectedIndex >= static_cast<int>(player.getHand().size()) && !player.getHand().empty())
                                selectedIndex = player.getHand().size() - 1;
                                
                            if(!enemy.isAlive()) break;
                        }
                    }
                    break;
                    
                case 'q':
                    endTurn = true;
                    break;
            }
            
            if(!enemy.isAlive()) break;
        }

        if(enemy.isAlive()) {
            printBattleUI();
            std::cout << "\n" << RED << "Enemy's turn!" << RESET << "\n";
            enemy.executeTurn(player);
            
            for(int i = 0; i < 3; i++) {
                std::cout << "." << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        }
    }
        if (!player.isAlive()) {
        playDeathAnimation();
    }

    return player.isAlive();
};

void CombatSystem::playDeathAnimation() {
    // Очищаем экран
    std::cout << "\033c";

    // Кадры анимации смерти
    const std::vector<std::string> deathFrames = {
        R"(
          O 
         /|\
         / \
        )",
        R"(
          O 
         /|\
         / 
        )",
        R"(
          O 
         /|
         / 
        )",
        R"(
          O 
         / 
         / 
        )",
        R"(
          O 
        )",
        R"(
          .
        )",
        R"(
        )"
    };

    for (const auto& frame : deathFrames) {
        std::cout << "\033c";
        std::cout << RED << "=== YOU DIED! ===" << RESET << "\n\n";
        std::cout << frame << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout << "\033c";
    std::cout << RED <<"You lost the battle..."<<RESET<< "\n"<<"But something gives you the strength to wake up by the fire" << "\n";

    std::cout << "Press any key to continue...";
    InputSystem::getKey();
};


/**
 * @brief Renders the battle UI with ASCII art and statuses.
 * @note Uses `system("clear")` for console clearing (platform-dependent).
 */
void CombatSystem::printBattleUI() const {
    std::cout << "\033c";
    std::cout << R"(
  ╔════════════════════════╗
  ║      BATTLE ARENA      ║
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
}