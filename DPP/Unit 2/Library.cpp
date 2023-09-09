// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; 

    if (head == NULL) {
        return newNode; 
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; 

    return head;
}

int main() {
    int n;
    scanf("%d", &n); 
    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        char data;
        scanf(" %c", &data); 
        head = insertEnd(head, data);
    }

    if (head == NULL) {
        printf("Linked List is empty.\n");
    } else {
        struct Node* current = head;
        do {
            printf("%c ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }

    return 0;
}

//Susahnt