#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

// ===== Exercice 3 =====
enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    // ———————— 03-02/3 —————————
    std::size_t hash() const {
        // Source :
        // https://en.cppreference.com/w/cpp/utility/hash
        std::size_t kindHash = static_cast<std::size_t>(kind);
        std::size_t valueHash = static_cast<std::size_t>(value);
        return kindHash ^ (valueHash << 1);
    }
};

// ———————— 03-01 —————————
// En partant du principe que "couleur" de l'énoncé est le kind
bool operator==(const Card& card1, const Card& card2) {
    return card1.kind == card2.kind && card1.value == card2.value;
}
