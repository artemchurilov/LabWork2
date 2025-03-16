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

class Game
{
    GameMap gameMap;
    
    using GameClock = std::chrono::steady_clock;
    GameState state;
    bool running = true;
public:
    Game();
    ~Game();
    void run();
    struct
    {
        bool w = false;
        bool a = false;
        bool s = false;
        bool d = false;
    } keys;
private:
    void processInput();
    void interact();
    void update();
    void handleDeath();
    void respawnPlayer();
    void render();

};

#endif
