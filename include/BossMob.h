/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef BOSSMOB_H
#define BOSSMOB_H
#include "GameObject.h"
#include <iostream>


class BossMob : public GameObject
{
public:
    char getSymbol() const override;
    bool isPassable() const override;
    void interact(GameState& state) override;
};
#endif