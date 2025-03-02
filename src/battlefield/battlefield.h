/* Artem Churilov st130184@student.spbu.ru
   LabWork 2 task "Making Game" step 1 "Creating Repository"
*/

#ifndef BATTLEFIELD_H    
#define BATTLEFIELD_H

#include "../obj/obj.h"
class Battlefield
{
private:
    int width;
    int height;
    Obj*** grid;

public:
    Battlefield(int w, int h);
    ~Battlefield();

    bool addObject(int x, int y, Obj* obj);
    void removeObject(int x, int y);
    Obj* getObject(int x, int y) const;
    void printBattlefield() const;
};

#endif