#include <iostream>
#include <vector>
#include <cstdlib>
#include "utilities.cpp"
#include "fraction.cpp"

int main() {
    std::vector<Fraction> fractions;
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        fractions.push_back(Fraction(rand() % 10, rand() % 10 + 1));
    }
    for (auto& fract : fractions) {
        // 01 - bonus : simplifier
        fract.simplify();
        std::cout << fract.getNumerator() << "/" << fract.getDenominator() << " = " << fract.getFraction() << std::endl;
    }
    // ---- TEST DES OPÉRATEURS ----
    Fraction fractA(1, 2);
    Fraction fractB(1, 3);
    // --- 01
    std::cout << fractA << " + " << fractB << " = " << fractA + fractB << std::endl;
    std::cout << fractA << " - " << fractB << " = " << fractA - fractB << std::endl;
    std::cout << fractA << " * " << fractB << " = " << fractA * fractB << std::endl;
    std::cout << fractA << " / " << fractB << " = " << fractA / fractB << std::endl;
    // --- 03
    if (fractA == fractB) {
        std::cout << "Égales" << std::endl;
    } else {
        std::cout << "Pas égales" << std::endl;
    }
    // --- 04
    if (fractA != fractB) {
        std::cout << "Différentes" << std::endl;
    } else {
        std::cout << "Pas différentes" << std::endl;
    }

    // ====== Exercice 6 ======
    // -------- 06-03
    float floatA {static_cast<float>(fractA)};
    std::cout << "Fraction floatée : " << floatA << std::endl;

    return 0;
}