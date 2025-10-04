#ifndef POKER_CARD_H
#define POKER_CARD_H
#pragma once
#include <string>
#include <vector>

enum Suit {
    Heart,
    Spade,
    Diamond,
    Club,
};

class Card {
public:
    Card(Suit suit, int value);
    Suit suit;
    int value;
};

void OutputCard(Card card);

void OutputAsciiCards(std::pmr::vector<Card> cards);

std::pmr::string GetCardAscii(Card card);


#endif //POKER_CARD_H
