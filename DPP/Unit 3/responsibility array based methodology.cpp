
#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int maxSize;
    int* arr;

public:
    Queue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == maxSize - 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enQueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            arr[++rear] = data;
            if (front == -1) {
                front = 0;
            }
        }
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return a placeholder value indicating an error
        } else {
            int data = arr[front];
            if (front == rear) {
                front = rear = -1; // Reset front and rear when the last element is dequeued
            } else {
                front++;
            }
            return data;
        }
    }
};

int main() {
    int N;
    cin >> N;

    Queue q(N);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        q.enQueue(num);
    }

    cout << "Dequeuing elements:";
    while (!q.isEmpty()) {
        int element = q.deQueue();
        cout << " " << element;
    }
    cout << endl;

    return 0;
}