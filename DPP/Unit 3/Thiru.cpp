#include <iostream>
#include <limits.h>

using namespace std;

#define MAX_SIZE 10

int mainStack[MAX_SIZE];
int maxStack[MAX_SIZE];
int top = -1;
int max_top = -1;

void push(int ele) {
    if (top >= MAX_SIZE - 1) {
        return;
    }
    
    top++;
    mainStack[top] = ele;

    if (max_top == -1 || ele >= maxStack[max_top]) {
        max_top++;
        maxStack[max_top] = ele;
    }
}

int pop() {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return -1; // Return -1 to indicate an error or empty stack
    }
    
    int ele = mainStack[top];
    top--;
    if (ele == maxStack[max_top]) {
        max_top--;
    }
    return ele;
}

int getMax() {
    if (max_top < 0) {
        return -1; // Return -1 to indicate an error or empty stack
    }

    return maxStack[max_top];
}

void printstack(int *stack) {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, ele;
    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> ele;
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Maximum element: " << getMax() << endl;
                break;
            case 4:
                printstack(mainStack);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

