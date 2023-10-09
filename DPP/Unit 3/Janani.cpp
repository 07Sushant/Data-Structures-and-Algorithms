#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    } else {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(const char *infix, char *postfix) {
    Stack operatorStack;
    initialize(&operatorStack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (operatorStack.top >= 0 && precedence(operatorStack.data[operatorStack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        } else if (infix[i] == '(') {
            push(&operatorStack, infix[i]);
        } else if (infix[i] == ')') {
            while (operatorStack.top >= 0 && operatorStack.data[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            if (operatorStack.top >= 0 && operatorStack.data[operatorStack.top] == '(') {
                pop(&operatorStack);
            } 
        }
        i++;
    }

    while (operatorStack.top >= 0) {
        if (operatorStack.data[operatorStack.top] == '(') {
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
