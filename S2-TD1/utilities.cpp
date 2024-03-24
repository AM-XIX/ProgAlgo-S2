#include <iostream>
#include "fraction.hpp"
#include "utilities.hpp"

float add(float fractA, float fractB) {
    return fractA + fractB;
}
float sub(float fractA, float fractB) {
    return fractA - fractB;
}
float mul(float fractA, float fractB) {
    return fractA * fractB;
}
float div(float fractA, float fractB) {
    return fractA / fractB;
}
float display(float fractA) {
    std::cout << fractA << std::endl;
}

int f1(int a, int b) {
    return a + b;
}
int f2(int a, int b) {
    return a - b;
}
