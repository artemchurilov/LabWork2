/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "iostream"
#include "GameMap.h"

GameMap::GameMap()
{
    grid.resize(height, std::vector<GameObject*>(width, nullptr));
    player = new Player(width/2, height/2);
    grid[player->getY()][player->getX()] = player;
    grid[2][3] = new Tree(2, 3);

};

void GameMap::draw() const
{
    for (int y = 0; y < height; y++) {
        std::cout<<"      ";
        for (int x = 0; x < width; x++) {
            if (grid[y][x]) std::cout << grid[y][x]->getChar() << " ";
            else std::cout << ". ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl << "-------------------------"<<std::endl;
    std::cout << std::endl <<"Your Energy: "<< player->getEnergy()<<". Your Health: "<< player->getHealth()
    <<std:: endl <<"Your Wood: "<<player->getWood()<<". Your Stone: "<<player->getStone()
    <<std:: endl <<"Gold: "<<player->getGold();;
    std::cout << std::endl;
    std::cout << std::endl << "-------------------------"<<std::endl;
};
bool GameMap::movePlayer(int dx, int dy)
{
    int newX = player->getX() + dx;
    int newY = player->getY() + dy;
    
    if (newX < 0 || newX >= width || newY < 0 || newY >= height) 
        return false;
        
    GameObject* target = grid[newY][newX];
    
    if (target && !target->isPassable()) {
        target->onInteract(*player);
        return false;
    }
    
    grid[player->getY()][player->getX()] = nullptr;
    player->setX(newX);
    player->setY(newY);
    grid[newY][newX] = player;
    
    return true;
};
