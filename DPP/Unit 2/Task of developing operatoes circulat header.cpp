#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

void insertEnd(Node*& last, int data) {
    Node* newNode = new Node(data);
    if (!last) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void printAlternateNodes(Node* last) {
    if (!last) {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node* current = last->next;
    bool print = true;

    cout << "Alternate Nodes: ";
    while (current != last) {
        if (print) {
            cout << current->data << " ";
        }
        print = !print;
        current = current->next;
    }
    cout << current->data << endl;
}

int main() {
    int n;
    cin >> n;

    Node* last = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertEnd(last, data);
    }

    printAlternateNodes(last);

    return 0;
}


//Sushant