/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include "GameObject.h"
class Campfire : public GameObject
{
public:
    char getSymbol() const override;
    void interact(GameState& state) const override;
};
#endif