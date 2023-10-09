#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_STACK_SIZE = 10; // Maximum stack size

struct Node {
    int data;
    int sum;
};

struct Stack {
    Node stackArray[MAX_STACK_SIZE];
    int top;
    int size;
};

void init(Stack* s) {
    s->top = -1;
    s->size = 0;
}

void push(Stack* s, int value) {
    s->top++;
    s->stackArray[s->top].data = value;
    s->stackArray[s->top].sum = (s->top == 0) ? value : s->stackArray[s->top - 1].sum + value;
    s->size++;
}

int pop(Stack* s) {
    if (s->top < 0) {
        return -1; // Stack is empty
    }

    int value = s->stackArray[s->top].data;
    s->top--;
    s->size--;

    return value;
}

float get_average(Stack* s) {
    if (s->size == 0) {
        return -1; // Stack is empty
    }
    return (float)s->stackArray[s->top].sum / s->size;
}

void printStack(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        cout << s->stackArray[i].data << " ";
    }
    cout << endl;
}

int main() {
    Stack s;
    init(&s);

    int num_elements, value;
    cin >> num_elements;

    for (int i = 0; i < num_elements; i++) {
        cin >> value;
        push(&s, value);
    }
    printStack(&s);

    float avg_val = get_average(&s);
    if (avg_val != -1) {
        cout << "Average of the stack values: " << fixed << setprecision(2) << avg_val << endl;
    } 

    int popped_value = pop(&s);
    if (popped_value != -1) {
        cout << "Popped value: " << popped_value << endl;
    }

    avg_val = get_average(&s);
    if (avg_val != -1) {
        cout << "Average of the stack values: " << fixed << setprecision(2) << avg_val << endl;
    } 

    return 0;
}
