// You are using GCC
#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* swapPairs(Node* head) {
    Node* dummy = createNode(-1);
    dummy->next = head;
    Node* prev = dummy;
    Node* current = head;

    while (current && current->next) {
        Node* first = current;
        Node* second = current->next;
        
        prev->next = second;
        first->next = second->next;
        second->next = first;
        
        prev = first;
        current = first->next;
    }

    return dummy->next;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int data;
        std::cin >> data;

        Node* newNode = createNode(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    std::cout << "Linked list before swapping pairwise: ";
    printList(head);

    head = swapPairs(head);

    std::cout << "Linked list after swapping pairwise: ";
    printList(head);

    return 0;
}


//Sushant
