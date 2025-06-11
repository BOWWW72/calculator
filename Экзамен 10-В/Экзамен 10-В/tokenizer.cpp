//tokenizer.cpp
#include "tokenizer.h"
#include "utils.h"
#include <cctype>
using namespace std;
vector<Token> tokenize(const string& expression) {
    vector<Token> tokens;
    string current;
    size_t pos = 0;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isspace(c)) continue;

        if (is_operator(c) || c == '(' || c == ')') {
            if (!current.empty()) {
                tokens.push_back({ TokenType::NUMBER, current, pos });
                current.clear();
            }
            TokenType type = (c == '(' || c == ')') ? TokenType::BRACKET : TokenType::OPERATOR;
            tokens.push_back({ type, string(1, c), i });
            continue;
        }

        if (std::isdigit(c) || c == '.') {
            if (current.empty()) pos = i;
            current += c;
            continue;
        }

        tokens.push_back({ TokenType::UNKNOWN, std::string(1, c), i });
    }

    if (!current.empty()) {
        tokens.push_back({ TokenType::NUMBER, current, pos });
    }

    return tokens;
}