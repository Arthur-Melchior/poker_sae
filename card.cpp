#include "card.h"
#include <iostream>
#include <sstream>

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

/// @details The idea is to split each card into lines, store those lines in a vector,
/// and then loop through every element to print them line by line, so the cards are displayed horizontally in the console.
void OutputAsciiCards(std::pmr::vector<Card> cards) {
    std::pmr::vector<std::pmr::vector<std::pmr::string> > ascii_cards;

    for (const auto card: cards) {
        auto ascii = GetCardAscii(card);
        std::stringstream ss(ascii);

        std::pmr::vector<std::pmr::string> split_asciis;
        std::pmr::string temp;
        while (std::getline(ss, temp, '\n')) {
            split_asciis.emplace_back(temp);
        }
        ascii_cards.emplace_back(split_asciis);
    }

    const auto ascii_card_height = ascii_cards[0].size();
    for (int i = 0; i < ascii_card_height; ++i) {
        for (auto line: ascii_cards) {
            std::cout << line[i];

            //the first line needs a space at the end, or it will be crooked
            //it can't be added to the ascii art because c++ will remove a lonely space at the end of a string
            if (i == 0) {
                std::cout << " ";
            }
        }

        std::cout << "\n";
    }
}


std::pmr::string GetCardAscii(const Card card) {
    switch (card.suit) {
        case Spade:
            switch (card.value) {
                case 1:
                    return R"(     _____
    |A .  |
    | /.\ |
    |(_._)|
    |  |  |
    |____V|)";
                case 2:
                    return R"(     _____
    |2    |
    |  ^  |
    |     |
    |  ^  |
    |____Z|)";
                case 3:
                    return R"(     _____
    |3    |
    | ^ ^ |
    |     |
    |  ^  |
    |____E|)";
                case 4:
                    return R"(     _____
    |4    |
    | ^ ^ |
    |     |
    | ^ ^ |
    |____h|)";
                case 5:
                    return R"(     _____
    |5    |
    | ^ ^ |
    |  ^  |
    | ^ ^ |
    |____S|)";
                case 6:
                    return R"(     _____
    |6    |
    | ^ ^ |
    | ^ ^ |
    | ^ ^ |
    |____9|)";
                case 7:
                    return R"(     _____
    |7    |
    | ^ ^ |
    |^ ^ ^|
    | ^ ^ |
    |____L|)";
                case 8:
                    return R"(     _____
    |8    |
    |^ ^ ^|
    | ^ ^ |
    |^ ^ ^|
    |____8|)";
                case 9:
                    return R"(     _____
    |9    |
    |^ ^ ^|
    |^ ^ ^|
    |^ ^ ^|
    |____6|)";
                case 10:
                    return R"(     _____
    |10 ^ |
    |^ ^ ^|
    |^ ^ ^|
    |^ ^ ^|
    |___0I|)";
                case 11:
                    return R"(     _____
    |J  ww|
    | ^ {)|
    |(.)% |
    | | % |
    |__%%[|)";
                case 12:
                    return R"(     _____
    |Q  ww|
    | ^ {(|
    |(.)%%|
    | |%%%|
    |_%%%O|)";
                case 13:
                    return R"(     _____
    |K  WW|
    | ^ {)|
    |(.)%%|
    | |%%%|
    |_%%%>|)";
                default: return "";
            }
            break;
        case Club:
            switch (card.value) {
                case 1:
                    return R"(     _____
    |A _  |
    | ( ) |
    |(_'_)|
    |  |  |
    |____V|)";
                case 2:
                    return R"(     _____
    |2    |
    |  &  |
    |     |
    |  &  |
    |____Z|)";
                case 3:
                    return R"(     _____
    |3    |
    | & & |
    |     |
    |  &  |
    |____E|)";
                case 4:
                    return R"(     _____
    |4    |
    | & & |
    |     |
    | & & |
    |____h|)";
                case 5:
                    return R"(     _____
    |5    |
    | & & |
    |  &  |
    | & & |
    |____S|)";
                case 6:
                    return R"(     _____
    |6    |
    | & & |
    | & & |
    | & & |
    |____9|)";
                case 7:
                    return R"(     _____
    |7    |
    | & & |
    |& & &|
    | & & |
    |____L|)";
                case 8:
                    return R"(     _____
    |8    |
    |& & &|
    |&  & |
    |& & &|
    |____8|)";
                case 9:
                    return R"(     _____
    |9    |
    |& & &|
    |& & &|
    |& & &|
    |____6|)";
                case 10:
                    return R"(     _____
    |10 & |
    |& & &|
    |& & &|
    |& & &|
    |___0I|)";
                case 11:
                    return R"(     _____
    |J  ww|
    | o {)|
    |o o% |
    | | % |
    |__%%[|)";
                case 12:
                    return R"(     _____
    |Q  ww|
    | o {(|
    |o o%%|
    | |%%%|
    |_%%%O|)";
                case 13:
                    return R"(     _____
    |K  WW|
    | o {)|
    |o o%%|
    | |%%%|
    |_%%%>|)";
                default: return "";
            }
            break;
        case Heart:
            switch (card.value) {
                case 1:
                    return R"(     _____
    |A_ _ |
    |( v )|
    | \ / |
    |  .  |
    |____V|)";
                case 2:
                    return R"(     _____
    |2    |
    |  v  |
    |     |
    |  v  |
    |____Z|)";
                case 3:
                    return R"(     _____
    |3    |
    | v v |
    |     |
    |  v  |
    |____E|)";
                case 4:
                    return R"(     _____
    |4    |
    | v v |
    |     |
    | v v |
    |____h|)";
                case 5:
                    return R"(     _____
    |5    |
    | v v |
    |  v  |
    | v v |
    |____S|)";
                case 6:
                    return R"(     _____
    |6    |
    | v v |
    | v v |
    | v v |
    |____9|)";
                case 7:
                    return R"(     _____
    |7    |
    | v v |
    |v v v|
    | v v |
    |____L|)";
                case 8:
                    return R"(     _____
    |8    |
    |v v v|
    | v v |
    |v v v|
    |____8|)";
                case 9:
                    return R"(     _____
    |9    |
    |v v v|
    |v v v|
    |v v v|
    |____6|)";
                case 10:
                    return R"(     _____
    |10 v |
    |v v v|
    |v v v|
    |v v v|
    |___0I|)";
                case 11:
                    return R"(     _____
    |J  ww|
    |   {)|
    |(v)% |
    | v % |
    |__%%[|)";
                case 12:
                    return R"(     _____
    |Q  ww|
    |   {(|
    |(v)%%|
    | v%%%|
    |_%%%O|)";
                case 13:
                    return R"(     _____
    |K  WW|
    |   {)|
    |(v)%%|
    | v%%%|
    |_%%%>|)";
                default: return "";
            }
            break;
        case Diamond:
            switch (card.value) {
                case 1:
                    return R"(     _____
    |A ^  |
    | / \ |
    | \ / |
    |  .  |
    |____V|)";
                case 2:
                    return R"(     _____
    |2    |
    |  o  |
    |     |
    |  o  |
    |____Z|)";
                case 3:
                    return R"(     _____
    |3    |
    | o o |
    |     |
    |  o  |
    |____E|)";
                case 4:
                    return R"(     _____
    |4    |
    | o o |
    |     |
    | o o |
    |____h|)";
                case 5:
                    return R"(     _____
    |5    |
    | o o |
    |  o  |
    | o o |
    |____S|)";
                case 6:
                    return R"(     _____
    |6    |
    | o o |
    | o o |
    | o o |
    |____9|)";
                case 7:
                    return R"(     _____
    |7    |
    | o o |
    |o o o|
    | o o |
    |____L|)";
                case 8:
                    return R"(     _____
    |8    |
    |o o o|
    | o o |
    |o o o|
    |____8|)";
                case 9:
                    return R"(     _____
    |9    |
    |o o o|
    |o o o|
    |o o o|
    |____6|)";
                case 10:
                    return R"(     _____
    |10 o |
    |o o o|
    |o o o|
    |o o o|
    |___0I|)";
                case 11:
                    return R"(     _____
    |J  ww|
    | /\{)|
    | \/% |
    |   % |
    |__%%[|)";
                case 12:
                    return R"(     _____
    |Q  ww|
    | /\{(|
    | \/%%|
    |  %%%|
    |_%%%O|)";
                case 13:
                    return R"(     _____
    |K  WW|
    | /\{)|
    | \/%%|
    |  %%%|
    |_%%%>|)";
                default: return "";
            }
    }
    return "";
}
