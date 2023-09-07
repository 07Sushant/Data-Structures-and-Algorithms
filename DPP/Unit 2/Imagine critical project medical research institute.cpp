// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

int isPalindrome(struct Node* head) {
    struct Node* forward = head;
    struct Node* backward = head;

    while (backward->next != NULL) {
        backward = backward->next;
    }

    while (forward != backward && forward->prev != backward) {
        if (forward->data != backward->data) {
            return 0; 
        }
        forward = forward->next;
        backward = backward->prev;
    }

    return 1; 
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    if (isPalindrome(head)) {
        printf("The patient's medical history is a palindrome\n");
    } else {
        printf("The patient's medical history is not a palindrome\n");
    }

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}



//Sushant