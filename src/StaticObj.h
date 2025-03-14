/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef STATICOBJ_H
#define STATICOBJ_H

#include "GameObject.h"

class StaticObj : public GameObject {
    public:
        explicit StaticObj(char symbol);
        char getSymbol() const override;
    
    private:
        char symbol;
    };

#endif