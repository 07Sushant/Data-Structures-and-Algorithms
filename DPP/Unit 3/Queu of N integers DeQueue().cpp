#include <iostream>

// Define the maximum size of the queue
const int MAXSIZE = 25;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to enqueue an element into the queue
    void enqueue(int item) {
        Node* newNode = new Node();
        newNode->data = item;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue an element from the front of the queue
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Underflow" << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Function to print the queue
    void printQueue() {
        if (front == nullptr) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    int N;
    std::cin >> N;

    Queue queue;

    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        queue.enqueue(num);
    }

    queue.dequeue();
    queue.printQueue();

    return 0;
}
