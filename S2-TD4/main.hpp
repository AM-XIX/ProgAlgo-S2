#pragma once
#include <iostream>
#include <vector>

// ———————— 02-01 —————————
auto const is_space = [](char letter){ return letter == ' '; };

// ———————— 02-02 —————————
std::vector<std::string> split_string(std::string const& str);

// ———————— 03 —————————
bool is_palindrome(std::string const& str);

// ———————— Aller + loin -01 —————————
int sommeCarre(std::vector<int> const& numbers);
// ———————— Aller + loin -02 —————————
int evensProduct(const std::vector<int>& vec);
