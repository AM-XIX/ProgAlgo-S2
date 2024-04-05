#pragma once
#include <vector>
#include <string>

 // ====== Exercice 2 ======
// -------- 02-01
enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

// -------- 02-02
Token make_token(Operator op);

// -------- 02-03
std::vector<Token> tokenize(std::vector<std::string> const& words);

// -------- 02-04
float npi_evaluate(std::vector<Token> const& tokens);

