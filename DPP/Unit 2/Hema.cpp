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

struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* current = head;

    while (current != NULL) {
        struct Node* runner = current;

        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                struct Node* duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }

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
    int numNodes;
    scanf("%d", &numNodes);

    struct Node* head = NULL;

    for (int i = 0; i < numNodes; i++) {
        int value;
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Original List: ");
    printList(head);

    head = removeDuplicates(head);

    printf("Updated List: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0
}
