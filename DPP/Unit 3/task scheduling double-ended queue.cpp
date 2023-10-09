#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

void insertFront(Node** deque, int data) {
    Node* newNode = new Node(data);
    if (*deque == nullptr) {
        *deque = newNode;
    } else {
        newNode->next = *deque;
        (*deque)->prev = newNode;
        *deque = newNode;
    }
}

void insertBack(Node** deque, int data) {
    Node* newNode = new Node(data);
    if (*deque == nullptr) {
        *deque = newNode;
    } else {
        Node* temp = *deque;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printDeque(Node* deque) {
    Node* temp = deque;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* deque = nullptr;

    int element;
    cin >> element;
    insertFront(&deque, element);

    cin >> element;
    insertFront(&deque, element);

    cin >> element;
    insertBack(&deque, element);

    cin >> element;
    insertBack(&deque, element);

    cin >> element;
    insertFront(&deque, element);

    cin >> element;
    insertBack(&deque, element);

    printDeque(deque);

    return 0;
}