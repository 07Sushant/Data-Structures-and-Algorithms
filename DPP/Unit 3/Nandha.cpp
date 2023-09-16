// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element is " << top->data;
        }
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    Stack stack;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        stack.push(data);
    }

    stack.display();
    stack.displayTop();

    stack.pop();

    stack.display();
    stack.displayTop();

    return 0;
}
