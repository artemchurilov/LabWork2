/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "CardPlayer.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Strike.h"
#include "Defend.h"


void CardPlayer::drawCards(int count){
    for(int i = 0; i < count && !deck.empty(); ++i) {
        hand.push_back(move(deck.back()));
        deck.pop_back();
    }
}
void CardPlayer::startTurn() {
    energy = 3;
    drawCards(5 - hand.size());
    weak = std::max(weak - 1, 0);
}
void CardPlayer::addBlock(int amount) {
    block += amount * (weak > 0 ? 0.75 : 1.0);
}

CardPlayer::CardPlayer() {
    for(int i = 0; i < 10; ++i) deck.push_back(std::make_unique<Strike>());
    for(int i = 0; i < 5; ++i) deck.push_back(std::make_unique<Defend>());
    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    
    drawCards(5);
}

void CardPlayer::takeDamage(int amount) {
    int actual = std::max(amount - block, 0);
    health -= actual;
    block = std::max(block - amount, 0);
}

void CardPlayer::printStatus() const {
    std::cout << "\n[Player]\nHP: " << health 
         << "\nBlock: " << block
         << "\nEnergy: " << energy
         << "\nWeak: " << weak << " turns\n";
}