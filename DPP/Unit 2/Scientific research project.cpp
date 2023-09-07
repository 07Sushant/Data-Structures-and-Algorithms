#include <iostream>
using namespace std;

struct Node {
    float data;
    Node* next;

    Node(float val) : data(val), next(nullptr) {}
};

void insertAtEnd(Node*& header, float value) {
    Node* newNode = new Node(value);
    
    if (!header) {
        newNode->next = newNode;
        header = newNode; 
    } else {
        newNode->next = header->next; 
        header->next = newNode; 
        header = newNode; 
    }
}

void display(Node* header) {
    if (!header) {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node* current = header->next;

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != header->next);

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* header = nullptr;

    for (int i = 0; i < n; i++) {
        float value;
        cin >> value;
        insertAtEnd(header, value);
    }

    display(header);

    if (header) {
        Node* current = header;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != header);
    }

    return 0;
}



//sUSHANT