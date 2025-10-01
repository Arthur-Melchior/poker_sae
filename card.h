#ifndef POKER_CARD_H
#define POKER_CARD_H
#pragma once

enum Suit {
    Heart,
    Spade,
    Diamond,
    Club,
};

struct Card {
    Suit suit;
    int value;
};

Card Draw();

void OutputCard(Card card);

#endif //POKER_CARD_H
