#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

void insertAtEnd(Node*& head, Node*& tail, const string& name) {
    Node* newNode = new Node;
    newNode->data = name;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }

    tail = newNode;
}

void splitLinkedList(Node* head, Node*& firstHalfTail, Node*& secondHalfHead) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    int middle = count / 2;
    current = head;
    
    for (int i = 0; i < middle; i++) {
        current = current->next;
    }

    firstHalfTail = current->prev;
    secondHalfHead = current;
    firstHalfTail->next = nullptr;
    secondHalfHead->prev = nullptr;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; i++) {
        string name;
        getline(cin, name);
        insertAtEnd(head, tail, name);
    }

    Node* firstHalfTail = nullptr;
    Node* secondHalfHead = nullptr;

    splitLinkedList(head, firstHalfTail, secondHalfHead);

    Node* current = head;

    
    while (current != firstHalfTail) {
        cout << current->data << " ";
        current = current->next;
    }
    if (current != nullptr) {
        cout << current->data << endl;
    } else {
        cout << "" << endl;
    }

    
    current = secondHalfHead;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "" << endl;

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}



//Sushant