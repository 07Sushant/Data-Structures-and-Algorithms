#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node* header, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = header->next;
    header->next = newNode;
}

void displayList(struct Node* header) {
    struct Node* current = header->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* header = createNode(-1);
    int n, data;

    scanf("%d", &n);
    while (n != -1) {
        insertAtBeginning(header, n);
        scanf("%d", &n);
    }


    displayList(header);

    return 0;
}






//Sushant