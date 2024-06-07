#include <iostream>
#include <vector>
#include "main.hpp"
#include "encoding.cpp"

int main() {
    // ===== Exercice 1 =====
    // ———————— 01-01 —————————
    std::string test = "AAAABBBCCDAA";
    std::string encoded = runLengthEncoding(test);
    std::cout << "Résultat : " << encoded << std::endl;

    // ———————— 01-02 —————————
    std::string test2 = "12A3B2C1D2A";
    std::string decoded = runLengthDecoding(test2);
    std::cout << "Résultat : " << decoded << std::endl;
    //fail

    return 0;
}
