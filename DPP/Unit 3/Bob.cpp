#include <iostream>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct Deque {
    Node* front;
    Node* rear;
    int size;
};

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
}

bool isEmpty(Deque* deque) {
    return deque->size == 0;
}

void pushBack(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }

    deque->rear = newNode;
    deque->size++;
}

int getSize(Deque* deque) {
    return deque->size;
}

int main() {
    Deque myDeque;
    initDeque(&myDeque);
    int num;
    while (1) {
        std::cin >> num;
        if (num == -1)
            break;
        pushBack(&myDeque, num);
    }
    int count = getSize(&myDeque);
    std::cout << "Number of elements in the deque: " << count << std::endl;
    return 0;
}