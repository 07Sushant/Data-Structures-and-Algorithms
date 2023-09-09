#include <iostream>
using namespace std;

// Define a struct for a node in the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a new node at the front of the linked list
void insertAtFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insertAtFront(head, value);
    }

    cout << "Created Linked list: ";
    displayList(head);

    int new_element;
    cin >> new_element;
    insertAtFront(head, new_element);

    cout << endl << "Final List: ";
    displayList(head);

    return 0;
}

