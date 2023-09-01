#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
}

struct Node* mergeAlternately(struct Node* list1, struct Node* list2) {
    struct Node* merged = NULL;
    struct Node* current1 = list1;
    struct Node* current2 = list2;
    struct Node* merged_tail = NULL;
    
    while (current1 != NULL || current2 != NULL) {
        if (current1 != NULL) {
            append(&merged, current1->data);
            current1 = current1->next;
        }
        if (current2 != NULL) {
            append(&merged, current2->data);
            current2 = current2->next;
        }
    }
    
    return merged;
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
    int n, m;
    scanf("%d", &n);
    
    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        append(&list1, data);
    }
    
    scanf("%d", &m);
    
    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        append(&list2, data);
    }
    
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    
    struct Node* mergedList = mergeAlternately(list1, list2);
    
    printf("Merged List: ");
    printList(mergedList);
    
    return 0;
}


//sushant





