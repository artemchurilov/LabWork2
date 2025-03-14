/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
    public:
        void print() const;
    
        int hp = 100;
        int energy = 50;
        int gold = 0;
        int wood = 0;
        int stone = 0;
    };
#endif