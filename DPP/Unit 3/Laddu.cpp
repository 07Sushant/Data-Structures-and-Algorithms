#include <iostream>

using namespace std;

#define MAX_SIZE 10

bool isEmpty(int top) {
    return (top == -1);
}

bool isFull(int top) {
    return (top == MAX_SIZE - 1);
}

void push(int stack[], int &top, int item) {
    if (isFull(top)) {
        cout << "Stack is full!" << endl;
        return;
    }
    stack[++top] = item;
}

int pop(int stack[], int &top) {
    if (isEmpty(top)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return stack[top--];
}

int main() {
    int stack[MAX_SIZE];
    int top = -1;
    int choice, item;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> item;
                push(stack, top, item);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                if (isFull(top)) {
                    cout << "Stack is full!" << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 4:
                if (isEmpty(top)) {
                    cout << "Stack is empty!" << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
