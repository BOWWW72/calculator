//tokenizer.h
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include "token.h"  // Только прямо необходимые зависимости
using namespace std;
vector<Token> tokenize(const string& expression);

#endif