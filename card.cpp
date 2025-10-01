#include "card.h"
#include <cstdlib>
#include <iostream>

Card Draw() {
    int suit_id = rand() % 4;
    const int card_value = rand() % 13 + 1;
    const Card card = {static_cast<Suit>(suit_id), card_value};
    return card;
}

void OutputCard(const Card card) {
    switch (card.value) {
        case 1:
            std::cout << "Ace";
            break;
        case 11:
            std::cout << "Jack";
            break;
        case 12:
            std::cout << "Queen";
            break;
        case 13:
            std::cout << "King";
            break;
        default:
            std::cout << card.value;
            break;
    }

    std::cout << " of ";

    switch (card.suit) {
        case 0:
            std::cout << "Heart" << std::endl;
            break;
        case 1:
            std::cout << "Spade" << std::endl;
            break;
        case 2:
            std::cout << "Diamond" << std::endl;
            break;
        case 3:
            std::cout << "Club" << std::endl;
            break;
    }
}
