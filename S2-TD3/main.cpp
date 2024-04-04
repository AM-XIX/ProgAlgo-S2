#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include "main.hpp"
#include <cctype>


 // ====== Exercice 1 ======
int calculNPI(const std::string& expression) {
    // -------- 01-02
    std::vector<std::string> tokens = split_string(expression);
    std::vector<int> stack;

    // -------- 01-01, 01-02
    for (const std::string& token : tokens) {
        if (isdigit(token[0])) {
            stack.push_back(std::stoi(token));
        } else {
            int operand2 = stack.back();
            stack.pop_back();
            int operand1 = stack.back();
            stack.pop_back();

            // ------ opérateurs
            if (token == "+") {
                stack.push_back(operand1 + operand2);
            } else if (token == "-") {
                stack.push_back(operand1 - operand2);
            } else if (token == "*") {
                stack.push_back(operand1 * operand2);
            } else if (token == "/") {
                stack.push_back(operand1 / operand2);
            }
        }
    }

    return stack.back();
}

// ------ 01-03
bool isFloat(const std::string& str) {
    bool hasDecimalPoint = false;
    bool hasDigit = false;

    for (char c : str) {
        if (std::isdigit(c)) {
            hasDigit = true;
        } else if (c == '.') {
            if (hasDecimalPoint) {
                return false;
            }
            hasDecimalPoint = true;
        } else {
            return false;
        }
    }
    return hasDigit && hasDecimalPoint;
}

// ------ 01-04 version (je faisais déjà le stack en 01 donc ça risque d'être mélangé mais voilà juste le 04)
float npi_evaluate(std::vector<std::string> const& tokens) {
    std::vector<float> stack;

    for (const std::string& token : tokens) {
        if (isFloat(token)) {
            stack.push_back(std::stof(token));
        } else {
            float operand2 = stack.back();
            stack.pop_back();
            float operand1 = stack.back();
            stack.pop_back();

            if (token == "+") {
                stack.push_back(operand1 + operand2);
            } else if (token == "-") {
                stack.push_back(operand1 - operand2);
            } else if (token == "*") {
                stack.push_back(operand1 * operand2);
            } else if (token == "/") {
                stack.push_back(operand1 / operand2);
            }
        }
    }

    return stack.back();
}

int main() {
    std::string expression;
    std::cout << "Entrer un calcul NPI : ";
    std::getline(std::cin, expression);

    // ------ 01-01
    int result = calculNPI(expression);
    // ------ 01-04
    // float result = npi_evaluate(split_string(expression));
    std::cout << "Résultat : " << result << std::endl;
    // PS : l'opérateur puissance a fait buguer mon terminal

    return 0;
}