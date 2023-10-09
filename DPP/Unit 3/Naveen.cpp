#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == NULL;
}

void push(struct Stack* stack, int data)
{
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void printStack(struct Stack* stack)
{
    struct Node* curr = stack->top;
    while (curr != NULL) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

void deleteEven(struct Stack* stack)
{
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->top = NULL;
    while (!isEmpty(stack)) {
        int val = pop(stack);
        if (val % 2 == 1)
            push(temp, val);
    }
    while (!isEmpty(temp)) {
        push(stack, pop(temp));
    }
    printStack(stack);
}

int main()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    int i, n, ele;
    cin>>n;
    for (i = 0; i < n; i++) {
        cin>>ele;
        push(stack, ele);
    }
    printStack(stack);
    cout<<endl;
    deleteEven(stack);
    return 0;
}
