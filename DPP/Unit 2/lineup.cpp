// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    struct Node* current = head->next;
    int length = 1;

    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    k = k % length;

    if (k == 0) {
        return head;
    }

    struct Node* newTail = head->next;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }

    current->next = head->next;
    head->next = newTail->next;
    newTail->next = NULL;

    return head;
}

void printList(struct Node* head) {
    struct Node* current = head->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n); 
    struct Node* header = createNode(0); 
    struct Node* current = header;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        current->next = createNode(value);
        current = current->next;
    }

    int k;
    scanf("%d", &k);

    printf("Original List: ");
    printList(header);

    header = rotateRight(header, k);

    printf("Rotated List: ");
    printList(header);

    return 0;
}

