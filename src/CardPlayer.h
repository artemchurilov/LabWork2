/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CARDPLAYER_H
#define CARDPLAYER_H

#include <vector>
#include <memory>
#include "Card.h"
class Card;
class CardPlayer
{
    int health = 50;
    int block = 0;
    int energy = 3;
    int weak = 0;
    std::vector<std::unique_ptr<Card>> deck;
    std::vector<std::unique_ptr<Card>> hand;


public:
    CardPlayer();
    void drawCards(int count);
    void startTurn();
    void loseEnergy(int amount);
    void addBlock(int amount);
    void takeDamage(int amount);
    void addWeak(int turns);
    bool isAlive() const;
    void printStatus() const;
    std::vector<std::unique_ptr<Card>>& getHand();
    int getEnergy() const;
    int getHealth() const;
    int getBlock() const;
};


#endif