#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100; 

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return true;
    }
    return false;
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(string infix, string& postfix) {
    char stack[MAX_SIZE];
    int top = -1;  

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix += ch;
        } else if (isOperator(ch)) {
            while (top >= 0 && stack[top] != '(' && precedence(ch) <= precedence(stack[top])) {
                postfix += stack[top];
                top--;
            }
            top++;
            stack[top] = ch;
        } else if (ch == '(') {
            top++;
            stack[top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix += stack[top];
                top--;
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        }
    }

    while (top >= 0) {
        postfix += stack[top];
        top--;
    }
}

int main() {
    string infix, postfix;
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
