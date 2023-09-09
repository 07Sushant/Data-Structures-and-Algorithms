// You are using GCC

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* insertSorted(Node* head, int value) {
    Node* newNode = new Node(value);

    if (!head || value <= head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;

    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void displayList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    int n;
    std::cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        head = insertSorted(head, value);
    }

    int new_element;
    std::cin >> new_element;
    head = insertSorted(head, new_element);

    displayList(head);

    return 0;
}
