#include <iostream>

using namespace std;

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

Node* deleteFirstNode(Node* head) {
    if (head == nullptr) {
        return nullptr; 
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

int main() {
    int n;
    cin >> n; 

    Node* head = nullptr; 

    for (int i = 0; i < n; i++) {
        int studentID;
        cin >> studentID;
        if (head == nullptr) {
            head = createNode(studentID);
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = createNode(studentID);
        }
    }

    head = deleteFirstNode(head);

    printLinkedList(head);

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

