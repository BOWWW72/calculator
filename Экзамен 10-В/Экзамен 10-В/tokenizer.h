//tokenizer.h
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include "token.h"  // ������ ����� ����������� �����������
using namespace std;
vector<Token> tokenize(const string& expression);

#endif