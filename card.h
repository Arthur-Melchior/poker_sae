#ifndef POKER_CARD_H
#define POKER_CARD_H
#pragma once

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

void OutputCardAscii(Card card);


#endif //POKER_CARD_H
