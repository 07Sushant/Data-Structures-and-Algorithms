#include <iostream>

class Node {
public:
    int customer_id;
    Node* next;

    Node(int id) : customer_id(id), next(nullptr) {}
};

class CustomerQueue {
private:
    Node* front;
    Node* rear;

public:
    CustomerQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int customer_id) {
        Node* new_customer = new Node(customer_id);
        if (rear == nullptr) {
            front = rear = new_customer;
        } else {
            rear->next = new_customer;
            rear = new_customer;
        }
        std::cout << "Customer ID " << customer_id << " is enqueued." << std::endl;
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        int customer_id = front->customer_id;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        std::cout << "Dequeued customer ID: " << customer_id << std::endl;
    }

    void display() {
        if (front == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* current = front;
        std::cout << "Customer IDs in the queue are: ";
        while (current) {
            std::cout << current->customer_id << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    CustomerQueue queue;

    int option;
    while (std::cin >> option) {
        if (option == 1) {
            int customer_id;
            std::cin >> customer_id;
            queue.enqueue(customer_id);
        } else if (option == 2) {
            queue.dequeue();
        } else if (option == 3) {
            queue.display();
        } else {
            std::cout << "Invalid option." << std::endl;
        }
    }

    return 0;
}
