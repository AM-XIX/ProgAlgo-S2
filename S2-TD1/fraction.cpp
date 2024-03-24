#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fraction.hpp"

// ====== Exercice 1 ======
Fraction operator+(const Fraction& fractA, const Fraction& fractB) {
    return Fraction(fractA.getNumerator() * fractB.getDenominator() + fractB.getNumerator() * fractA.getDenominator(),
                    fractA.getDenominator() * fractB.getDenominator());
}

Fraction operator-(const Fraction& fractA, const Fraction& fractB) {
    return Fraction(fractA.getNumerator() * fractB.getDenominator() - fractB.getNumerator() * fractA.getDenominator(),
                    fractA.getDenominator() * fractB.getDenominator());
}

Fraction operator*(const Fraction& fractA, const Fraction& fractB) {
    return Fraction(fractA.getNumerator() * fractB.getNumerator(),
                    fractA.getDenominator() * fractB.getDenominator());
}

Fraction operator/(const Fraction& fractA, const Fraction& fractB) {
    return Fraction(fractA.getNumerator() * fractB.getDenominator(),
                    fractA.getDenominator() * fractB.getNumerator());
}

// ====== Exercice 2 ======
std::ostream& operator<<(std::ostream& os, const Fraction& fract) {
    os << fract.getNumerator() << "/" << fract.getDenominator();
    return os;
}

// ====== Exercice 3 ======
bool operator==(const Fraction& fractA, const Fraction& fractB) {
    return (fractA.getNumerator() * fractB.getDenominator() == fractB.getNumerator() * fractA.getDenominator());
}
bool operator!=(const Fraction& fractA, const Fraction& fractB) {
    return !(fractA == fractB);
}

// ====== Exercice 4 ======
// -------- 04-01
bool operator<(const Fraction& fractA, const Fraction& fractB) {
    return (fractA.getNumerator() * fractB.getDenominator() < fractB.getNumerator() * fractA.getDenominator());
}
// -------- 04-02
bool operator>(const Fraction& fractA, const Fraction& fractB) {
    return (fractA.getNumerator() * fractB.getDenominator() > fractB.getNumerator() * fractA.getDenominator());
}
bool operator<=(const Fraction& fractA, const Fraction& fractB) {
    return !(fractA > fractB);
}
bool operator>=(const Fraction& fractA, const Fraction& fractB) {
    return !(fractA < fractB);
}

// ====== Exercice 5 ======
/*EXERCICE 5*/
