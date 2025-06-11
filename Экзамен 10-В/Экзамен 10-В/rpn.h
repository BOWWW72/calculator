//rpn.h
#ifndef RPN_H
#define RPN_H

#include <vector>
#include "token.h"  // Только прямо необходимые зависимости
using namespace std;
vector<Token> to_rpn(const vector<Token>& tokens);
double calculate_rpn(const vector<Token>& rpn_tokens);

#endif