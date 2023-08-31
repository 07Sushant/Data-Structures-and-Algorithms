#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head;

void createlist(int n);
void traverselist();
int searchelement(int item);

void createlist(int n) {
    struct node *newnode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Unable to allocate memory");
        exit(1);
    }

    printf("Enter the data of node: ");

    
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Unable to allocate memory");
            break;
        }
        printf("Enter the data of the node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
}

void traverselist() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int searchelement(int item) {
    struct node *temp = head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == item) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main() {
    int n, item, index;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    
    printf("Enter the item to search: ");
    scanf("%d", &item);
    
    index = searchelement(item);
    if (index != -1) {
        printf("Item found at index %d\n", index);
    } else {
        printf("Item not found\n");
    }

    printf("Linked list contents:\n");
    traverselist();

    return 0;
}
