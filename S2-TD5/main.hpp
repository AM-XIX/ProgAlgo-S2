#pragma once
#include <iostream>
#include <vector>

// ===== Exercice 1 =====
// ———————— 01-01 —————————
size_t folding_string_hash(std::string const& s, size_t max);

// ———————— 01-02 —————————
size_t folding_string_ordered_hash(std::string const& s, size_t max);

// ———————— 01-03 —————————
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);



