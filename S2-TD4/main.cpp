#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include "main.hpp"

// ===== Exercice 2 =====
// ———————— 02-01 —————————
int countLetters(const std::string& sentence) {
    auto it = std::find(sentence.begin(), sentence.end(), ' ');
    return std::distance(sentence.begin(), it);
}

// ———————— 02-02 —————————
std::vector<std::string> splitSentence(const std::string& sentence) {
    std::vector<std::string> words;
    std::string word;
    std::istringstream iss(sentence);
    
    while (iss >> word) {
        words.push_back(word);
    }
    
    return words;
}

 // ===== Exercice 3 =====
bool isPalindrome(const std::string& str) {
    return std::equal(std::begin(str), std::end(str), std::rbegin(str));
}

int main() {
    // ===== Exercice 1 =====
    // ———————— 01-01 —————————
    std::vector<int> v(10);
    // -------- Remplissage du vecteur
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 101;
        // std::cout << v[i] << " ";
    }

    // ———————— 01-02 —————————
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        // ———————— 01-05 —————————
        std::sort(v.begin(), v.end());

        // ———————— 01-06 —————————
        // std::cout << std::accumulate(v.begin(), it, 0) << std::endl;

        // comm 06 et décom ça pour avoir 01-02 seulement :
        // std::cout << *it << " ";
    }

    // ———————— 01-03 —————————
    auto it { std::find(v.begin(), v.end(), 80) };
    if (it != v.end())
    {
        // Essai bonus parce que j'avais mal compris la consigne bruh :
        // std::cout << "Element found at position " << it - v.begin() << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    // ———————— 01-04 —————————
    std::cout << std::count(v.begin(), v.end(), 41) << std::endl;
    
    // ———————— 02-01 —————————
    std::cout << countLetters("Trololol") << std::endl;
    
    // ———————— 02-02 —————————
    std::vector<std::string> words = splitSentence("Tololo lolol ololol");
    for (const std::string& word : words) {
        std::cout << word << std::endl;
    }
    std::cout << std::endl;

    // ===== Exercice 3 =====
    std::cout << isPalindrome("kayak") << std::endl;
}
