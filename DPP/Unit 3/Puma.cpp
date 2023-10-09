#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100; // Adjust the maximum stack size as needed

char stack[MAX_SIZE];
int top = -1;

void push(char value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    } else {
        cout << "Stack overflow!" << endl;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        cout << "Stack underflow!" << endl;
        return -1; // You can choose a different error value if needed
    }
}

char topValue() {
    if (top >= 0) {
        return stack[top];
    } else {
        cout << "Stack is empty!" << endl;
        return -1; // You can choose a different error value if needed
    }
}

bool isEmpty() {
    return top == -1;
}

int getPrecedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1; // For other characters, or invalid operators
    }
}

string infixToPostfix(string expression) {
    string result = "";
    
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (isspace(c)) {
            continue;
        } else if (isalnum(c)) {
            while (i < expression.length() && (isalnum(expression[i]) || expression[i] == '.')) {
                result += expression[i];
                i++;
            }
            //result += ' ';
            i--;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && topValue() != '(') {
                result += topValue();
                //result += ' ';
                pop();
            }
            pop();  // Discard the '('
        } else {
            while (!isEmpty() && getPrecedence(c) <= getPrecedence(topValue())) {
                result += topValue();
                //result += ' ';
                pop();
            }
            push(c);
        }
    }
    
    while (!isEmpty()) {
        result += topValue();
        //result += ' ';
        pop();
    }
    
    return result;
}

int main() {
    string infixExpression;
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "The RPN is: " << postfixExpression;

    return 0;
}
