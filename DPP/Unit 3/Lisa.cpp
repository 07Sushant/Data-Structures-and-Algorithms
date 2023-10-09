#include <iostream>

const int MAX_SIZE = 100;

int stackA[MAX_SIZE];
int topA = -1;

int stackB[MAX_SIZE];
int topB = -1;

void pushA(int value) {
    if (topA == MAX_SIZE - 1) {
        return;
    }
    stackA[++topA] = value;
}

int popA() {
    if (topA == -1) {
        return -1;
    }
    return stackA[topA--];
}

void pushB(int value) {
    if (topB == MAX_SIZE - 1) {
        return;
    }
    stackB[++topB] = value;
}

int popB() {
    if (topB == -1) {
        return -1;
    }
    return stackB[topB--];
}

void reverseStack() {
    while (topA != -1) {
        int element = popA();
        pushB(element);
    }
}

void displayStackB() {
    std::cout << "Elements in Stack B (reversed): ";
    for (int i = topB; i >= 0; --i) {
        std::cout << stackB[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n, value;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        pushA(value);
    }

    std::cout << "Stack A elements: ";
    for (int i = topA; i >= 0; --i) {
        std::cout << stackA[i] << " ";
    }
    std::cout << std::endl;

    reverseStack();
    displayStackB();

    return 0;
}
