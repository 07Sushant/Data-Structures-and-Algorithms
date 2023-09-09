// You are using GCC
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void appendLeft(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void appendRight(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void printList() {
        Node* current = head;
        cout << "Linked List: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    int choice, value;
    while (true) {
        cin >> choice;
        if (choice == 1) {
            cin >> value;
            linkedList.appendLeft(value);
        } else if (choice == 2) {
            cin >> value;
            linkedList.appendRight(value);
        } else if (choice == 3) {
            linkedList.printList();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

