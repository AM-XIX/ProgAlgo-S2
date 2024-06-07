#include <vector>
#include <algorithm>
#include <iostream>
#include "main.hpp"
#include "sort.cpp"
#include "ScopedTimer.hpp"


int main(){
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<float> array2 {1.f,9.f,2.f,8.f,3.f,5.f,6.f};
    std::vector<int> array3 {(generate_random_vector(20, 100))};

    // ====== Exercice 1 ======
    // bubble_sort(array);
    
    // ====== Exercice 2 ======
    // merge_sort(array2);

    // ====== Exercice 3 ======
    {
    ScopedTimer timer("Chrono bubble");
        bubble_sort(array3);
    }
    {
    ScopedTimer timer("Chrono merge");
        merge_sort(array2);
    }
    {
    ScopedTimer timer("Chrono standard");
        std::sort(array3.begin(), array3.end());
    }
    // on constate que la fonction sort de la bibliothèque standard est sah plus rapide que tous les autres algo qu'on a codé nous-mêmes.

    // ====== Exercice 4 ======
    // Test 1
    std::vector<int> arrayD1{1, 2, 2, 3, 4, 8, 12};

    int value = 8;
    int index = search(arrayD1, value);
    if (index != -1) {
        std::cout << "Value " << value << " found at index " << index << std::endl;
    } else {
        std::cout << "Value " << value << " not found" << std::endl;
    }

    // Test 2
    // std::vector<int> arrayD2{1, 2, 3, 3, 6, 14, 12, 15};

    // int value = 15;
    // int index = search(arrayD2, value);
    // if (index != -1) {
    //     std::cout << "Value " << value << " found at index " << index << std::endl;
    // } else {
    //     std::cout << "Value " << value << " not found" << std::endl;
    // }

    // Test 3
    // std::vector<int> arrayD3{2, 2, 3, 4, 5, 8, 12, 15, 16};

    // int value = 16;
    // int index = search(arrayD3, value);
    // if (index != -1) {
    //     std::cout << "Value " << value << " found at index " << index << std::endl;
    // } else {
    //     std::cout << "Value " << value << " not found" << std::endl;
    // }

    // Test 4
    // std::vector<int> arrayD4{5, 6, 7, 8, 9, 10, 11, 12, 13};

    // int value = 6;
    // int index = search(arrayD4, value);
    // if (index != -1) {
    //     std::cout << "Value " << value << " found at index " << index << std::endl;
    // } else {
    //     std::cout << "Value " << value << " not found" << std::endl;
    // }

    // Test 5
    // std::vector<int> arrayD5{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // int value = 10;
    // int index = search(arrayD5, value);
    // if (index != -1) {
    //     std::cout << "Value " << value << " found at index " << index << std::endl;
    // } else {
    //     std::cout << "Value " << value << " not found" << std::endl;
    // }

    // ====== Aller + loin ======
    // j'avoue que j'ai pas exactement compris "(c'est à dire en 𝑂(𝑛)" mais je crois que je suis sur la bonne voie ?
    std::vector<int> array4 {5, 1, 6, 1, 4, 3, 6, 5, 2, 4, 2, 3};
    int max_value = 6;
    counting_sort(array4, max_value);
    std::cout << "Counting sort :" << std::endl;
    for (int num : array4) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ====== Vérif ======
    // if (is_sorted(array4)) {
    //     std::cout << "Le tableau est trié" << std::endl;
    // }
    // else {
    //     std::cout << "Le tableau n'est pas trié" << std::endl;
    // }
}