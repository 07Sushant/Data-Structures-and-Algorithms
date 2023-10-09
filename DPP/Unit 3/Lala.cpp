#include <iostream>
#define MAX 15
using namespace std;

int top = -1;
int a[MAX];

bool push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow" << endl;
        return false;
    } else {
        a[++top] = x;
        return true;
    }
}

bool pop(int &x) {
    if (top < 0) {
        return false;
    } else {
        x = a[top--];
        return true;
    }
}

void display() {
    for (int i = 0; i <= top; i++) {
        cout << a[i] << " ";
    }
}

bool isEmpty() {
    return (top < 0);
}

int main() {
    int i, n;
    cin >> n;
    if (n > MAX) {
        cout << "Stack Overflow" << endl;
        return 0;
    }
    for (i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (!push(val)) {
            return 1; // Exit with an error code if there is a stack overflow
        }
    }
    display();

    int topElement;
    if (pop(topElement)) {
        cout << "\nTop element: " << topElement << endl;
        display();
    } else {
        cout << "Stack is empty." << endl;
    }

    return 0;
}
