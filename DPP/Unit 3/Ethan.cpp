#include <iostream>
#include <stdlib.h>

#define MAX_SIZE 100
using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Dequeue;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void initDequeue(Dequeue* dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

bool isEmpty(Dequeue* dq) {
    return (dq->front == NULL);
}

void enqueueFront(Dequeue* dq, int value) {
    Node* newNode = createNode(value);

    if (isEmpty(dq)) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void enqueueRear(Dequeue* dq, int value) {
    Node* newNode = createNode(value);

    if (isEmpty(dq)) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

int dequeueFront(Dequeue* dq) {
    if (isEmpty(dq)) {
        std::cout << "Dequeue is empty. Unable to dequeue.\n";
        return -1; // Assuming -1 is not a valid element
    }

    Node* frontNode = dq->front;
    int value = frontNode->value;
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->front = frontNode->next;
        dq->front->prev = NULL;
    }

    free(frontNode);
    return value;
}

void printMostRepeatedElement(Dequeue* dq) {
    int count[MAX_SIZE] = {0};
    int mostRepeatedElement = -1;
    int maxCount = 0;
    int value;

    while (!isEmpty(dq)) {
        value = dequeueFront(dq);

        if (value == -1)
            break;

        count[value]++;
        
        if (count[value] > maxCount) {
            maxCount = count[value];
            mostRepeatedElement = value;
        }
    }

    if (maxCount > 0) {
        cout<<"Most Repeated Element: "<<maxCount;
    } else {
        cout<<"No repeated elements found.";
    }
}

int main() {
    Dequeue dq;
    initDequeue(&dq);

    int value;

    while (1) {
        cin>>value;
        
        if (value == -1)
            break;

        enqueueRear(&dq, value);
    }

    printMostRepeatedElement(&dq);

    return 0;
}
