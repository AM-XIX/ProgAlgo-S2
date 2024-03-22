#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

// ------ Notation Polonaise inversée
int calculNPI(const std::string& expression) {

    std::vector<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        // ------ vérifier si nombre
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

int main() {
    std::string expression;
    std::cout << "Entrer un calcul NPI : ";
    std::getline(std::cin, expression);

    int result = calculNPI(expression);
    std::cout << "Résultat : " << result << std::endl;

    return 0;
}