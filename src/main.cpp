/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <iostream>
#include <memory>
#include <vector>
#include "GameMap.h"
#include "Cell.h"
#include "../include/const.h"
#include "Inventory.h"

#include <cstdlib>
#include "Player.h"

char getInput()
{
    char input;
    std::cin >> input;
    return input;
}

int main()
{
    GameMap gameMap(MAP_WIDTH, MAP_HEIGHT);
    Player player;

    while (true)
    {
        gameMap.render(player.inventory);

        char input = getInput();
        switch (input)
        {
        case 'w':
            gameMap.movePlayer(0, -1);
            break;
        case 's':
            gameMap.movePlayer(0, 1);
            break;
        case 'a':
            gameMap.movePlayer(-1, 0);
            break;
        case 'd':
            gameMap.movePlayer(1, 0);
            break;
        case 'q':
            return 0;
        default:
            break;
        }
    }
}