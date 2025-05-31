/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#include "../include/CardPlayer.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>

bool CardPlayer::isAlive() const
{
    return health > 0;
}

std::vector<std::unique_ptr<Card>>& CardPlayer::getHand()
{
    return hand;
}

int CardPlayer::getEnergy() const
{
    return energy;
}

int CardPlayer::getHealth() const
{
    return health;
}

int CardPlayer::getBlock() const
{
    return block;
}

void CardPlayer::setEnergy(int amount)
{
    energy = amount;
}

void CardPlayer::setHealth(int amount)
{
    health = amount;
}

void CardPlayer::loseEnergy(int amount)
{
    energy -= amount;
}

void CardPlayer::addWeak(int turns)
{
    weak += turns;
}

void CardPlayer::drawCards(int count)
{
    for (int i = 0; i < count && !deck.empty(); ++i)
    {
        hand.push_back(std::move(deck.back()));
        deck.pop_back();
    }
}

void CardPlayer::startTurn()
{
    energy = 3; // Reset energy at the start of the turn
    drawCards(5 - static_cast<int>(hand.size())); // Draw up to 5 cards
    weak = std::max(weak - 1, 0); // Decrease "Weak" duration
}

void CardPlayer::addBlock(int amount)
{
    // "Weak" reduces block by 25%
    block += static_cast<int>(amount * (weak > 0 ? 0.75 : 1.0));
}

CardPlayer::CardPlayer() {}

void CardPlayer::heal(int amount)
{
    health = std::min(health + amount, 50); // Max health is 50
}

void CardPlayer::takeDamage(int amount)
{
    int actual = std::max(amount - block, 0); // Block absorbs damage
    health -= actual;
    block = std::max(block - amount, 0); // Reduce block after damage
}

void CardPlayer::printStatus() const
{
    std::cout << "\n[Player]\nHP: " << health
              << "\nBlock: " << block
              << "\nEnergy: " << energy
              << "\nWeak: " << weak << " turns\n";
}