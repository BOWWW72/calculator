//main.cpp
#include <iostream>
#include <string>
#include "tokenizer.h"
#include "rpn.h"
using namespace std;
int main() {
    cout << "Expression Calculator" << endl;
    cout << "Supported operations: + - * / ( )" << endl;
    cout << "Enter expression or 'exit' to quit:" << endl;

    while (true) {
        cout << "> ";
        string input;
        getline(std::cin, input);

        if (input == "exit") break;
        if (input.empty()) continue;

        try {
            auto tokens = tokenize(input);
            auto rpn = to_rpn(tokens);
            double result = calculate_rpn(rpn);
            cout << "Result: " << result << endl;
        }
        catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}