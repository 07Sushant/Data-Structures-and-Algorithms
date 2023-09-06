#include <stdio.h>
#include <stdlib.h>

struct CharNode {
    char data;
    struct CharNode* next;
};

void insertAfterIndex(struct CharNode** head, int index, char value) {
    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }

    struct CharNode* newNode = (struct CharNode*)malloc(sizeof(struct CharNode));
    newNode->data = value;

    struct CharNode* current = *head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (currentIndex != index) {
        printf("Invalid index.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}


void printList(struct CharNode* head) {
    printf("Updated list: ");
    struct CharNode* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct CharNode* head) {
    struct CharNode* current = head;
    while (current != NULL) {
        struct CharNode* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct CharNode* head = NULL;
    struct CharNode* tail = NULL;
    for (int i = 0; i < n; i++) {
        char value;
        scanf(" %c", &value); 
        struct CharNode* newNode = (struct CharNode*)malloc(sizeof(struct CharNode));
        newNode->data = value;
        newNode->next = NULL;
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int index;
    char insertChar;
    scanf("%d %c", &index, &insertChar);

    insertAfterIndex(&head, index, insertChar);

    printList(head);

    freeList(head);

    return 0;
}


//sushant