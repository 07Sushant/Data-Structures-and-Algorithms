#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertAtFront(Node*& head, Node*& tail, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void deleteAtFront(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return; 
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

void deleteAtEnd(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return; 
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int task;
        cin >> task;
        insertAtFront(head, tail, task);
    }

    printList(head);

    deleteAtFront(head, tail);
    printList(head);

    deleteAtEnd(head, tail);
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


//Susahnt