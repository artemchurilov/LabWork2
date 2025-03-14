/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef DYNAMICOBJ_H
#define DYNAMICOBJ_H

#include "GameObject.h"

class DynamicObj : public GameObject {
    public:
        explicit DynamicObj(char symbol);
        char getSymbol() const override;
    
    private:
        char symbol;
    };
#endif