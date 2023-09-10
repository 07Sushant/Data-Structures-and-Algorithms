#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteNodes(struct Node** head, int start, int end) {
    if (*head == NULL || start >= end) {
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    int position = 1;

    while (position < start && current != NULL) {
        prev = current;
        current = current->next;
        position++;
    }

    while (position <= end && current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
        position++;
    }

    if (prev != NULL) {
        prev->next = current;
    } else {
        *head = current;
    }

    if (position <= end) {
        *head = NULL;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < size; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int start, end;
    scanf("%d %d", &start, &end);

    printf("Linked List before deletion: ");
    printList(head);

    deleteNodes(&head, start, end);

    if (head == NULL) {
        printf("Linked List after deletion: all the elements are deleted\n");
    } else {
        printf("Linked List after deletion: ");
        printList(head);
    }

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


//Sushant

