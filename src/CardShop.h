#ifndef CARDSHOP_H
#define CARDSHOP_H


#include "GameObject.h"
#include "GameState.h"
#include <iostream>

class CardShop : public GameObject
{
public:
    char getSymbol() const override;
    bool isPassable() const override;
    void interact(GameState& state) override;

private:
    struct CardPack
    {
        std::string name;
        std::string card_name;
        int gold_cost;
        int wood_cost;
        int stone_cost;
        int damage;
        int block;
    };

    const std::vector<CardPack> packs =
    {
        {"Arms Action", "Toy Hammer", 100, 10, 0, 10, 0},
        {"Legs Action", "Kicking Boots", 100, 0, 10, 0, 15},
        {"Spells", "Magic Plushie", 100, 5, 5, 8, 8}
    };

    void printShopArt(const GameState& state) const;
    int getShopChoice() const;
    void handleChoice(int choice, GameState& state, bool& inShop);
};

#endif