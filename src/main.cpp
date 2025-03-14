/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include <iostream>
#include <memory>
#include <vector>
#include "GameMap.h"
#include "Cell.h"
#include "../include/const.h"

#include <cstdlib>


int main()
{
    GameMap gameMap(MAP_WIDTH, MAP_HEIGHT);
    GameState state;
    char input;

    while (true)
    {
        gameMap.render(state);
        std::cin >> input;

        switch(input)
        {
        case 'w':
            gameMap.movePlayer(0, -1, state);
            break;
        case 's':
            gameMap.movePlayer(0, 1, state);
            break;
        case 'a':
            gameMap.movePlayer(-1, 0, state);
            break;
        case 'd':
            gameMap.movePlayer(1, 0, state);
            break;
        case 'q':
            return 0;
        }
    }
}