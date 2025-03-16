/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CARDMANAGER_H
#define CARDMANAGER_H
#include "Card.h"
#include <iostream>

class CardManager
{
public:
    static std::string getColor(const std::string& cardName);
    static std::string getDescription(const std::string& cardName);
};

#endif