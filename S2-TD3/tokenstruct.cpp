#include "tokenstruct.hpp"
#include <stack>

// -------- 02-02
Token make_token(Operator op) {
    Token token;
    token.type = TokenType::OPERATOR;
    token.op = op;
    return token;
}

// -------- 02-03
float evaluate_npi(std::vector<Token> const& tokens) {
    std::stack<double> stack;
    
    for (const Token& token : tokens) {
        if (token.type == TokenType::OPERAND) {
            stack.push(token.value);
        } else if (token.type == TokenType::OPERATOR) {
            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();
            
            double result = 0.0;
            switch (token.op) {
                case Operator::ADD:
                    result = operand1 + operand2;
                    break;
                case Operator::SUB:
                    result = operand1 - operand2;
                    break;
                case Operator::MUL:
                    result = operand1 * operand2;
                    break;
                case Operator::DIV:
                    result = operand1 / operand2;
                    break;
            }
            
            stack.push(result);
        }
    }
    
    return stack.top();
}