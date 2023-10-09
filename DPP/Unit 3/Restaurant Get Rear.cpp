#include <iostream>

struct Queue {
int* arr; // array to store queue elements
int front; // front points to the front element in the queue
int rear; // rear points to the last element in the queue
int capacity; // maximum capacity of the queue
int size; // current size of the queue
};

void initializeQueue(Queue& q, int capacity) {
q.capacity = capacity;
q.arr = new int[capacity];
q.front = 0;
q.rear = -1;
q.size = 0;
}

bool isEmpty(const Queue& q) {
return q.size == 0;
}

bool isFull(const Queue& q) {
return q.size == q.capacity;
}

void enqueue(Queue& q, int item) {
if (isFull(q)) {
return;
}
q.rear = (q.rear + 1) % q.capacity;
q.arr[q.rear] = item;
q.size++;
}

int getFront(const Queue& q) {
if (isEmpty(q)) {
std::cout << "Queue is empty. No front element." << std::endl;
return -1;
}
return q.arr[q.front];
}

int getRear(const Queue& q) {
if (isEmpty(q)) {
std::cout << "Queue is empty. No rear element." << std::endl;
return -1;
}
return q.arr[q.rear];
}

int main() {
int N;
std::cin >> N;
Queue queue;
initializeQueue(queue, N); // Creating a queue of capacity N

for (int i = 0; i < N; i++) {
    int num;
    std::cin >> num;
    enqueue(queue, num);
}

std::cout << "Front element: " << getFront(queue) << std::endl;
std::cout << "Rear element: " << getRear(queue) << std::endl;

return 0;
}