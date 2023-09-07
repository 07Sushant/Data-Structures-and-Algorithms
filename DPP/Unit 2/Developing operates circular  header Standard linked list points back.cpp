// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;  
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void printAlternateNodes(Node* head) {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Alternate Nodes:");
    Node* current = head;
    int isEven = 1;
    do {
        if (isEven) {
            printf(" %d", current->data);
        }
        isEven = !isEven;
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data;

    scanf("%d", &n);

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &data);
            insertEnd(&head, data);
        }
    }

    printAlternateNodes(head);

    return 0;
}

//sushant