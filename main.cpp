#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>

#include "card.h"
#include "combo_finder.h"
#include "deck.h"

void show_table_cards(const std::pmr::vector<Card> &cards_on_table, const bool show_ascii) {
    std::cout << "Cards on the table" << std::endl;
    for (const auto card: cards_on_table) {
        OutputCard(card);
        if (show_ascii) {
            OutputCardAscii(card);
        }
    }
}

bool player_folds() {
    int player_choice = 0;
    std::cout << "Do you fold or follow ? \n [1] fold  [2] follow" << std::endl;
    std::cin >> player_choice;
    return player_choice == 1;
}

void show_player_cards(const std::pmr::vector<Card> &player_cards, const bool show_ascii) {
    std::cout << "Your cards are : " << std::endl;
    OutputCard(player_cards[0]);
    if (show_ascii) {
        OutputCardAscii(player_cards[0]);
    }
    OutputCard(player_cards[1]);
    if (show_ascii) {
        OutputCardAscii(player_cards[1]);
    }
}

int main() {
    srand(time(nullptr));
    auto deck = Deck();

    std::pmr::vector<Card> player_cards = {deck.Draw(), deck.Draw()};
    std::pmr::vector<Card> table_cards = {deck.Draw(), deck.Draw(), deck.Draw()};

    show_player_cards(player_cards, true);
    show_table_cards(table_cards, true);

    find_combos(player_cards, table_cards);

    if (player_folds()) {
        return 0;
    }

    table_cards.push_back(deck.Draw());
    show_player_cards(player_cards, false);
    show_table_cards(table_cards, false);

    find_combos(player_cards, table_cards);

    if (player_folds()) {
        return 0;
    }

    table_cards.push_back(deck.Draw());
    show_player_cards(player_cards, false);
    show_table_cards(table_cards, false);

    std::pmr::vector<Card> enemy_cards = {deck.Draw(), deck.Draw()};
    const int player_score = find_combos(player_cards, table_cards);
    const int enemy_score = find_combos(enemy_cards, table_cards, false);

    std::cout << "enemy hand : " << std::endl;
    OutputCard(enemy_cards[0]);
    OutputCard(enemy_cards[1]);

    if (player_score < enemy_score) {
        std::cout << "the enemy has a better hand ! you loose !" << std::endl;
    } else {
        std::cout << "you have a better hand ! you win !";
    }

    return 0;
}
