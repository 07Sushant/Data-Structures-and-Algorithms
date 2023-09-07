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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            std::cout << "Linked List is empty." << std::endl;
        } else {
            std::cout << "Linked List: ";
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    LinkedList linkedList;
    int value;

    while (true) {
        std::cin >> value;
        if (value < 0) {
            break; 
        }
        linkedList.insert(value);
    }

    linkedList.display();

    return 0;
}


//Sushant