/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef DECKMANAGER_H
#define DECKMANAGER_H

#include "GameState.h"

class DeckManager {
    public:
        static void showDeck(const GameState& state);
        static void showCardDetails(const GameState& state, const std::string& card);
        static void replaceCard(GameState& state, int index);
    };

#endif