#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = *head;

    if (*head != nullptr)
        (*head)->prev = newNode;

    *head = newNode;
}

void reverseList(Node** head) {
    Node* current = *head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != nullptr)
        *head = temp->prev;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    int n, data;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> data;
        insertAtBeginning(&head, data);
    }

    std::cout << "Original List: ";
    printList(head);

    reverseList(&head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}

//Sushant