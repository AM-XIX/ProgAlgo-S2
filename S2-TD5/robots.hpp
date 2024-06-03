#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

// ———————— 02-01 —————————
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes);

// ———————— 02-02 —————————
float somme_vector(std::vector<float> const& vec);