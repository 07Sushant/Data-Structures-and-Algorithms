#include <iostream>
#include <cstring>
#include <cctype>

#define MAX_EXPR_LEN 100

char operators[] = "+-*/%^";
char functions[][5] = {"sin", "cos", "tan", "exp", "log", "sqrt"};

int is_operator(char c) {
    for (int i = 0; i < strlen(operators); i++) {
        if (c == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int is_function(char *str) {
    for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); i++) {
        if (strcmp(str, functions[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int get_precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/' || c == '%') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    char stack[MAX_EXPR_LEN];
    int top = -1;
    int len = strlen(infix);
    int i = 0, j = 0;
    while (i < len) {
        char token = infix[i];
        if (isdigit(token) || isalpha(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            stack[++top] = token;
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; 
        } else if (is_operator(token)) {
            while (top != -1 && stack[top] != '(' && get_precedence(token) <= get_precedence(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token;
        } else if (isalpha(token)) {
            char func[MAX_EXPR_LEN];
            int k = 0;
            while (isalpha(token)) {
                func[k++] = token;
                i++;
                token = infix[i];
            }
            func[k] = '\0';
            if (is_function(func)) {
                stack[++top] = '(';
                i--;
            } else {
                postfix[j++] = func[0];
                i--;
            }
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_EXPR_LEN], postfix[MAX_EXPR_LEN];
    std::cin.getline(infix, MAX_EXPR_LEN);
    infix_to_postfix(infix, postfix);
    std::cout << "Postfix expression: " << postfix << std::endl;
    return 0;
}
