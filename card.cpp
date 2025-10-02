#include "card.h"
#include <cstdlib>
#include <iostream>

Card::Card(Suit suit, int value) {
    this->suit = suit;
    this->value = value;
}

void OutputCard(const Card card) {
    switch (card.value) {
        case 1:
            std::cout << "  Ace";
            break;
        case 11:
            std::cout << "  Jack";
            break;
        case 12:
            std::cout << "  Queen";
            break;
        case 13:
            std::cout << "  King";
            break;
        default:
            std::cout << "   " << card.value;
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

void OutputCardAscii(const Card card) {
    switch (card.suit) {
        case Spade:
            switch (card.value) {
                case 1:
                    std::cout << R"(     _____
    |A .  |
    | /.\ |
    |(_._)|
    |  |  |
    |____V|)" << std::endl << std::endl;
                    break;
                case 2:
                    std::cout << R"(     _____
    |2    |
    |  ^  |
    |     |
    |  ^  |
    |____Z|)" << std::endl << std::endl;
                    break;
                case 3:
                    std::cout << R"(     _____
    |3    |
    | ^ ^ |
    |     |
    |  ^  |
    |____E|)" << std::endl << std::endl;
                    break;
                case 4:
                    std::cout << R"(     _____
    |4    |
    | ^ ^ |
    |     |
    | ^ ^ |
    |____h|)" << std::endl << std::endl;
                    break;
                case 5:
                    std::cout << R"(     _____
    |5    |
    | ^ ^ |
    |  ^  |
    | ^ ^ |
    |____S|)" << std::endl << std::endl;
                    break;
                case 6:
                    std::cout << R"(     _____
    |6    |
    | ^ ^ |
    | ^ ^ |
    | ^ ^ |
    |____9|)" << std::endl << std::endl;
                    break;
                case 7:
                    std::cout << R"(     _____
    |7    |
    | ^ ^ |
    |^ ^ ^|
    | ^ ^ |
    |____L|)" << std::endl << std::endl;
                    break;
                case 8:
                    std::cout << R"(     _____
    |8    |
    |^ ^ ^|
    | ^ ^ |
    |^ ^ ^|
    |____8|)" << std::endl << std::endl;
                    break;
                case 9:
                    std::cout << R"(     _____
    |9    |
    |^ ^ ^|
    |^ ^ ^|
    |^ ^ ^|
    |____6|)" << std::endl << std::endl;
                    break;
                case 10:
                    std::cout << R"(     _____
    |10 ^ |
    |^ ^ ^|
    |^ ^ ^|
    |^ ^ ^|
    |___0I|)" << std::endl << std::endl;
                    break;
                case 11:
                    std::cout << R"(     _____
    |J  ww|
    | ^ {)|
    |(.)% |
    | | % |
    |__%%[|)" << std::endl << std::endl;
                    break;
                case 12:
                    std::cout << R"(     _____
    |Q  ww|
    | ^ {(|
    |(.)%%|
    | |%%%|
    |_%%%O|)" << std::endl << std::endl;
                    break;
                case 13:
                    std::cout << R"(     _____
    |K  WW|
    | ^ {)|
    |(.)%%|
    | |%%%|
    |_%%%>|)" << std::endl << std::endl;
                    break;
                default: ;
            }
            break;
        case Club:
            switch (card.value) {
                case 1:
                    std::cout << R"(     _____
    |A _  |
    | ( ) |
    |(_'_)|
    |  |  |
    |____V|)" << std::endl << std::endl;
                    break;
                case 2:
                    std::cout << R"(     _____
    |2    |
    |  &  |
    |     |
    |  &  |
    |____Z|)" << std::endl << std::endl;
                    break;
                case 3:
                    std::cout << R"(     _____
    |3    |
    | & & |
    |     |
    |  &  |
    |____E|)" << std::endl << std::endl;
                    break;
                case 4:
                    std::cout << R"(     _____
    |4    |
    | & & |
    |     |
    | & & |
    |____h|)" << std::endl << std::endl;
                    break;
                case 5:
                    std::cout << R"(     _____
    |5    |
    | & & |
    |  &  |
    | & & |
    |____S|)" << std::endl << std::endl;
                    break;
                case 6:
                    std::cout << R"(     _____
    |6    |
    | & & |
    | & & |
    | & & |
    |____9|)" << std::endl << std::endl;
                    break;
                case 7:
                    std::cout << R"(     _____
    |7    |
    | & & |
    |& & &|
    | & & |
    |____L|)" << std::endl << std::endl;
                    break;
                case 8:
                    std::cout << R"(     _____
    |8    |
    |& & &|
    |&  & |
    |& & &|
    |____8|)" << std::endl << std::endl;
                    break;
                case 9:
                    std::cout << R"(     _____
    |9    |
    |& & &|
    |& & &|
    |& & &|
    |____6|)" << std::endl << std::endl;
                    break;
                case 10:
                    std::cout << R"(     _____
    |10 & |
    |& & &|
    |& & &|
    |& & &|
    |___0I|)" << std::endl << std::endl;
                    break;
                case 11:
                    std::cout << R"(     _____
    |J  ww|
    | o {)|
    |o o% |
    | | % |
    |__%%[|)" << std::endl << std::endl;
                    break;
                case 12:
                    std::cout << R"(     _____
    |Q  ww|
    | o {(|
    |o o%%|
    | |%%%|
    |_%%%O|)" << std::endl << std::endl;
                    break;
                case 13:
                    std::cout << R"(     _____
    |K  WW|
    | o {)|
    |o o%%|
    | |%%%|
    |_%%%>|)" << std::endl << std::endl;
                    break;
                default: ;
            }
            break;
        case Heart:
            switch (card.value) {
                case 1:
                    std::cout << R"(     _____
    |A_ _ |
    |( v )|
    | \ / |
    |  .  |
    |____V|)" << std::endl << std::endl;
                    break;
                case 2:
                    std::cout << R"(     _____
    |2    |
    |  v  |
    |     |
    |  v  |
    |____Z|)" << std::endl << std::endl;
                    break;
                case 3:
                    std::cout << R"(     _____
    |3    |
    | v v |
    |     |
    |  v  |
    |____E|)" << std::endl << std::endl;
                    break;
                case 4:
                    std::cout << R"(     _____
    |4    |
    | v v |
    |     |
    | v v |
    |____h|)" << std::endl << std::endl;
                    break;
                case 5:
                    std::cout << R"(     _____
    |5    |
    | v v |
    |  v  |
    | v v |
    |____S|)" << std::endl << std::endl;
                    break;
                case 6:
                    std::cout << R"(     _____
    |6    |
    | v v |
    | v v |
    | v v |
    |____9|)" << std::endl << std::endl;
                    break;
                case 7:
                    std::cout << R"(     _____
    |7    |
    | v v |
    |v v v|
    | v v |
    |____L|)" << std::endl << std::endl;
                    break;
                case 8:
                    std::cout << R"(     _____
    |8    |
    |v v v|
    | v v |
    |v v v|
    |____8|)" << std::endl << std::endl;
                    break;
                case 9:
                    std::cout << R"(     _____
    |9    |
    |v v v|
    |v v v|
    |v v v|
    |____6|)" << std::endl << std::endl;
                    break;
                case 10:
                    std::cout << R"(     _____
    |10 v |
    |v v v|
    |v v v|
    |v v v|
    |___0I|)" << std::endl << std::endl;
                    break;
                case 11:
                    std::cout << R"(     _____
    |J  ww|
    |   {)|
    |(v)% |
    | v % |
    |__%%[|)" << std::endl << std::endl;
                    break;
                case 12:
                    std::cout << R"(     _____
    |Q  ww|
    |   {(|
    |(v)%%|
    | v%%%|
    |_%%%O|)" << std::endl << std::endl;
                    break;
                case 13:
                    std::cout << R"(     _____
    |K  WW|
    |   {)|
    |(v)%%|
    | v%%%|
    |_%%%>|)" << std::endl << std::endl;
                    break;
                default: ;
            }
            break;
        case Diamond:
            switch (card.value) {
                case 1:
                    std::cout << R"(     _____
    |A ^  |
    | / \ |
    | \ / |
    |  .  |
    |____V|)" << std::endl << std::endl;
                    break;
                case 2:
                    std::cout << R"(     _____
    |2    |
    |  o  |
    |     |
    |  o  |
    |____Z|)" << std::endl << std::endl;
                    break;
                case 3:
                    std::cout << R"(     _____
    |3    |
    | o o |
    |     |
    |  o  |
    |____E|)" << std::endl << std::endl;
                    break;
                case 4:
                    std::cout << R"(     _____
    |4    |
    | o o |
    |     |
    | o o |
    |____h|)" << std::endl << std::endl;
                    break;
                case 5:
                    std::cout << R"(     _____
    |5    |
    | o o |
    |  o  |
    | o o |
    |____S|)" << std::endl << std::endl;
                    break;
                case 6:
                    std::cout << R"(     _____
    |6    |
    | o o |
    | o o |
    | o o |
    |____9|)" << std::endl << std::endl;
                    break;
                case 7:
                    std::cout << R"(     _____
    |7    |
    | o o |
    |o o o|
    | o o |
    |____L|)" << std::endl << std::endl;
                    break;
                case 8:
                    std::cout << R"(     _____
    |8    |
    |o o o|
    | o o |
    |o o o|
    |____8|)" << std::endl << std::endl;
                    break;
                case 9:
                    std::cout << R"(     _____
    |9    |
    |o o o|
    |o o o|
    |o o o|
    |____6|)" << std::endl << std::endl;
                    break;
                case 10:
                    std::cout << R"(     _____
    |10 o |
    |o o o|
    |o o o|
    |o o o|
    |___0I|)" << std::endl << std::endl;
                    break;
                case 11:
                    std::cout << R"(     _____
    |J  ww|
    | /\{)|
    | \/% |
    |   % |
    |__%%[|)" << std::endl << std::endl;
                    break;
                case 12:
                    std::cout << R"(     _____
    |Q  ww|
    | /\{(|
    | \/%%|
    |  %%%|
    |_%%%O|)" << std::endl << std::endl;
                    break;
                case 13:
                    std::cout << R"(     _____
    |K  WW|
    | /\{)|
    | \/%%|
    |  %%%|
    |_%%%>|)" << std::endl << std::endl;
                    break;
                default: ;
            }
    }
}
