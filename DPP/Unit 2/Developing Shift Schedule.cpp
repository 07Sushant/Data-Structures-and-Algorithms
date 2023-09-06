// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void leftShift(struct Node** head, int k) {
    if (*head == NULL || k <= 0) {
        return;
    }

    struct Node* current = *head;
    int count = 1;

    while (count < k && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (current->next == NULL) {

        return;
    }

    struct Node* newHead = current->next;
    current->next = NULL;


    current = newHead;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = *head;

    *head = newHead;
}


void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    int n, shift, k;
    struct Node* head = NULL;


    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &shift);
        insertAtEnd(&head, shift);
    }

    scanf("%d", &k);

    printf("Original Linked List: ");
    printList(head);
    printf("\n");

    leftShift(&head, k);


    printf("Modified Linked List after left shift: ");
    printList(head);
    printf("\n");

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
