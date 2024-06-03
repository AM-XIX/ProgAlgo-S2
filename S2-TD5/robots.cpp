#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "robots.hpp"

// ===== Exercice 2 =====

// ———————— 02-00 - Set up —————————
std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

// ———————— 02-01 —————————
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> repairs_map;
    for (auto const& robot : robots_fixes) {
        std::string robotName = robot.first;
        repairs_map[robotName].push_back(0.0f);
    }
    return repairs_map;
}

// ———————— 02-02 —————————
float somme_vector(std::vector<float> const& vec) {
    float somme = 0.0f;
    for (float num : vec) {
        somme += num;
    }
    return somme;
}

// Je n'ai pas compris où le cost devait intervenir dans l'exo
int main() {
    // ———————— 02-03 —————————
    std::vector<std::pair<std::string, float>> robots_fixes = get_robots_fix(10);
    std::unordered_map<std::string, std::vector<float>> repairs_map = robots_fixes_map(robots_fixes);
    for (auto& repair : repairs_map) {
        std::vector<float>& repairs = repair.second;
        for (float& numRepairs : repairs) {
            numRepairs = std::rand() % 10;
        }
    }
    for (const auto& repair : repairs_map) {
        const std::string& robotName = repair.first;
        const std::vector<float>& repairs = repair.second;
        float totalRepairs = somme_vector(repairs);
        std::cout << robotName << " a " << totalRepairs << " réparations à faire." << std::endl;
    }
    return 0;
}