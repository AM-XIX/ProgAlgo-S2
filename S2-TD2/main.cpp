#include <vector>
#include <algorithm>
#include <iostream> 
#include "main.hpp"

// ====== Exercice 1 ======

// -------- 01-00 - Setup
bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end());
}

// -------- 01-01 : tri à bulle
void bubble_sort(std::vector<int> & vec) {
    bool change = true;
    while (change) {
        change = false;
        for (size_t i = 0; i < vec.size() - 1; ++i) {
            if (vec[i] > vec[i + 1]) {
                std::swap(vec[i], vec[i + 1]);
                change = true;
            }
        }
    }
}

int main() {
    // -------- 01-00 - Setup
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bubble_sort(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}