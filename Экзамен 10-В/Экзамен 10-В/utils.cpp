//utils.cpp
#include "utils.h"
#include "token.h"  // Теперь включаем здесь, а не в заголовке

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int get_priority(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

bool is_unary_operator(const Token& token, std::size_t index, const std::vector<Token>& tokens) {
    return token.value == "-" &&
        (index == 0 ||
            tokens[index - 1].type == TokenType::OPERATOR ||
            tokens[index - 1].value == "(");
}   