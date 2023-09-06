#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void push(Node** head_ref, string new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(Node** head_ref, string new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    Node* last = *head_ref;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        push(&head, str);
    }
    cout << "Document:";
    printList(head);
    string new_string;
    cin >> new_string;
    append(&head, new_string);
    cout << "\nUpdated Document:";
    printList(head);
    return 0;
}



//Sushant