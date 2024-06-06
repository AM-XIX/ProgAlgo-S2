#include <iostream>
#include <vector>
#include "node.hpp"

// ===== Exercice 1 =====
// ———————— 01-00 - Set up —————————
void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

// ———————— 01-01 —————————
Node* create_node(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// ———————— 01-02 —————————
bool Node::is_leaf() const {
    return this->left == nullptr && this->right == nullptr;
}

// ———————— 01-03 —————————
void Node::insert(int value) {
    if (value < this->value) {
        if (this->left == nullptr) {
            this->left = create_node(value);
        } else {
            this->left->insert(value);
        }
    } else {
        if (this->right == nullptr) {
            this->right = create_node(value);
        } else {
            this->right->insert(value);
        }
    }
}

// ———————— 01-04 —————————
int Node::height() const {
    if (this->is_leaf()) {
        return 0;
    }
    int left_height {0};
    int right_height {0};
    if(this->left) left_height = this->left->height();
    if(this->right) right_height = this->right->height();
    
    return std::max(left_height, right_height) + 1; // j'espère que c'est légal d'ajouter le 1 systématiquement
}

// ———————— 01-05 —————————
void Node::delete_childs() {
    // j'ai tenté de la simplifier mais c'était pas très concluant
    if (this->right) {
        this->right->delete_childs();
        delete this->right;
        this->right = nullptr;
    }
    if (this->left) {
        this->left->delete_childs();
        delete this->left;
        this->left = nullptr;
    }
}

// ———————— 01-06 —————————
void Node::display_infixe() const {
    if (this->left) {
        this->left->display_infixe();
    }
    std::cout << this->value << ", ";
    if (this->right) {
        this->right->display_infixe();
    }
}