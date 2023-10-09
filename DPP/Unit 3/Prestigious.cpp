#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        cout << "Stack Overflow!" << endl;
        exit(EXIT_FAILURE);
    }
    stack->data[++(stack->top)] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack Underflow!" << endl;
        exit(EXIT_FAILURE);
    }
    return stack->data[(stack->top)--];
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evalPostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (isDigit(ch)) {
            push(&stack, ch - '0');
        } else if (isOperator(ch)) {
            int x = pop(&stack);
            int y = pop(&stack);

            int result;
            if (ch == '+') {
                result = y + x;
            } else if (ch == '-') {
                result = y - x;
            } else if (ch == '*') {
                result = y * x;
            } else if (ch == '/') {
                result = y / x;
            } else {
                exit(EXIT_FAILURE);
            }

            push(&stack, result);
        }
        i++;
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];
    cin.getline(postfix, sizeof(postfix));

    int result = evalPostfix(postfix);
    cout << result << endl;

    return 0;
}

