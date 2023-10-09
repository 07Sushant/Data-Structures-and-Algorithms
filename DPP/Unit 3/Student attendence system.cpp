#include <iostream>

const int MAX_SIZE = 100;

struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(Queue& q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(const Queue& q) {
    return q.front == -1;
}

bool isFull(const Queue& q) {
    return q.rear == MAX_SIZE - 1;
}

void enqueue(Queue& q, int data) {
    if (isFull(q)) {
        return;
    }

    if (isEmpty(q)) {
        q.front = 0;
    }

    q.rear++;
    q.queue[q.rear] = data;
}

int countOccurrences(const Queue& q, int element) {
    int count = 0;

    if (isEmpty(q)) {
        return count;
    }

    for (int i = q.front; i <= q.rear; i++) {
        if (q.queue[i] == element) {
            count++;
        }
    }

    return count;
}

int main() {
    Queue queue;
    initializeQueue(queue);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        enqueue(queue, element);
    }

    int searchElement;
    std::cin >> searchElement;

    int occurrences = countOccurrences(queue, searchElement);

    std::cout << "Occurrences of " << searchElement << " in the queue: " << occurrences << std::endl;

    return 0;
}
