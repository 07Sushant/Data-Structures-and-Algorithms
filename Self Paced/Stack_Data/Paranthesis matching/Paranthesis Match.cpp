#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
} * top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(const char *exp)
{
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
            {
                printf("Not Balanced\n");
                return 0;
            }
            pop();
        }
    }
    if (top == NULL)
    {
        printf("Balanced\n");
        return 1;
    }
    else
    {
        printf("Not Balanced\n");
        return 0;
    }
}

int main()
{   
    char expression[100];
    printf("Enter the expression: \n");
    scanf("%s", expression);

    isBalanced(expression);

    return 0;
}
