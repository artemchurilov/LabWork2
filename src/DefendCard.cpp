/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/DefendCard.h"

DefendCard::DefendCard(int cost, std::string cardName, int blockValue) 
    :  Card(cost), name(cardName), block(blockValue){}

void DefendCard::play(CardPlayer& user, Enemy& target) {
    if (target.isAlive()){
        user.addBlock(block);
        user.loseEnergy(energyCost);
    }
}

std::string DefendCard::getName() const {
    return name;
}

