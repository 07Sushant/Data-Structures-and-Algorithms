// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;
    int size;

public:
    LinkedListStack() {
        top = nullptr;
        size = 0;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            Node* temp = top;
            int poppedValue = top->data;
            top = top->next;
            delete temp;
            size--;
            return poppedValue;
        }
    }


    bool isEmpty() {
        return top == nullptr;
    }


    bool isFull() {
        return size >= 32;
    }
};


string decimalToBinary(int decimal) {
    LinkedListStack stack;
    while (decimal > 0) {
        int remainder = decimal % 2;
        stack.push(remainder);
        decimal /= 2;
    }

    string binary = "";
    while (!stack.isEmpty()) {
        binary += to_string(stack.pop());
    }

    return binary;
}

int main() {
    int decimal;
    cin >> decimal;

    if (decimal >= 1 && decimal <= 512) {
        string binary = decimalToBinary(decimal);
        cout << "Binary representation: " << binary << endl;
    } else {
        cout << "Invalid input: Decimal number must be between 1 and 512." << endl;
    }

    return 0;
}
