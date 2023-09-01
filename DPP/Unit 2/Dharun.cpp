
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertNode(string value) {
        Node* newNode = new Node(value);
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

    void deleteLastNode() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;

    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;
        list.insertNode(value);
    }

    list.deleteLastNode();
    list.printList();
    
    return 0;
}

//Sushant