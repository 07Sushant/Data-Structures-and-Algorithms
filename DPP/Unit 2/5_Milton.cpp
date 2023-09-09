#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; 
        return head;
    }
}

int isSorted(struct Node* head) {
    if (head == NULL) {
        return 1; 
    }
    struct Node* current = head;
    do {
        if (current->data > current->next->data) {
            return 0; 
        }
        current = current->next;
    } while (current->next != head); 
    return 1; 
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data); 
        head = insertEnd(head, data);
    }
    if (head == NULL || isSorted(head)) {
        printf("The list is sorted in non-decreasing order.\n");
    } else {
        printf("The list is not sorted in non-decreasing order.\n");
    }
    return 0;
}

