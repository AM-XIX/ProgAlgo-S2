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
Fraction& operator+=(Fraction& fractA, const Fraction& fractB) {
    fractA.num = fractA.num * fractB.den + fractB.num * fractA.den;
    fractA.den *= fractB.den;
    fractA.simplify();
    return fractA;
}

Fraction& operator-=(Fraction& fractA, const Fraction& fractB) {
    fractA.num = fractA.num * fractB.den - fractB.num * fractA.den;
    fractA.den *= fractB.den;
    fractA.simplify();
    return fractA;
}

Fraction& operator*=(Fraction& fractA, const Fraction& fractB) {
    fractA.num *= fractB.num;
    fractA.den *= fractB.den;
    fractA.simplify();
    return fractA;
}

Fraction& operator/=(Fraction& fractA, const Fraction& fractB) {
    fractA.num *= fractB.den;
    fractA.den *= fractB.num;
    fractA.simplify();
    return fractA;
}

// ====== Exercice 6 ======
// -------- 06-01/2
Fraction::operator float() const {
    Fraction f = *this;
    return f.to_float();
}

// ====== Aller + loin - 01 ======
Fraction operator+(Fraction const &f, int const i){
    Fraction result{0, 0};
    result.num = f.num + i * f.den;
    result.den = f.den;
    result.simplify();
    return result;
}

Fraction operator+(int const i, Fraction const &f){
    Fraction result{0, 0};
    result.num = f.num + i * f.den;
    result.den = f.den;
    result.simplify();
    return result;
}

Fraction operator-(Fraction const &f, int const i) {
    Fraction result(f.getNumerator() - i * f.getDenominator(), f.getDenominator());
    result.simplify();
    return result;
}

Fraction operator-(int i, const Fraction& f) {
    Fraction result(i * f.getDenominator() - f.getNumerator(), f.getDenominator());
    result.simplify();
    return result;
}

Fraction operator*(const Fraction& f, int i) {
    Fraction result(f.getNumerator() * i, f.getDenominator());
    result.simplify();
    return result;
}

Fraction operator*(int i, const Fraction& f) {
    Fraction result(f.getNumerator() * i, f.getDenominator());
    result.simplify();
    return result;
}

Fraction operator/(const Fraction& f, int i) {
    Fraction result(f.getNumerator(), f.getDenominator() * i);
    result.simplify();
    return result;
}

Fraction operator/(int i, const Fraction& f) {
    Fraction result(i * f.getDenominator(), f.getNumerator());
    result.simplify();
    return result;
}