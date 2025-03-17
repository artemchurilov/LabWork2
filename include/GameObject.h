/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "GameState.h"

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual char getSymbol() const = 0;
    virtual bool isPassable() const;
    virtual void interact(GameState&) {};
};

#endif