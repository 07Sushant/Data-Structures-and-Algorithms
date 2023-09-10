#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** headRef, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (*headRef == nullptr) {
        *headRef = newNode;
        newNode->next = *headRef;
        return;
    }

    Node* temp = *headRef;
    while (temp->next != *headRef) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *headRef;
}

void printList(Node* head) {
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

Node* getIntersection(Node** heads, int numLists) {
    unordered_set<int> commonElements;
    Node* current = heads[0];

    // Store elements of the first linked list in the hash table
    do {
        commonElements.insert(current->data);
        current = current->next;
    } while (current != heads[0]);

    // Find common elements among the remaining linked lists
    for (int i = 1; i < numLists; i++) {
        current = heads[i];
        unordered_set<int> tempSet;

        // Find common elements with the hash table
        do {
            if (commonElements.find(current->data) != commonElements.end()) {
                tempSet.insert(current->data);
            }
            current = current->next;
        } while (current != heads[i]);

        // Update the common elements
        commonElements = tempSet;
    }

    // Create a new circular linked list with the common elements
    Node* result = nullptr;
    Node* tail = nullptr;

    for (int element : commonElements) {
        Node* newNode = new Node();
        newNode->data = element;

        if (result == nullptr) {
            result = newNode;
            result->next = result;
            tail = result;
        } else {
            newNode->next = result;
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}

int main() {
    int numLists;
    cin >> numLists;

    Node** heads = new Node*[numLists];

    for (int i = 0; i < numLists; i++) {
        heads[i] = nullptr;

        int numElements;
        cin >> numElements;

        for (int j = 0; j < numElements; j++) {
            int data;
            cin >> data;
            append(&heads[i], data);
        }
    }

    for (int i = 0; i < numLists; i++) {
        cout << "List " << i + 1 << ": ";
        printList(heads[i]);
    }

    Node* intersection = getIntersection(heads, numLists);

    cout << "Intersection: ";
    printList(intersection);

    return 0;
}


//Sushant