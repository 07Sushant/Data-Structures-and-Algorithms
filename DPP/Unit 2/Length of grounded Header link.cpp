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




// if your quesion is slightly different  use THIS


// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* newNode(int data) {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->next = NULL;
//     return temp;
// }

// void insertEnd(struct Node** head, int data) {
//     struct Node* new_node = newNode(data);
//     if (*head == NULL) {
//         *head = new_node;
//         (*head)->next = *head; 
//     } else {
//         struct Node* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         temp->next = new_node;
//         new_node->next = *head; 
//     }
// }

// void pairwiseSwap(struct Node** head) {
//     if (*head == NULL || (*head)->next == *head) {
//         return;
//     }
    
//     struct Node* prev = *head;
//     struct Node* current = (*head)->next;
    
//     while (1) {
//         int temp = prev->data;
//         prev->data = current->data;
//         current->data = temp;
        
//         prev = current->next;
//         if (prev == *head || prev->next == *head) {
//             break;
//         }
//         current = prev->next;
//     }
// }

// void printList(struct Node* head) {
//     if (head == NULL)
//         return;
    
//     struct Node* temp = head;
//     do {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("\n");
// }

// int main() {
//     int n, data;
//     struct Node* head = NULL;

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &data);
//         insertEnd(&head, data);
//     }

//     printf("Original linked list: ");
//     printList(head);

//     pairwiseSwap(&head);

//     printf("Linked list after pairwise swapping: ");
//     printList(head);

//     return 0;
// }


// //Sushant
