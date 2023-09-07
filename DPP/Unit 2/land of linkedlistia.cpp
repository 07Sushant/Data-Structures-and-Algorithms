#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* insertAtEnd(Node* header, int value) {
    Node* newNode = new Node(value);

    if (!header) {
        newNode->next = newNode;
        return newNode; 
    } else {
        newNode->next = header->next; 
        header->next = newNode; 
        return newNode; 
    }
}

void display(Node* header) {
    if (!header) {
        return;
    }

    Node* current = header->next;
    bool firstElement = true;

    do {
        if (!firstElement) {
            cout << " ";
        }
        cout << current->data;
        firstElement = false;
        current = current->next;
    } while (current != header->next);

    cout << endl;
}

Node* pairwiseSwap(Node* header) {
    if (!header || header->next == header) {
        return header; 
    }

    Node* current = header->next;
    Node* prev = header;

    do {
        Node* nextNode = current->next;
        Node* nextPair = nextNode->next;

        prev->next = nextNode;
        nextNode->next = current;
        current->next = nextPair;

        prev = current;
        current = nextPair;

    } while (current != header->next && current->next != header->next);

    return header; 
}

int main() {
    int n;
    cin >> n;

    Node* header = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        header = insertAtEnd(header, value);
    }

    cout << "Original linked list: ";
    display(header);

    header = pairwiseSwap(header);

    cout << "Linked list after pairwise swapping: ";
    display(header);

    return 0;
}


//sUSHANT