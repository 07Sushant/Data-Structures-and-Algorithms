#include <iostream>
#include <cstring>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isValidPostfixExpression(const char* postfix) {
    int stack[100]; 
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            int operand = 0;
            while (isdigit(c)) {
                operand = operand * 10 + (c - '0');
                i++;
                c = postfix[i];
            }
            stack[++top] = operand;
        } else if (isOperator(c)) {
            if (top < 1) {
                return false; 
            }
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            switch (c) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        return false; // Division by zero
                    }
                    stack[++top] = operand1 / operand2;
                    break;
            }
        } else if (c != ' ') {
            return false; 
        }
    }

    return (top == 0); 
}

int main() {
    char postfixExpression[100];
    
    cin.getline(postfixExpression, sizeof(postfixExpression));

    if (isValidPostfixExpression(postfixExpression)) {
        cout << "Valid postfix expression" << endl;
    } else {
        cout << "Invalid postfix expression" << endl;
    }

    return 0;
}
