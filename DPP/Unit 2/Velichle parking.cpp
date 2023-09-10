#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to rotate the linked list counter-clockwise by k positions
struct Node* rotateLinkedList(struct Node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }

    struct Node* current = head;
    int count = 1;

    // Traverse to the kth node
    while (count < k && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (current->next == NULL) {
        // k is greater than or equal to the length of the list
        return head;
    }

    struct Node* newHead = current->next;
    newHead->prev = NULL;
    current->next = NULL;

    // Traverse to the end of the original list
    current = newHead;
    while (current->next != NULL) {
        current = current->next;
    }

    // Connect the end of the original list to the old head
    current->next = head;
    head->prev = current;

    return newHead;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%c-->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int n, k;
    scanf("%d", &n);
    char vehicles[n];
    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        scanf(" %c", &vehicles[i]);
        struct Node* newNode = createNode(vehicles[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    scanf("%d", &k);

    printf("Current Parking Positions:\n");
    printList(head);

    struct Node* newHead = rotateLinkedList(head, k);

    printf("Updated Parking Positions:\n");
    printList(newHead);

    return 0;
}
//Sushant