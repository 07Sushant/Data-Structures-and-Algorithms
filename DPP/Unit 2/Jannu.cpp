// You are using GCC
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(const string& value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node*& head, const string& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(Node* head) {
    cout << "Linked List Contents:";
    while (head) {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    int num_of_strings;
    cin >> num_of_strings;

    Node* head = nullptr;

    for (int i = 0; i < num_of_strings; ++i) {
        string str;
        cin >> str;
        insertAtEnd(head, str);
    }

    string new_string;
    cin >> new_string;
    insertAtEnd(head, new_string);

    displayList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

//Sushant