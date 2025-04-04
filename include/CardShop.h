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

    /**
     * @brief Renders the shop UI with available packs and player resources.
     * @param state GameState for current player stats.
     */
    void printShopArt(const GameState& state) const;

    /**
     * @brief Validates and returns the player's menu choice (1-4).
     * @return Validated integer input.
     */
    int getShopChoice() const;

    /**
     * @brief Processes the player's choice (buying a pack or exiting).
     * @param choice Selected menu option (1-4).
     * @param state GameState to modify.
     * @param inShop Reference flag to control the shop loop.
     */
    void handleChoice(int choice, GameState& state, bool& inShop);

    /**
     * @brief Validates and returns a choice within a specified range.
     * @param min Minimum allowed value.
     * @param max Maximum allowed value.
     * @return Validated integer input.
     */
    int getShopChoice(int min, int max) const;

    /**
     * @brief Randomly selects a card from a pack based on weighted probabilities.
     * @param pack Reference to the CardPack to draw from.
     * @return Name of the selected card.
     */
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