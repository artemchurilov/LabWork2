/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef DECKSELECTOR_H
#define DECKSELECTOR_H
#include "../include/GameState.h"
/**
 * @class DeckSelector
 * @brief Handles deck selection UI for the player.
 * @details Uses terminal-based navigation with WASD/arrow key support.
 */
class DeckSelector
{
public:
    /**
    * @enum DeckType
    * @brief Types of preconfigured decks available for selection.
    */
    enum DeckType
    {
        RICK,        ///< Balanced deck: 5 Strike, 5 Defend.
        RISK_RICK,   ///< Aggressive deck: 10 Strike, 5 Defend.
        SHIELDY_RICK ///< Defensive deck: 5 Strike, 10 Defend.
    };
    /**
     * @brief Displays the deck selection menu and returns the chosen deck.
     * @return Selected DeckType.
     */
    DeckType show();

    /**
     * @brief Handles deck selection at the start of the game.
     */
    void selectDeck(GameState& state);
private:

    /**
     * @brief Prints the menu title ("ToyRick").
     */
    void printTitle();

    /**
     * @brief Prints deck options with highlighting for the selected item.
     * @param selected Index of the currently selected option (0-2).
     */
    void printOptions(int selected);
};

#endif