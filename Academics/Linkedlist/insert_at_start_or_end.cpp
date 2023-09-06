#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head;

void createlist(int n);
void traverselist();
void insertatstart(int data);
void insertatend(int data); 

void createlist(int n) {
    struct node *newnode, *temp;
    int data, i;

    head = NULL;

    for (i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed");
            exit(1);
        }
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }
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

void insertatstart(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertatend(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

int main() {
    int n, insertData, choice;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createlist(n);

    printf("Linked list created:\n");
    traverselist();

    printf("Enter 0 to insert at the beginning or 1 to insert at the end: ");
    scanf("%d", &choice);

    
    if (choice == 0) {
        printf("Enter data to insert at the beginning: ");
        scanf("%d", &insertData);
        insertatstart(insertData);
    } else if (choice == 1) {
        printf("Enter data to insert at the end: ");
        scanf("%d", &insertData);
        insertatend(insertData);
    } else {
        printf("Invalid choice\n");
    }

    printf("Updated Linked list :\n");
    traverselist();

    return 0;
}



