#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};

void deleteMid(struct Node** head_ref, int n) {
    if (*head_ref == NULL || n == 0) {
        return;
    }

    if (n == 1) {
        struct Node* temp = *head_ref;
        *head_ref = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = *head_ref;
    int count = 0;

    while (curr != NULL) {
        if (count == n / 2) {
            prev->next = curr->next;
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
        count++;
    }
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        cout<< node->data<<" ";
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int i, n;
    cin>>n;
    for (i = n; i > 0; i--) {
        push(&head, i);
    }
    deleteMid(&head, n);
    printList(head);
    return 0;
}
