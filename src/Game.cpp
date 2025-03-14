/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "Game.h"
#include "../include/const.h"

Game::Game():gameMap(MAP_WIDTH, MAP_HEIGHT)
{
    enableRawMode();
}

Game::~Game()
{
    disableRawMode();
}

void Game::run()
{
    while(running)
    {
        processInput();
        update();
        render();
        usleep(100000); // 100ms
    }
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
};

void Game::update()
{
    if(state.inventory.hp <= 0) handleDeath();
}

void Game::handleDeath()
{
    state.last_message = "Press R to respawn at campfire";
    render();
    while(true)
    {
        if(keyPressed())
        {
            char c = getKey();
            if(c == 'r' || c == 'R')
            {
                respawnPlayer();
                return;
            }
        }
        usleep(100000);
    }
}

void Game::respawnPlayer()
{
    state.inventory = {100, 50, 0, 0, 0,
                       state.inventory.sword_level,
                       state.inventory.shield_level
                      };
    gameMap.setPlayerPos(state.campfire_x, state.campfire_y);
}

void Game::render()
{
    gameMap.render(state);
}