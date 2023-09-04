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

struct Node* deleteEvenPositionNodes(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* prev = head;
    struct Node* current = head->next;
    int position = 2;

    while (current != NULL) {
        if (position % 2 == 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
        position++;
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

    printf("Original Linked List: ");
    printList(head);

    head = deleteEvenPositionNodes(head);

    printf("Final Linked List: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

//Sushant