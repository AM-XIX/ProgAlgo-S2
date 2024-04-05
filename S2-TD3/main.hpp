#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

// -------- 01-02
std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

// -------- 01-03
bool is_floating(std::string const& s);

// -------- 01-04
float npi_evaluate(std::vector<std::string> const& tokens);
