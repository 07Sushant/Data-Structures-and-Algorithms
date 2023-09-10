
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

// Function to display the linked list
void displayList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert a new data point into the sorted linked list
Node* insertSorted(Node* head, int newData) {
    Node* newNode = new Node(newData);

    // If the list is empty or the new data is smaller than the head, insert at the beginning
    if (head == nullptr || newData < head->data) {
        newNode->next = head;
        return newNode;
    }

    // Traverse the list to find the appropriate position to insert the new data
    Node* current = head;
    while (current->next != nullptr && current->next->data < newData) {
        current = current->next;
    }

    // Insert the new data point
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main() {
    Node* head = nullptr;  // Initialize an empty linked list

    int n;
    cin >> n;

    cout << "Original data points: ";  // Print this line once before insertions

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        // Insert the data point into the sorted linked list
        head = insertSorted(head, data);
    }

    displayList(head);  // Display the sorted linked list after all insertions

    int newData;
    cin >> newData;
    // Insert the new data point into the sorted linked list
    head = insertSorted(head, newData);

    cout << "Updated data points: ";  // Print this line once after inserting the new data point
    displayList(head);  // Display the sorted linked list after inserting the new data point

    return 0;
}


///Sushanat
