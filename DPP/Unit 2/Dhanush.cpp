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

    void insertNode(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        int count = 1;
        while (current != nullptr && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        list.insertNode(value, i + 1); 
    }

    int position;
    cin >> position;
    int value;
    cin >> value;
    list.insertNode(value, position); 
    list.printList();
    return 0;
}
