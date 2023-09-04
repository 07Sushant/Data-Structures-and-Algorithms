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
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    return head;
}

struct Node* deleteCommonNodes(struct Node* list1, struct Node* list2) {
    if (list1 == NULL || list2 == NULL) {
        return list1;
    }
    
    struct Node* current1 = list1;
    struct Node* prev1 = NULL;
    
    while (current1 != NULL) {
        int value1 = current1->data;
        struct Node* current2 = list2;
        int found = 0;
        
        while (current2 != NULL) {
            int value2 = current2->data;
            if (value1 == value2) {
                found = 1;
                break;
            }
            current2 = current2->next;
        }
        
        if (found) {
            if (prev1 == NULL) {
                list1 = current1->next;
                free(current1);
                current1 = list1;
            } else {
                prev1->next = current1->next;
                free(current1);
                current1 = prev1->next;
            }
        } else {
            prev1 = current1;
            current1 = current1->next;
        }
    }
    
    return list1;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }
    
    scanf("%d", &m);
    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }
    
    printf("First Linked List before deletion: ");
    printList(list1);
    
    list1 = deleteCommonNodes(list1, list2);
    
    printf("\nFirst Linked List after deletion: ");
    if (list1 == NULL) {
        printf("\nAll elements in the first linked list are the same.\n");
    } else {
        printList(list1);
        printf("\n");
    }
    
    return 0;
}

