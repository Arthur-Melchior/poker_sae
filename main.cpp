#include <algorithm>
#include <iostream>
#include <vector>

#include "card.h"
#include "combo_finder.h"

void Show_table_cards(const std::pmr::vector<Card> &cards_on_table) {
    std::cout << "Cards on the table" << std::endl;
    for (auto card: cards_on_table) {
        OutputCard(card);
    }
}

bool player_folds() {
    int player_choice = 0;
    std::cout << "Do you fold or follow ? \n [1] fold  [2] follow" << std::endl;
    std::cin >> player_choice;
    return player_choice == 1;
}

int main() {
    srand(time(nullptr));

    const Card player_cards[2] = {Draw(), Draw()};
    Card enemy_cards[2] = {Draw(), Draw()};
    std::pmr::vector<Card> cards_on_table = {Draw(), Draw(), Draw()};

    std::cout << "You have drawn : " << std::endl;
    OutputCard(player_cards[0]);
    OutputCard(player_cards[1]);

    Show_table_cards(cards_on_table);

    std::pmr::vector<Card> board = {
        player_cards[0], player_cards[1], cards_on_table[0], cards_on_table[1], cards_on_table[2]
    };

    find_combos(board);

    if (player_folds()) {
        return 0;
    }

    cards_on_table.push_back(Draw());
    Show_table_cards(cards_on_table);

    find_combos(board);

    if (player_folds()) {
        return 0;
    }

    cards_on_table.push_back(Draw());
    Show_table_cards(cards_on_table);

    find_combos(board);

    return 0;
}
