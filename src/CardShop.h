#ifndef CARDSHOP_H
#define CARDSHOP_H


#include "GameObject.h"
#include "GameState.h"
#include <iostream>

class CardShop : public GameObject
{
public:
struct CardPack
{
    std::string name;
    int gold_cost;
    int wood_cost;
    int stone_cost;
    std::vector<std::pair<std::string, int>> cards;
};
char getSymbol() const;
bool isPassable() const;

void interact(GameState& state);

void printShopArt(const GameState& state) const;

    int getShopChoice() const;
    void handleChoice(int choice, GameState& state, bool& inShop);
    int getShopChoice(int min, int max) const;
    std::string getRandomCard(const CardPack& pack) const;
    void printCardDescription(const std::string& card) const;

    const std::vector<CardPack> packs = {
        {"Arms Action", 100, 10, 0, {
            {"Fist Punch", 24}, {"Fist Block", 24}, 
            {"Arm Heal", 24}, {"Arm Combo", 24}, {"Ultra Duper Punch", 4}
        }},
        {"Legs Action", 100, 0, 10, {
            {"Foot Kick", 24}, {"Leg Block", 24},
            {"Leg Heal", 24}, {"Leg Combo", 24}, {"Ultra Duper Kick", 4}
        }},
        {"Spells", 100, 5, 5, {
            {"ArmDiscard", 25}, {"AutoRepair", 25},
            {"Unluck", 25}, {"Clink-clock", 25}
        }}
    };
    
private:


};
#endif