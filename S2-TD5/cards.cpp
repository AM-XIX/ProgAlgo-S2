#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <functional>
#include "cards.hpp"

// ===== Exercice 3 =====
// ———————— 03-02/3 —————————
namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

// ———————— 03-04 —————————
// j'ai galéré sur le cout de ça mais au final vous donniez le truc juste en-dessous dans l'énoncé T-T Sorry Steve
std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

// ———————— 03-04 —————————
int main() {
    std::vector<Card> cards = get_cards(100);
    std::unordered_map<Card, int> cardCount;

    for (const auto& card : cards) {
        cardCount[card]++;
    }

    for (const auto& pair : cardCount) {
        std::cout << card_name(pair.first) << " : " << pair.second << std::endl;
    }
    return 0;
}