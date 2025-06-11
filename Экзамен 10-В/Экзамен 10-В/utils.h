//utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// Предварительное объявление вместо #include "token.h"
struct Token;
enum class TokenType;

bool is_operator(char c);
int get_priority(const std::string& op);
bool is_unary_operator(const Token& token, std::size_t index, const std::vector<Token>& tokens);

#endif