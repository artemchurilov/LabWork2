/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "obj.h"

class Entity: public Obj
{
public:
    Entity(int new_posX, int new_posY,int movespeed, int counterHP);
    ~Entity();

    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();

    void set_movespeed(int new_movespeed);
    int get_movespeed();

    void set_counterHP(int new_counterHP);
    int get_counterHP();
private:
    int movespeed;
    int counterHP;
};


#endif