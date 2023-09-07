// You are using GCC
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(const string& value) : data(value), prev(nullptr), next(nullptr) {}
};

int countUniqueInteractions(Node* head) {
    unordered_set<string> uniqueSessions;
    int count = 0;
    
    Node* current = head;
    
    while (current != nullptr) {
        if (uniqueSessions.find(current->data) == uniqueSessions.end()) {
            uniqueSessions.insert(current->data);
            count++;
        }
        current = current->next;
    }
    
    return count;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); 
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < N; i++) {
        string sessionID;
        getline(cin, sessionID);
        
        Node* newNode = new Node(sessionID);
        
        if (tail != nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode;
        }
        
        tail = newNode;
    }
    
    int uniqueCount = countUniqueInteractions(head);
    
    cout << "Number of unique user interactions: " << uniqueCount << endl;
    
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}



///Sushant