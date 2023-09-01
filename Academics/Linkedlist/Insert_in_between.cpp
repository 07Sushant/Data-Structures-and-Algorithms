#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createlist(int n);
void traverselist();
void insertbetween(int data, int position);

void createlist(int n) {
    struct node *newnode, *temp;
    int data, i;

    head = NULL;

    for (i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("memory nahi allocate ho payi");
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

void insertbetween(int data, int position) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("memory nahi allocate ho payi");
        exit(1);
    }
    newnode->data = data;

    if (position == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        struct node *temp = head;
        int i;

        for (i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
            free(newnode);
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main() {
    int n, insertData, position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createlist(n);

    printf("Linked list contents:\n");
    traverselist();

    printf("Enter data to insert: ");
    scanf("%d", &insertData);
    printf("Enter the position to insert the data: ");
    scanf("%d", &position);
    
    insertbetween(insertData, position);

    printf("updated Linked list: \n");
    traverselist();

    return 0;
}
