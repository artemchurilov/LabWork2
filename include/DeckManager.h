/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef DECKMANAGER_H
#define DECKMANAGER_H

#include "GameState.h"

/**
 * @class DeckManager
 * @brief Utility class for managing the player's deck and card interactions.
 * @details Provides static methods to display, inspect, and modify the player's deck.
 */
class DeckManager {
public:
    /**
     * @brief Displays the player's current deck with colored card names.
     * @param state Reference to the GameState containing deck data.
     * @note Temporarily disables raw input mode for text interaction.
     */
    static void showDeck(GameState& state);

    /**
     * @brief Shows detailed information about a specific card.
     * @param state Reference to the GameState (unused in this implementation).
     * @param card Name of the card to inspect.
     * @details Uses CardManager to retrieve color and description.
     */
    static void showCardDetails(const std::string& card);

    /**
     * @brief Replaces a card in the player's deck at the specified index.
     * @param state Reference to the GameState to modify.
     * @param index Position of the card to replace (0-based).
     * @warning Does not validate index bounds. Ensure `0 ≤ index < deck_size`.
     */
    static void replaceCard(GameState& state, int index);
};

#endif