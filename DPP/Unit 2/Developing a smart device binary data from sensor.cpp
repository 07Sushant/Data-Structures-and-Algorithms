#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

int getDecimalValue(struct ListNode* head) {
    int decimalValue = 0;

    while (head != NULL) {
        decimalValue = (decimalValue << 1) | head->val;
        head = head->next;
    }

    return decimalValue;
}

int main() {
    struct ListNode* head = NULL;
    struct ListNode* current = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    int decimalValue = getDecimalValue(head);

    printf("Linked List: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\nDecimal Value: %d\n", decimalValue);

    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }

    return 0;
}
//Sushant