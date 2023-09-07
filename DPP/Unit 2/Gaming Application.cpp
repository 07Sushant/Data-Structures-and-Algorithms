#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularHeaderLinkedList {
private:
    Node* header;

public:
    CircularHeaderLinkedList() {
        header = nullptr; 
    }

    void addScoreAtFront(int value) {
        Node* newNode = new Node(value);
        if (!header) {
            newNode->next = newNode;
            header = newNode; 
        } else {
            newNode->next = header->next; 
            header->next = newNode; 
        }
    }

    void addScoreAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!header) {
            newNode->next = newNode;
            header = newNode; 
        } else {
            newNode->next = header->next; 
            header->next = newNode; 
            header = newNode; 
        }
    }

    void displayScores() {
        if (!header) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = header->next;
        int count = 0;
        
        do {
            current = current->next;
            count++;
        } while (current != header->next);

        cout << "Number of nodes in the CLL is " << count << endl;
        
        int ncount = 0;
        
        do{
            cout << current->data << " ";
            current = current->next;
            count++;
        } while (current != header->next);
    }
};

int main() {
    CircularHeaderLinkedList cll;

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        cll.addScoreAtFront(score);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int score;
        cin >> score;
        cll.addScoreAtEnd(score);
    }

    cll.displayScores();

    return 0;
}


//Sushant