#ifndef POKER_DECK_H
#define POKER_DECK_H
#include <vector>

#include "card.h"

class Deck {
public:
    Deck();
    std::pmr::vector<Card> cards;
    Card Draw();
};

#endif //POKER_DECK_H