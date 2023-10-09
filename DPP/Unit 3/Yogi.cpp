#include <iostream>
#include <string>

using namespace std;

const int MAX_EXPR_LEN = 100;

int is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')') {
        return 1;
    }
    return 0;
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

struct CharStack {
    char data[MAX_EXPR_LEN];
    int top;

    CharStack() {
        top = -1;
    }

    void push(char c) {
        if (top < MAX_EXPR_LEN - 1) {
            data[++top] = c;
        } else {
            cout << "Stack overflow!" << endl;
            exit(EXIT_FAILURE);
        }
    }

    char pop() {
        if (top >= 0) {
            return data[top--];
        } else {
            cout << "Stack underflow!" << endl;
            exit(EXIT_FAILURE);
        }
    }

    char peek() {
        if (top >= 0) {
            return data[top];
        } else {
            return '\0'; // Return null character for an empty stack.
        }
    }

    bool empty() {
        return top == -1;
    }
};

string infix_to_postfix(const string& infix) {
    CharStack operators;
    string postfix;
    char c;

    for (int i = 0; i < infix.length(); i++) {
        c = infix[i];
        if (!is_operator(c)) {
            postfix += c;
        } else {
            if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (operators.peek() != '(') {
                    postfix += operators.pop();
                }
                operators.pop(); // Pop the '('
            } else {
                while (!operators.empty() && operators.peek() != '(' && precedence(c) <= precedence(operators.peek())) {
                    postfix += operators.pop();
                }
                operators.push(c);
            }
        }
    }

    while (!operators.empty()) {
        postfix += operators.pop();
    }

    return postfix;
}

int main() {
    int num_expressions;
    string infix, postfix;

    cin >> num_expressions;

    for (int i = 1; i <= num_expressions; i++) {
        cin >> infix;
        postfix = infix_to_postfix(infix);
        cout << "Postfix expression " << i << ": " << postfix << endl;
    }

    return 0;
}
