#pragma once
#include <iostream>
#include <vector>

// ===== Exercice 1 =====
struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    // ———————— 01-02 —————————
    bool is_leaf() const;
    // ———————— 01-03 —————————
    void insert(int value);
    // ———————— 01-04 —————————
    int height() const;
    // ———————— 01-05 —————————
    void delete_childs();
    // ———————— 01-06 —————————
    void display_infixe() const;
};

// ———————— 01-01 —————————
Node* create_node(int value);


