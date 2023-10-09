#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Adjust the maximum stack size as needed.

void push(char stack[], int &top, char c) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = c;
    }
}

void pop(char stack[], int &top) {
    if (top >= 0) {
        --top;
    }
}

char top(const char stack[], int top) {
    if (top >= 0) {
        return stack[top];
    }
    return '\0'; // Return a null character for an empty stack.
}

bool isEmpty(int top) {
    return top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

void infixToPostfix(const char* expression) {
    char result[MAX_SIZE];
    char operators[MAX_SIZE];
    int top_result = -1;
    int top_operators = -1;

    int i = 0;
    while (expression[i]) {
        char current = expression[i];

        if (isdigit(current)) {
            while (isdigit(current)) {
                result[++top_result] = current;
                current = expression[++i];
            }
            result[++top_result] = ' '; // Add space after operand
        }

        if (current == ' ' || current == '\t') {
            ++i; // Skip whitespace
            continue;
        }

        if (current == '\0') {
            break; // End of input
        }

        while (!isEmpty(top_operators) && precedence(current) <= precedence(top(operators, top_operators))) {
            result[++top_result] = top(operators, top_operators);
            result[++top_result] = ' '; // Add space after operator
            pop(operators, top_operators);
        }
        push(operators, top_operators, current);
        ++i;
    }

    while (!isEmpty(top_operators)) {
        result[++top_result] = top(operators, top_operators);
        result[++top_result] = ' '; // Add space after operator
        pop(operators, top_operators);
    }

    result[++top_result] = '\0'; // Null-terminate the result

    cout << "The Reverse Polish Notation (RPN) expression is: " << result;
}

int main() {
    char expression[MAX_SIZE];
    //cout << "Enter the infix expression: ";
    cin.getline(expression, MAX_SIZE);

    infixToPostfix(expression);

    return 0;
}
