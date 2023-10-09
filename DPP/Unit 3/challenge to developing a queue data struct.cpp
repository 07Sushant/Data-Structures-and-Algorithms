#include <iostream>
#include <cstdlib>
using namespace std;

// Define the node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Define the queue structure
struct Queue {
    Node* front;
    Node* rear;
};

// Initialize an empty queue
void initializeQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

// Enqueue (add to the back) operation
void enqueue(Queue& q, int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    
    if (q.rear == nullptr) {
        q.front = newNode;
        q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

// Dequeue (remove from the front) operation
int dequeue(Queue& q) {
    if (q.front == nullptr) {
        cerr << "Queue is empty." << endl;
        return -1;
    }
    
    int data = q.front->data;
    Node* temp = q.front;
    q.front = q.front->next;
    
    // If the queue becomes empty after dequeue, update the rear pointer
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    
    delete temp;
    return data;
}

// Display the elements of the queue
void display(Queue& q) {
    Node* current = q.front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Queue myQueue;
    initializeQueue(myQueue);
    
    int d;
    do {
        cin >> d;
        if (d > 0) {
            enqueue(myQueue, d);
        }
    } while (d > -1);
    
    
    
    // Dequeue and display elements
    cout << "Dequeued elements: ";
    while (myQueue.front != nullptr) {
        int element = dequeue(myQueue);
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}