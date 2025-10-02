#include "deck.h"

#include <algorithm>
#include <random>

Deck::Deck() {
    for (int i = 0; i < 4; ++i) {
        const auto suit = static_cast<Suit>(i);
        for (int y = 1; y < 13; ++y) {
            auto card = Card(suit, y);
            this->cards.push_back(card);
        }
    }
    std::ranges::shuffle(this->cards, std::mt19937(std::random_device()()));
}

Card Deck::Draw() {
    const auto card = this->cards.back();
    this->cards.pop_back();
    return card;
}
