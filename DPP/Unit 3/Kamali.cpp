#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

struct Stack {
    int stackArray[MAX_SIZE];
    int top;
};

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int value) {
    if (s->top >= MAX_SIZE - 1) {
        return;
    }

    s->top++;
    s->stackArray[s->top] = value;
}

int pop(Stack* s) {
    if (s->top < 0) {
        return -1;
    }

    int value = s->stackArray[s->top];
    s->top--;
    return value;
}

void sort_stack(Stack* s) {
    int tempStack[MAX_SIZE];
    int sortedTop = -1;

    while (s->top >= 0) {
        int temp = pop(s);
        while (sortedTop >= 0 && tempStack[sortedTop] < temp) {
            push(s, tempStack[sortedTop]);
            sortedTop--;
        }
        sortedTop++;
        tempStack[sortedTop] = temp;
    }

    while (sortedTop >= 0) {
        push(s, tempStack[sortedTop]);
        sortedTop--;
    }
}

void printStack(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        cout << s->stackArray[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    init(&s);

    int num_elements, value;

    cin >> num_elements;

    if (num_elements > MAX_SIZE) {
        cout << "Stack is full" << endl;
        return 0;
    }
    if (num_elements ==0 ) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    for (int i = 0; i < num_elements; i++) {
        cin >> value;
        push(&s, value);
    }

    cout << "Original stack: ";
    printStack(&s);

    sort_stack(&s);

    cout << "Sorted stack: ";
    printStack(&s);

    return 0;
}
