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
    // std::vector<Node const*> Node::prefixe() const;

    int min() const;
    int max() const;
};

// ———————— 01-01 —————————
Node* create_node(int value);

// ———————— 01-09 —————————
Node*& most_left(Node*& node);

// ———————— 01-10 —————————
bool remove(Node*& node, int value);

// ———————— 01-11 —————————
void delete_tree(Node* node);

