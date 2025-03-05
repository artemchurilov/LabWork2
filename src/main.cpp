#include <iostream>
#include "Player/Player.h"
#include "Tree/Tree.h"
#include "Menu/Menu.h"
#include "GameMap/GameMap.h"

int main() {
    startMenu();
    GameMap gameMap;
    char input;
    while(true) 
    {
        std::cout <<"\033c";
        std:: cout <<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<< "     Forest Friends" <<std::endl<<"~+~-~+~-~+~-~+~-~+~-~+~-~"<<std::endl<<std::endl;
        gameMap.draw();

        std::cout <<std::endl<< "Input direction (w/a/s/d) or q for exit: ";
        std::cin >> input;   
        if(input == 'q') break;
        switch(input) 
        {
            case 'w': gameMap.movePlayer(0, -1); break;
            case 's': gameMap.movePlayer(0, 1); break;
            case 'a': gameMap.movePlayer(-1, 0); break;
            case 'd': gameMap.movePlayer(1, 0); break;
        }
    }        
    return 0;
}
