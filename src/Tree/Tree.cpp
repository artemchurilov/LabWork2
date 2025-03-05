/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "Tree.h"
#include "iostream"
#include "../Player/Player.h"

Tree::Tree(int x, int y) : StaticObj(x, y, true), fruitCount(5)
{

};

void Tree::onInteract(Player& player)
{        
    if (player.getEnergy()>=5)
    {
        player.addEnergy(-5);
        player.addWood(1);
    }
}

bool Tree::isPassable() const
{
    return false;    
};

char Tree::getChar() const 
{ 
    return 'T';
};

int Tree::getFruitCount()
{
    return fruitCount;
};
void Tree::addFruitCount(int _fruitCount)
{
    setFruitCount(getFruitCount()+_fruitCount);
};
void Tree::setFruitCount(int _fruitCount)
{
    fruitCount=_fruitCount;
};
