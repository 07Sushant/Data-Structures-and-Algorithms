#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
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

    void swapPairwise() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            swap(current->data, current->next->data);
            current = current->next->next;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        list.insert(data);
    }

    cout << "Linked list before swapping pairwise: ";
    list.display();

    list.swapPairwise();

    cout << "Linked list after swapping pairwise: ";
    list.display();

    return 0;
}


//Sushant