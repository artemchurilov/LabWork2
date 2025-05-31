/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef CARDSHOP_H
#define CARDSHOP_H

#include "GameObject.h"
#include "GameState.h"
#include <iostream>

/**
 * @class CardShop
 * @brief Represents a shop where players can purchase card packs.
 * @details Inherits from GameObject. Allows players to spend resources to acquire new cards.
 */
class CardShop : public GameObject
{
private:
    int selectedItem = 0;
    std::string message;
    bool inReplaceMode = false;
    int replaceIndex = 0;
    std::string newCard;
public:
    /**
     * @struct CardPack
     * @brief Defines a purchasable card pack with costs and contents.
     */
    struct CardPack
    {
        std::string name;            ///< Name of the pack (e.g., "Arms Action").
        int gold_cost;               ///< Gold cost to purchase the pack.
        int wood_cost;               ///< Wood cost to purchase the pack.
        int stone_cost;              ///< Stone cost to purchase the pack.
        std::vector<std::pair<std::string, int>> cards; ///< Cards in the pack (name + weight for probability).
    };

    /**
     * @override
     * @brief Returns the shop's symbol.
     * @return 'K' (ASCII character).
     */
    char getSymbol() const override;

    /**
     * @override
     * @brief Checks if the shop can be traversed.
     * @return Always false (blocks movement).
     */
    bool isPassable() const override;

    /**
     * @override
     * @brief Enters the card shop interaction loop.
     * @param state GameState to modify (resources, deck).
     */
    void interact(GameState& state) override;

    bool inCardShop = false;

    void renderShopInterface(const GameState& state) const;
    void renderReplaceInterface(const GameState& state) const;
    void handleInput(GameState& state);
    std::string getRandomCard(const CardPack& pack) const;

    /**
     * @brief Available card packs in the shop.
     * @details
     * - "Arms Action": Costs 100G + 10W. Contains attack/block cards.
     * - "Legs Action": Costs 100G + 10S. Contains kick/heal cards.
     * - "Spells": Costs 100G + 5W + 5S. Contains special ability cards.
     */
    const std::vector<CardPack> packs =
    {
        {"Arms Action", 100, 10, 0, {{"Fist Punch", 24}, {"Fist Block", 24}, {"Arm Heal", 24}, {"Arm Combo", 24}, {"Ultra Duper Punch", 4}}},
        {"Legs Action", 100, 0, 10, {{"Foot Kick", 24}, {"Leg Block", 24}, {"Leg Heal", 24}, {"Leg Combo", 24}, {"Ultra Duper Kick", 4}}},
        {"Spells", 100, 5, 5, {{"AutoRepair", 20}, {"Strongest Spell", 40}, {"Clink-clock", 40}}}
    };
};

#endif