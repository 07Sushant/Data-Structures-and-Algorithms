
#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    
public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    bool isEqual(Queue& other) {
        Node* curr1 = front;
        Node* curr2 = other.front;
        
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->data != curr2->data) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return curr1 == nullptr && curr2 == nullptr;
    }
};

int main() {
    Queue queue1, queue2;
    int N1, N2;
    
    std::cin >> N1;
    for (int i = 0; i < N1; ++i) {
        int val;
        std::cin >> val;
        queue1.enqueue(val);
    }
    
    std::cin >> N2;
    for (int i = 0; i < N2; ++i) {
        int val;
        std::cin >> val;
        queue2.enqueue(val);
    }
    
    if (queue1.isEqual(queue2)) {
        std::cout << "The queues have the same elements in the same order." << std::endl;
    } else {
        std::cout << "The queues do not have the same elements in the same order." << std::endl;
    }
    
    return 0;
}