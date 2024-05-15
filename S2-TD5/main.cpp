#include <iostream>
#include <vector>
#include "robots.cpp"
#include "main.hpp"

// ===== Exercice 1 =====
// ———————— 01-01 —————————
size_t folding_string_hash(const std::string& s, size_t max) {
    size_t sum = 0;
    for (char c : s) {
        sum += static_cast<size_t>(c);
    }
    return sum % max;
}

// ———————— 01-02 —————————
size_t folding_string_ordered_hash(const std::string& s, size_t max) {
    size_t sum = 0;
    for (size_t i = 0; i < s.length(); i++) {
        sum += static_cast<size_t>(s[i]) * (i + 1);
    }
    return sum % max;
}

// ———————— 01-03 —————————
size_t polynomial_rolling_hash(const std::string& s, size_t m) {
    size_t sum = 0;
    size_t p = 31;
    size_t power = 1;
    for (char c : s) {
        sum = (sum + c * power) % m;
        power = (power * p) % m;
    }
    return sum;
}

int main() {
    // ———————— 01-01 —————————
    std::string str = "Hello, world!";
    size_t max = 1024;
    size_t hash = folding_string_hash(str, max);
    std::cout << "Hash value: " << hash << std::endl;

    // ———————— 01-02 —————————
    std::string str2 = "cba";
    size_t hash2 = folding_string_ordered_hash(str2, max);
    std::cout << "Ordered hash value: " << hash2 << std::endl;
    
    // ———————— 01-03 —————————
    std::string str3 = "HI WORLD";
    size_t m = 1000000009;
    size_t hash3 = polynomial_rolling_hash(str3, m);
    std::cout << "Polynomial rolling hash value: " << hash3 << std::endl;

    return 0;
}