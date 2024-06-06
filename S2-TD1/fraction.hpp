#pragma once
#include <numeric>

struct Fraction {
    int num {0};
    int den {1};
    int fraction = num / den;
    Fraction(int num, int den) : num(num), den(den) {}
    int getNumerator() const { return num; }
    int getDenominator() const { return den; }
    int getFraction() const { return fraction; }
    void setNumerator(int num) { this->num = num; }
    void setDenominator(int den) { this->den = den; }
    void setFraction(int fraction) { this->fraction = fraction;}
    void simplify();

    // ====== Exercice 6 ======
    // -------- 06-01
    float to_float() {
        return (float)num/(float)den;
    }
    operator float() const;
};

// ====== Exercice 1 ======
Fraction operator+(const Fraction& fractA, const Fraction& fractB);
Fraction operator-(const Fraction& fractA, const Fraction& fractB);
Fraction operator*(const Fraction& fractA, const Fraction& fractB);
Fraction operator/(const Fraction& fractA, const Fraction& fractB);

// 01 - bonus : simplifier
// PS : je suis partie sur du gdc, je sais pas si on avait le droit
void Fraction::simplify() {
    int gcd = std::gcd(num, den);
    num /= gcd;
    den /= gcd;
}

// ====== Exercice 2 ======
std::ostream& operator<<(std::ostream& os, const Fraction& fract);

// ====== Exercice 3 ======
bool operator==(const Fraction& fractA, const Fraction& fractB);
bool operator!=(const Fraction& fractA, const Fraction& fractB);

// ====== Exercice 4 ======
// -------- 04-01
bool operator<(const Fraction& fractA, const Fraction& fractB);
// -------- 04-02
bool operator>(const Fraction& fractA, const Fraction& fractB);
bool operator<=(const Fraction& fractA, const Fraction& fractB);
bool operator>=(const Fraction& fractA, const Fraction& fractB);

// ====== Exercice 5 ======
Fraction operator+=(const Fraction& fractA, const Fraction& fractB);
Fraction operator-=(const Fraction& fractA, const Fraction& fractB);
Fraction operator*=(const Fraction& fractA, const Fraction& fractB);
Fraction operator/=(const Fraction& fractA, const Fraction& fractB);

// ====== Aller + loin - 01 ======
Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);

Fraction operator-(Fraction const& f, int const i);
Fraction operator-(int const i, Fraction const& f);

Fraction operator*(Fraction const& f, int const i);
Fraction operator*(int const i, Fraction const& f);

Fraction operator/(Fraction const& f, int const i);
Fraction operator/(int const i, Fraction const& f);
