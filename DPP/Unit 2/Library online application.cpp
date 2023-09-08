// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; 
    }
}

int main() {
    struct Node* head = NULL;
    int n;
    scanf("%d", &n);
    
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            char data;
            scanf(" %c", &data); 
            insertAtEnd(&head, data);
        }
    } else {
        printf("Linked List is empty.\n");
    }

    if (head != NULL) {
        struct Node* current = head;
        do {
            printf("%c ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    }
    
    return 0;
}



// Sushant