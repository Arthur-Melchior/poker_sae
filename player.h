#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H
#include <vector>

#include "card.h"

class Player {
public:
    std::pmr::vector<Card> cards;
    int score;
};
#endif //POKER_PLAYER_H
