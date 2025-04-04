/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/Game.h"
#include "../include/const.h"
#include "../include/DeckSelector.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"     
#define YELLOW  "\033[33m"     
#define BLUE    "\033[34m"

Game::Game() : gameMap(MAP_WIDTH, MAP_HEIGHT)
{
    enableRawMode();
}
void Game::selectDeck()
{

    DeckSelector selector;
    auto deckType = selector.show();

    switch(deckType)
    {
    case DeckSelector::RISK_RICK:
        state.current_deck = {"Strike","Strike","Strike","Strike","Strike",
                              "Strike","Strike","Strike","Strike","Strike",
                              "Defend","Defend","Defend","Defend","Defend"
                             };
        break;
    case DeckSelector::RICK_RICK:
        state.current_deck = {"Strike","Strike","Strike","Strike","Strike",
                              "Defend","Defend","Defend","Defend","Defend"
                             };
        break;
    case DeckSelector::SHIELDY_RICK:
        state.current_deck = {"Strike","Strike","Strike","Strike","Strike",
                              "Defend","Defend","Defend","Defend","Defend",
                              "Defend","Defend","Defend","Defend","Defend"
                             };
        break;
    }    
}

Game::~Game()
{
    disableRawMode();
}

void Game::showMainMenu()
{
    MainMenu menu;
    while(true)
    {
        MainMenu::MenuResult result = menu.show();
        switch(result)
        {
        case MainMenu::START:
            selectDeck();
            return;
        case MainMenu::RULES:
            showRulesScreen();
            break;
        case MainMenu::QUIT:
            running = false;
            return;
        }
    }
}

void Game::showRulesScreen()
{
    std::cout << "\033c";
        std::cout << YELLOW << "\n📜 " << RESET << "GAME RULES & CONTROLS" << YELLOW << " 📜\n" << RESET;
        std::cout << "--------------------------------------------------\n";
        
        std::cout << YELLOW << "\n🎮 CONTROLS:\n" << RESET;
        std::cout << "- " << GREEN << "W, A, S, D" << RESET << " - Movement:\n";
        std::cout << "- " << GREEN << "B" << RESET << " - Toggle Map\n";
        std::cout << "- " << GREEN << "C" << RESET << " - View Card Deck\n";
        std::cout << "- " << GREEN << "Q" << RESET << " - Quit Game\n";

        std::cout << YELLOW << "\n🌳 RESOURCES & OBJECTS:\n" << RESET;
        std::cout << "- " << GREEN << "T (Tree)" << RESET << "   - Source of " << GREEN << "Wood\n" << RESET;
        std::cout << "- " << GREEN << "S (Stone)" << RESET << "  - Source of " << GREEN << "Stone\n" << RESET;
        std::cout << "- " << GREEN << "M (Mob)" << RESET << "    - Drops " << GREEN << "Gold\n" << RESET;
        std::cout << "- " << GREEN << "C (Campfire)" << RESET << " - Restores " << GREEN << "HP/Energy\n" << RESET;
        std::cout << "- " << GREEN << "$ (Shop)" << RESET << " - Source of new " << GREEN << "Upgrades\n" << RESET;
        std::cout << "- " << GREEN << "K (CardShop)" << RESET << " - Source of new " << GREEN << "Cards\n" << RESET;
        std::cout << "- " << GREEN << "B (Boss)" << RESET << " - The Final " << GREEN << "Challenge\n" << RESET;
        

        std::cout << "\n" << RED << "TIP: " << RESET << "Type " << GREEN << "Q" << RESET 
                  << " anytime to quit the game!\n\n";
    getKey();
}

void Game::run()
{
    showMainMenu();
    while(running)
    {
        processInput();
        update();
        render();
        usleep(100000);
    }
}



void Game::replaceCard(int index)
{
    std::cout << "\033c";
    std::cout << "Select new card:\n";
    for(size_t i = 0; i < state.deck_cards.size(); ++i)
    {
        std::cout << i+1 << ". " << state.deck_cards[i] << "\n";
    }

    std::cout << "Choice: ";
    int choice;
    std::cin >> choice;
    if(choice > 0 && choice <= int(state.deck_cards.size()))
    {
        state.current_deck[index] = state.deck_cards[choice-1];
    }
}

void Game::showDeck()
{
    disableRawMode();
    std::cout << "\033c";

    std::cout << "=== YOUR DECK ===\n";
    for(size_t i = 0; i < state.current_deck.size(); ++i)
    {
        std::string color = CardManager::getColor(state.current_deck[i]);
        std::cout << color << i+1 << ". " << state.current_deck[i]
                  << "\n";
    }

    std::cout << "\033[0m"<<"\nEnter card number to see details or C to return: ";
    std::string input;
    std::getline(std::cin, input);

    if(input == "c" || input == "C")
    {
        enableRawMode();
        return;
    }

    try
    {
        int index = std::stoi(input) - 1;
        if(index >= 0 && index < int(state.current_deck.size()))
        {
            showCardDetails(state.current_deck[index]);
        }
    }
    catch(...) {}

    enableRawMode();
}

void Game::showCardDetails(const std::string& card)
{
    std::cout << "\033c";
    std::string color = CardManager::getColor(card);
    std::cout << color << "=== " << card << " ===\033[0m\n";
    std::cout << CardManager::getDescription(card) << "\n\n";
    std::cout << "Press any key to continue...";
    std::cout << "\n";
    getKey();
    showDeck();

}

void Game::processInput()
{
    while(keyPressed())
    {
        char c = getKey();
        int dx = 0, dy = 0;

        switch(c)
        {
        case 'w':
        case 'W':
            dy = -1;
            break;

        case 's':
        case 'S':
            dy = 1;
            break;

        case 'a':
        case 'A':
            dx = -1;
            break;

        case 'd':
        case 'D':
            dx = 1;
            break;

        case 'b':
        case 'B':
            gameMap.toggleMap();
            break;

        case 'q':
        case 'Q':
            running = false;
            break;
        case 'c':
        case 'C':
            showDeck();
            break;
        }

        if(dx != 0 || dy != 0)
        {
            gameMap.movePlayer(dx, dy, state);
        }
    }
}

void Game::interact()
{
    int px, py;
    gameMap.getPlayerPos(px, py);
    gameMap.interactAt(px, py, state);
}

void Game::update()
{
    auto now = std::chrono::steady_clock::now();
    lastUpdate = now;

    int dx = 0, dy = 0;
    if(keys.w) dy -= 1;
    if(keys.s) dy += 1;
    if(keys.a) dx -= 1;
    if(keys.d) dx += 1;

    gameMap.movePlayer(dx, dy, state);

    keys = {false, false, false, false};

    if(state.inventory.hp <= 0) handleDeath();
}

void Game::handleDeath()
{
    state.inventory.hp = 100;
    state.inventory.energy = 50;
    state.day++;
    gameMap.setPlayerPos(state.campfire_x, state.campfire_y);
    state.last_message = "Respawned at campfire! Day " + std::to_string(state.day);
}

void Game::render()
{
    gameMap.render(state);
};