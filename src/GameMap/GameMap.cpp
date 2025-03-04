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
    grid[3][3] = new Tree(3, 3);

};

void GameMap::draw() const
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x]) std::cout << grid[y][x]->getChar() << " ";
            else std::cout << ". ";
        }
        std::cout << "\n";
    }
};
bool GameMap::movePlayer(int dx, int dy)
{
    int newX = player->getX() + dx;
    int newY = player->getY() + dy;
    
    if (newX < 0 || newX >= width || newY < 0 || newY >= height) 
        return false;
        
        
    if (grid[newY][newX] && !grid[newY][newX]->isPassable())
        return false;
        
    grid[player->getY()][player->getX()] = nullptr;
    player->setX(newX);
    player->setY(newY);
    grid[newY][newX] = player;
    
    return true;
};
