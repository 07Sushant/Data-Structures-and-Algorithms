#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

Node* insertNode(Node* head, int value) {
    if (head == nullptr) {
        head = createNode(value);
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = createNode(value);
        temp->next->next = head;
    }
    return head;
}

Node* deleteEndNode(Node* head, int value) {
    if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
        return nullptr;
    }

    Node* temp = head;
    Node* prev = nullptr;
    Node* delNode = nullptr;

    while (temp->next != head) {
        if (temp->next->data == value) {
            prev = temp;
            delNode = temp->next;
        }
        temp = temp->next;
    }

    if (delNode == nullptr) {
        cout << "Value not found in the linked list!" << endl;
        return head;
    }

    if (delNode == head) {
        prev->next = head->next;
        delete head;
        head = prev->next;
    } else {
        prev->next = delNode->next;
        delete delNode;
    }

    return head;
}

void displayLinkedList(Node* head) {
    if (head == nullptr) {
        
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int numNodes;
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int value;
        cin >> value;
        head = insertNode(head, value);
    }
   cout << "Linked list before deletion" << endl;
    displayLinkedList(head);

    int valueToDelete;
    cin >> valueToDelete;

    head = deleteEndNode(head, valueToDelete);
    cout << "Linked list after deletion" << endl;
    displayLinkedList(head);

    return 0;
}


//Sushant