/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Game.h"
#include "../include/const.h"
#include "DeckSelector.h"

Game::Game() : gameMap(MAP_WIDTH, MAP_HEIGHT)
{
    enableRawMode();

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
    system("clear");
    std::cout << "=== GAME RULES ===\n";
    std::cout << "1. Collect resources to buy cards\n";
    std::cout << "2. Fight enemies to gain gold\n";
    std::cout << "3. Defeat the final boss to win\n";
    std::cout << "\n Press any key to return...";
    std::cout << "\n";
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
    system("clear");
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
    system("clear");

    std::cout << "=== YOUR DECK ===\n";
    for(size_t i = 0; i < state.current_deck.size(); ++i)
    {
        std::string color = CardManager::getColor(state.current_deck[i]);
        std::cout << color << i+1 << ". " << state.current_deck[i]
                  << "\n";
    }

    std::cout << "\nEnter card number to see details or C to return: ";
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
    system("clear");
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
            dy = -1;
            break;
        case 's':
            dy = 1;
            break;
        case 'a':
            dx = -1;
            break;
        case 'd':
            dx = 1;
            break;
        case ' ':
            interact();
            break;
        case 'b':
            gameMap.toggleMap();
            break;
        case 'q':
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