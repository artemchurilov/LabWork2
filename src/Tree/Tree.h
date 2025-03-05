/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef TREE_H
#define TREE_H
#include "../StaticObj/StaticObj.h"

class Tree : public StaticObj {
public:
    Tree(int x, int y);
    
    char getChar() const override;
    bool isPassable() const override;
    void onInteract(Player& player) override;
    int getFruitCount();
    void addFruitCount(int _fruitCount);
    void setFruitCount(int _fruitCount);
private:
    int fruitCount;
};

          
#endif