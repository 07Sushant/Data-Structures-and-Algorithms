
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    free(temp);

    return value;
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    int input;
    while (1) {
        scanf("%d", &input);

        if (input == -1) {
            break;
        }

        enqueue(&q, input);
    }

    printf("Dequeued elements:");

    while (!isEmpty(&q)) {
        int value = dequeue(&q);
        printf(" %d", value);
    }

    printf("\n");

    return 0;
}