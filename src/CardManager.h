#ifndef CARDMANAGER_H
#define CARDMANAGER_H
#include "Card.h"
#include <iostream>

class CardManager {
    public:
        static std::string getColor(const std::string& cardName);
        static std::string getDescription(const std::string& cardName);
    };

#endif