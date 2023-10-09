
#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int evaluatePostfix(const string &expression) {
    stack<int> operandStack;

    for (char c : expression) {
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else if (c == '+') {
            int operand2 = operandStack.top();
            operandStack.pop();
int operand1 = operandStack.top();
            operandStack.pop();
            operandStack.push(operand1 + operand2);
        } else if (c == '-') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            operandStack.push(operand1 - operand2);
        } else if (c == '*') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            operandStack.push(operand1 * operand2);
        } else if (c == '/') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            operandStack.push(operand1 / operand2);
        }
    }

    return operandStack.top();
}

int main() {
    string expression;
    cin >> expression;

    int result = evaluatePostfix(expression);

    cout << result << endl;

    return 0;
}