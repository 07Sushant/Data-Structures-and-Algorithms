#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

bool isSorted(Node* head) {
    if (!head) {
        return true; }

    Node* current = head;
    do {
        if (current->data > current->next->data) {
            return false; 
        }
        current = current->next;
    } while (current->next != head);

    return true; 
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head; 
        } else {
            tail->next = newNode;
            tail = newNode;
            newNode->next = head; 
        }
    }

    if (isSorted(head)) {
        cout << "The list is sorted in non-decreasing order." << endl;
    } else {
        cout << "The list is not sorted in non-decreasing order." << endl;
    }

    if (head) {
        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }

    return 0;
}

//sUSHANT

