#include <iostream>
#define MAX 25

int queue[MAX];
int rear = -1;
int front = -1;

void Enqueue(int data) {
    if (rear == MAX - 1)
        std::cout << "Overflow" << std::endl;
    else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = data;
    }
}

void Dequeue() {
    if (front == -1 || front > rear) {
        std::cout << "Underflow" << std::endl;
        return;
    } else {
        front = front + 1;
    }
}

void display() {
    if (front == -1)
        std::cout << "Queue is empty" << std::endl;
    else {
        for (int i = front; i <= rear; i++)
            std::cout << queue[i] << " ";
        std::cout << std::endl;
    }
}

int main() {
    int n, i, e;
    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> e;
        Enqueue(e);
    }
    Dequeue();
    display();

    return 0;
}

