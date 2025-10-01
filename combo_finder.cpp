#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "card.h"

bool is_flush(const std::pmr::vector<Card> &board) {
    int hearts = 0;
    int spades = 0;
    int clubs = 0;
    int diamonds = 0;

    for (auto card: board) {
        switch (card.suit) {
            case Heart:
                ++hearts;
                break;
            case Spade:
                ++spades;
                break;
            case Club:
                ++clubs;
                break;
            case Diamond:
                ++diamonds;
                break;
        }
    }

    if (hearts == 5 || spades == 5 || clubs == 5 || diamonds == 5) {
        return true;
    }

    return false;
}

bool is_straight(const std::pmr::vector<Card> &board) {
    int series = 0;
    for (int i = 0; i < board.size() - 1; ++i) {
        if (board[i + 1].value == board[i].value + 1) {
            ++series;
        } else {
            series = 0;
        }
        if (series == 5) {
            return true;
        }
    }

    return false;
}

std::map<int, int> find_duplicates(const std::pmr::vector<Card> &board) {
    std::map<int, int> duplicates = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0},
        {7, 0},
        {8, 0},
        {9, 0},
        {10, 0},
        {11, 0},
        {12, 0},
        {13, 0}
    };


    for (int i = 0; i < board.size() - 1; ++i) {
        if (board[i].value == board[i + 1].value) {
            duplicates[board[i].value]++;
        }
    }

    return duplicates;
}

int is_royal_flush(const std::pmr::vector<Card> &board) {
    int y = 0;
    for (auto i = board.size() - 1; i >= board.size() - 6; --i, ++y) {
        if (board[i].value != 13 - y) {
            return false;
        }
    }

    return true;
}

void find_combos(std::pmr::vector<Card> &board) {
    //all algorithms assume the board is sorted
    std::ranges::sort(board, [](const Card a, const Card b) {
        return a.value < b.value;
    });

    auto flush = is_flush(board);
    auto straight = is_straight(board);
    bool royal_flush = false;

    if (flush && straight) {
        royal_flush = is_royal_flush(board);
    }

    auto duplicates = find_duplicates(board);

    const auto pairs = std::ranges::count_if(duplicates, [](auto &dup) {
        return dup.second == 1;
    });
    const auto three_of_a_kind = std::ranges::count_if(duplicates, [](auto &dup) {
        return dup.second == 2;
    });
    const auto four_of_a_kind = std::ranges::count_if(duplicates, [](auto &dup) {
        return dup.second == 3;
    });


    if (royal_flush) {
        std::cout << "you have a royal flush !";
    } else if (flush && straight) {
        std::cout << "you have a straight flush !" << std::endl;
    } else if (four_of_a_kind) {
        std::cout << "you have a four of a kind !" << std::endl;
    } else if (three_of_a_kind && pairs) {
        std::cout << "you have a full house !" << std::endl;
    } else if (flush) {
        std::cout << "you have a flush !" << std::endl;
    } else if (straight) {
        std::cout << "you have a straight !" << std::endl;
    } else if (three_of_a_kind) {
        std::cout << "you have a three of a kind !" << std::endl;
    } else if (pairs == 2) {
        std::cout << "you have two pairs !" << std::endl;
    } else if (pairs) {
        std::cout << "you have a pair !" << std::endl;
    } else {
        std::cout << "you don't have any combo" << std::endl;
    }
}
