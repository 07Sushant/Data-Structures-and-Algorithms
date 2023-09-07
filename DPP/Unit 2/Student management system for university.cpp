#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* deleteElements(Node* head, vector<int>& toDelete) {
    Node* dummy = new Node(-1);
    dummy->next = head;
    
    Node* current = dummy;
    
    while (current->next) {
        if (find(toDelete.begin(), toDelete.end(), current->next->data) != toDelete.end()) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    
    head = dummy->next;
    delete dummy;
    
    return head;
}

void reverseAndPrint(Node* head) {
    vector<int> elements;
    while (head) {
        elements.push_back(head->data);
        head = head->next;
    }
    
    for (int i = elements.size() - 1; i >= 0; i--) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

int main() {
    int val;
    vector<int> elements;
    while (cin >> val && val != -1) {
        elements.push_back(val);
    }
    
    Node* head = nullptr;
    for (int i = elements.size() - 1; i >= 0; i--) {
        Node* newNode = new Node(elements[i]);
        newNode->next = head;
        head = newNode;
    }
    
    vector<int> toDelete;
    while (cin >> val && val != -1) {
        toDelete.push_back(val);
    }
    
    head = deleteElements(head, toDelete);
    
    reverseAndPrint(head);
    
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}

//Sushant
