#include <vector>
#include <algorithm>
#include <iostream>
#include "main.hpp"
#include "sort.cpp"

int main(){
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<float> array2 {1.f,9.f,2.f,8.f,3.f,5.f,6.f};
    // ====== Exercice 1 ======
    // bubble_sort(array);
    
    // ====== Exercice 2 ======
    merge_sort(array2);

    if (is_sorted(array2)) {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}