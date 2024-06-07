#include <vector>
#include <algorithm>
#include <iostream>
#include "sort.hpp"
#include <cstdlib>


// ====== Exercice 1 ======
// ———————— 01-00 - Set up —————————
bool is_sorted(std::vector<float> const &vec) {
    // changer l'entrée en int ou float en fonction des exe
    return std::is_sorted(vec.begin(), vec.end());
}

// ———————— 01-01 —————————
void bubble_sort(std::vector<int> &vec)
{
    bool change = true;
    while (change)
    {
        change = false;
        for (size_t i = 0; i < vec.size() - 1; ++i)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                change = true;
            }
        }
    }
}

// ====== Exercice 2 ======
void merge_sort_merge(std::vector<float>& vec, size_t left, size_t middle, size_t right) {
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t left_index = 0;
    size_t right_index = 0;
    size_t index = left;

    while (left_index < left_vec.size() && right_index < right_vec.size()) {
        if (left_vec[left_index] < right_vec[right_index]) {
            vec[index++] = left_vec[left_index++];
        } else {
            vec[index++] = right_vec[right_index++];
        }
    }

    while (left_index < left_vec.size()) {
        vec[index++] = left_vec[left_index++];
    }

    while (right_index < right_vec.size()) {
        vec[index++] = right_vec[right_index++];
    }
}

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right) {
    if (left >= right)
    {
        return;
    }
    size_t middle = (right + left) / 2;
    merge_sort(vec, left, middle);
    merge_sort(vec, middle + 1, right);
    merge_sort_merge(vec, left, middle, right);
}

void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

// ====== Exercice 3 ======
std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}