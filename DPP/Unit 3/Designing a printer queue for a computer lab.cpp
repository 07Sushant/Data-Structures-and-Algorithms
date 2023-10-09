
#include <iostream>

using namespace std;

struct Node {
    int pages;
    Node* next;
    
    Node(int p) : pages(p), next(nullptr) {}
};

class PrinterQueue {
private:
    Node* front;
    Node* rear;
    
public:
    PrinterQueue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(int pages) {
        Node* newNode = new Node(pages);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Print job with " << pages << " pages is enqueued." << endl;
    }
    
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        cout << "Processing print job: " << temp->pages << " pages" << endl;
        delete temp;
    }
    
    void displayQueue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Print jobs in the queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->pages << " pages ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    PrinterQueue queue;
    int option;
    
    while (cin >> option) {
        switch (option) {
            case 1:
                int pages;
                cin >> pages;
                queue.enqueue(pages);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.displayQueue();
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
    
    return 0;
}