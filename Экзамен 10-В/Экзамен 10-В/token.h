//token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <cstddef>
#include <string>
using namespace std;
enum class TokenType {
    NUMBER,
    OPERATOR,
    BRACKET,
    UNKNOWN
};

struct Token {
    TokenType type;
    string value;
    size_t position;
};

#endif