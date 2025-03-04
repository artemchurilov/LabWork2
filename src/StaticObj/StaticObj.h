/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef STATICOBJ_H
#define STATICOBJ_H

#include "../GameObject/GameObject.h"

class StaticObj : public GameObject {
public:
    StaticObj(int x, int y, bool collidable);
    bool isPassable() const override;
};

#endif
