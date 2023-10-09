
#include <stdio.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
    int front, rear;
    int data[MAX_QUEUE_SIZE];
};

void initializeQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(struct Queue *q) {
    return q->front > q->rear;
}

void enqueue(struct Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->data[++q->rear] = item;
}

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reverseFirstK(struct Queue *q, int k) {
    if (isEmpty(q) || k <= 0 || k > (q->rear - q->front + 1)) {
        printf("Invalid reverse operation.\n");
        return;
    }

    reverseArray(q->data, q->front, q->front + k - 1);
}

void printQueue(struct Queue *q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue ticketQueue;
    initializeQueue(&ticketQueue);

    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        int ticket;
        scanf("%d", &ticket);
        enqueue(&ticketQueue, ticket);
    }

    reverseFirstK(&ticketQueue, k);
    printQueue(&ticketQueue);

    return 0;
}