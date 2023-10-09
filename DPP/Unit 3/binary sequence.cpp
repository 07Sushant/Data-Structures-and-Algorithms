#include <iostream>

struct Node {
    std::string data;
    Node* next;
    Node(const std::string& value) : data(value), next(nullptr) {}
};

struct Queue {
    Node* front;
    Node* rear;
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(const std::string& item) {
        Node* newNode = new Node(item);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
};

void generatePrintBinary(int n) {
    Queue queue;
    queue.enqueue("1");

    Node* current = queue.front;

    while (n--) {
        std::string s1 = current->data;
        std::cout << s1 << " ";

        std::string s2 = s1;

        queue.enqueue(s1 + "0");
        queue.enqueue(s2 + "1");

        current = current->next;
    }
}

int main() {
    int n;
    std::cin >> n;
    generatePrintBinary(n);

    return 0;
}