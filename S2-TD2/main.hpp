# pragma once
#include <iostream>
#include <vector>

// -------- 01-00 - Setup
void bubble_sort(std::vector<int> & vec);

// -------- 02-00 - Setup
// -------- 02-00 - Tri rapide
size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

// -------- 02-00 - Tri fusion
// void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
// void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);
// void merge_sort(std::vector<float> & vec) {
//     merge_sort(vec, 0, vec.size() - 1);
// }
