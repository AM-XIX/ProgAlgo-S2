# pragma once
#include <iostream>
#include <vector>

// ====== Exercice 1 ======
// ———————— 01-01 Set up —————————
void bubble_sort(std::vector<int> & vec);

// ====== Exercice 2 ======
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);

// ====== Exercice 3 ======
std::vector<int> generate_random_vector(size_t const size, int const max);

// ====== Exercice 4 ======
int search(std::vector<int> const& vec, int value);

// ====== Aller + loin ======
void counting_sort(std::vector<int> & vec, int const max);

