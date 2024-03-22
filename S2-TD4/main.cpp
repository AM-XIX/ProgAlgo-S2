#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>

int main() {

    // ===== Exercice 1 (Vector and Algorithm) =====
    
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
        std::cout << std::accumulate(v.begin(), it, 0) << std::endl;

        // comm 06 et décom ça pour avoir 01-02 seulement :
        // std::cout << *it << " ";
    }

    // ———————— 01-03 —————————
    auto it { std::find(v.begin(), v.end(), 69) };
    if (it != v.end())
    {
        // Essai bonus parce que j'avais mal compris la consigne :
        // std::cout << "Element found at position " << it - v.begin() << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    // ———————— 01-04 —————————
    std::cout << std::count(v.begin(), v.end(), 41) << std::endl;

}