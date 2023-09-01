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

int findLength(struct Node* header) {
    int length = 0;
    struct Node* current = header->next;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int main() {
    struct Node* header = createNode(-1);
    int n, data;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        newNode->next = header->next;
        header->next = newNode;
    }

    int length = findLength(header);
    printf("%d\n", length);

    return 0;
}

//Sushant