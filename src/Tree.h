/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef TREE_H
#define TREE_H

#include "GameObject.h"

class Tree : public GameObject
{
public:
    char getSymbol() const override;
    bool isPassable() const override;
    void interact(GameState& state) const override;
};


#endif