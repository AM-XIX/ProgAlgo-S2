#include <iostream>
#include <vector>
#include "encoding.hpp"

// ===== Exercice 1 =====
// ———————— 01-01 —————————
std::string runLengthEncoding(const std::string& str) {
    std::string res;
    int count = 1;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] != str[i - 1]) {
            res += std::to_string(count) + str[i - 1];
            count = 1;
        } else {
            count++;
        }
    }
    res += std::to_string(count) + str.back();

    return res;
}

// ———————— 01-02 —————————
std::string runLengthDecoding(const std::string& str) {
    std::string res;
    for (int i = 0; i < str.size(); i += 2) {
        int count = str[i] - '0';
        char ch = str[i + 1];
        res += std::string(count, ch);
    }
    return res;
}
