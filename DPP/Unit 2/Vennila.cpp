#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

struct Node* deleteSecondToLastNode(struct Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }

    struct Node* current = head;
    while (current->next->next->next != NULL) {
        current = current->next;
    }

    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
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

    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Original Linked List: ");
    printList(head);

    head = deleteSecondToLastNode(head);

    printf("Updated Linked List: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

//Sushant