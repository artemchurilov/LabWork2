/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "Tree.h"
#include "iostream"

Tree::Tree(int x, int y) : StaticObj(x, y, true), fruitCount(5) 
{

};

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


/*void Tree::onPlayerEnter(Player& player)
{
    if (fruitCount > 0) {
        player.addWood(1);
        fruitCount--;
        std::cout << "Собрано 1 дерево! Осталось: " << fruitCount << std::endl;
    }
};*/