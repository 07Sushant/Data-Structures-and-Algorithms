#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue
    int* arr;    // Array to store elements in a zigzag pattern
    int capacity; // Capacity of the array
    int size;    // Current size of the queue

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        arr[size] = data;
        size++;
    }

    int dequeue() {
        if (front == nullptr) {
            return -1; // Queue is empty
        }

        Node* temp = front;
        int data = temp->data;

        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return data;
    }

    void displayZigzagPattern() {
        bool forward = true; // Flag to determine the direction of traversal
        int start = 0; // Starting index for traversal
        int end = size - 1; // Ending index for traversal

        while (start <= end) {
            if (forward) {
                std::cout << arr[start] << " ";
                start++;
            } else {
                std::cout << arr[end] << " ";
                end--;
            }
            forward = !forward; // Toggle the direction
        }

        std::cout << std::endl;
    }
};

int main() {
    int capacity;
    std::cin >> capacity;

    Queue queue(capacity);

    int element;
    std::cin >> element;
    while (element != -1) {
        queue.enqueue(element);
        std::cin >> element;
    }

    queue.displayZigzagPattern();

    return 0;
}