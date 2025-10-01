#ifndef POKER_COMBO_FINDER_H
#define POKER_COMBO_FINDER_H
#include <map>

#include "card.h"

bool is_flush(const std::pmr::vector<Card> &board);

bool is_straight(const std::pmr::vector<Card> &board);

std::map<int, int> find_duplicates(const std::pmr::vector<Card> &board);

bool is_royal_flush(const std::pmr::vector<Card> &board);

void find_combos(std::pmr::vector<Card> &board);

#endif //POKER_COMBO_FINDER_H
