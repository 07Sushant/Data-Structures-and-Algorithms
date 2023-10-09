#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_SIZE = 100; // Adjust the maximum stack size as needed

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    } 
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } 
}

int topValue() {
    if (top >= 0) {
        return stack[top];
    } 
}

bool isEmpty() {
    return top == -1;
}

int evaluateRPN(string expression) {
    stringstream ss(expression);
    string token;

    while (getline(ss, token, ' ')) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = pop();
            int operand1 = pop();

            if (token == "+")
                push(operand1 + operand2);
            else if (token == "-")
                push(operand1 - operand2);
            else if (token == "*")
                push(operand1 * operand2);
            else if (token == "/")
                push(operand1 / operand2);
        } else {
            int number = stoi(token);
            push(number);
        }
    }

    return topValue();
}

int main() {
    string expression;
    getline(cin, expression);

    int result = evaluateRPN(expression);
    cout << "The result is: " << result << endl;

    return 0;
}
