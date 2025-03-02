/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "../obj/obj.h"

class Entity: public Obj
{
public:
    Entity(int new_posX, int new_posY,float new_movespeed, int new_counterHP);
    ~Entity();
    
    void set_movespeed(float new_movespeed);
    float get_movespeed();

    void set_counterHP(int new_counterHP);
    int get_counterHP();
private:
    float movespeed;
    int counterHP;
};


#endif