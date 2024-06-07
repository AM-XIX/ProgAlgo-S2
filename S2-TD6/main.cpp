#include <iostream>
#include <vector>
#include "main.hpp"
#include "node.cpp"

int main() {
    Node* root = create_node(5);

    root->insert(3);
    root->insert(7);
    root->insert(4);
    root->insert(8);
    root->insert(8);
    root->insert(81);

    pretty_print_left_right(*root);
    
    // ———————— 01-06—————————
    root->display_infixe();

    // ———————— 01-04 —————————
    int height = root->height();
    std::cout << "Hauteur : " << height << std::endl;
    
    // ———————— 01-05 —————————
    root->delete_childs();
    pretty_print_left_right(*root);
    return 0;
}