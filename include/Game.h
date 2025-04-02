/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/


#ifndef GAME_H
#define GAME_H


#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <cstdlib>
#include <string>
#include <chrono>
#include "GameMap.h"
#include "InputSystem.h"
#include "MainMenu.h"
#include "CardManager.h"
#include "GameState.h"
class Game
{
    GameMap gameMap;
    GameState state;
    bool running = true;


    std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();
    bool showRules = false;
public:
    Game();
    ~Game();
    void showMainMenu();
    void showRulesScreen();
    void replaceCard(int index);
    void run();
    void showDeck();
    void showCardDetails(const std::string& card);
    void selectDeck();
private:
    struct
    {
        bool w = false;
        bool a = false;
        bool s = false;
        bool d = false;
    } keys;

    void processInput();

    void interact();

    void update();

    void handleDeath();

    void render();


};

#endif
