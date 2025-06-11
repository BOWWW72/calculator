//rpn.cpp
#include "rpn.h"
#include "utils.h"
#include <stack>
#include <stdexcept>
#include <string>
using namespace std;
vector<Token> to_rpn(const vector<Token>& tokens) {
    vector<Token> output;
    stack<Token> operators;

    for (size_t i = 0; i < tokens.size(); ++i) {
        const Token& token = tokens[i];

        switch (token.type) {
        case TokenType::NUMBER:
            output.push_back(token);
            break;

        case TokenType::OPERATOR:
            if (token.value == "-" && is_unary_operator(token, i, tokens)) {
                operators.push({ TokenType::OPERATOR, "u", token.position });
            }
            else {
                while (!operators.empty() &&
                    operators.top().type == TokenType::OPERATOR &&
                    get_priority(operators.top().value) >= get_priority(token.value)) {
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
            }
            break;

        case TokenType::BRACKET:
            if (token.value == "(") {
                operators.push(token);
            }
            else {
                while (!operators.empty() && operators.top().value != "(") {
                    output.push_back(operators.top());
                    operators.pop();
                }
                if (operators.empty()) {
                    throw std::runtime_error("Unpaired bracket at position " + std::to_string(token.position));
                }
                operators.pop();
            }
            break;

        default:
            throw std::runtime_error("Unknown token: " + token.value + " at position " + std::to_string(token.position));
        }
    }

    while (!operators.empty()) {
        if (operators.top().value == "(") {
            throw std::runtime_error("Unpaired bracket at position " + std::to_string(operators.top().position));
        }
        output.push_back(operators.top());
        operators.pop();
    }

    return output;
}

double calculate_rpn(const std::vector<Token>& rpn_tokens) {
    std::stack<double> values;

    for (const Token& token : rpn_tokens) {
        if (token.type == TokenType::NUMBER) {
            values.push(std::stod(token.value));
            continue;
        }

        if (token.value == "u") {
            if (values.empty()) throw std::runtime_error("Not enough operands");
            double a = values.top(); values.pop();
            values.push(-a);
            continue;
        }

        if (values.size() < 2) throw std::runtime_error("Not enough operands");
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();

        if (token.value == "+") values.push(a + b);
        else if (token.value == "-") values.push(a - b);
        else if (token.value == "*") values.push(a * b);
        else if (token.value == "/") {
            if (b == 0) throw std::runtime_error("Division by zero");
            values.push(a / b);
        }
    }

    if (values.size() != 1) throw std::runtime_error("Calculation error");
    return values.top();
}